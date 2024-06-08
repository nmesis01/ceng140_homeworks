#include <stdio.h>
#include <stdlib.h>
int transform_name(const char *name)
{
    int C = 0;
    int i = 0;
    char c;
    while ((c = *(name+i)) != '\0')
    {
        C += (i+1)*(i+1)*(int)c;
        i++;
    }
    return C;
}
int** initialize_storage(int IA_size, int DA_size, int** DA_sizes)
{
    int i;
    int **storage = (int **)malloc(IA_size*sizeof(int *));
    *DA_sizes = (int *)malloc(IA_size*sizeof(int));
    for (i = 0; i < IA_size; i++)
    {
        *(storage+i)= (int *)calloc(DA_size,sizeof(int));
    }
    for (i = 0; i < IA_size; i++)
    {
        *(*DA_sizes+i) = DA_size;
    }
    return storage;
}
void print_storage(int** storage, int IA_size, int* DA_sizes)
{
    int i;
    int j;
    for (i = 0; i < IA_size; i++)
    {
        printf("%d ->",i);
        for (j = 0; j < *(DA_sizes+i); j++)
        {
            printf(" %d",storage[i][j]);
        }
        printf("\n");
    }
}
void insert(int** storage, int IA_size, const char* name, int* DA_sizes)
{
    int array_index;
    int C;
    int last_index = 0;
    C = transform_name(name);
    array_index = C % IA_size;
    while (last_index < *(DA_sizes+array_index))
    {
        if (storage[array_index][last_index] == 0)
        {
            break;
        }
        last_index++;
    }
    if (last_index >= *(DA_sizes+array_index))
    {
        int init0;
        *(DA_sizes+array_index) *= 2;
        storage[array_index] = (int *)realloc(storage[array_index],(*(DA_sizes+array_index))*sizeof(int));
        for (init0 = last_index; init0 < *(DA_sizes+array_index); init0++)
        {
            storage[array_index][init0] = 0;
        }
    }
    storage[array_index][last_index] = C;
}
void insert2(int** storage, int IA_size, int name_code, int* DA_sizes)
{
    int array_index;
    int last_index = 0;
    array_index = name_code % IA_size;
    while (last_index<*(DA_sizes+array_index))
    {
        if (storage[array_index][last_index] == 0)
        {
            break;
        }
        last_index++;
    }
    if (last_index == *(DA_sizes+array_index))
    {
        int init0;
        *(DA_sizes+array_index) *= 2;
        storage[array_index] = (int *)realloc(storage[array_index],(*(DA_sizes+array_index))*sizeof(int));
        for (init0 = last_index; init0 < *(DA_sizes+array_index); init0++)
        {
            storage[array_index][init0] = 0;
        }
    }
    storage[array_index][last_index] = name_code;
}
void fill_new_storage(int** storage, int IA_size, int** new_storage, int *DA_sizes, int** new_DA_sizes)
{
    int i;
    int j;
    for (i = 0; i < IA_size; i++)
    {
        for (j = 0; j < *(DA_sizes+i) && storage[i][j]; j++)
        {
                insert2(new_storage,IA_size*2,storage[i][j],*new_DA_sizes);
        }
    }
}
void resize_IA(int*** storage, int* IA_size, int DA_size, int** DA_sizes)
{
    int total_size = 0;
    int i;
    for (i = 0; i < *IA_size; i++)
    {
        total_size += *(*DA_sizes+i);
    }
    if (total_size>=((*IA_size)*DA_size)*1.5)
    {
        int **newstorage;
        int *new_DA_sizes;
        newstorage = initialize_storage((*IA_size)*2,DA_size,&new_DA_sizes);
        fill_new_storage(*storage,*IA_size,newstorage,*DA_sizes,&new_DA_sizes);
        for (i = 0; i < *IA_size; i++)
        {
            free((*storage)[i]);
        }
        free(*storage);
        free(*DA_sizes);
        *IA_size = (*IA_size)*2;
        *DA_sizes = new_DA_sizes;
        *storage = newstorage;
    }
}