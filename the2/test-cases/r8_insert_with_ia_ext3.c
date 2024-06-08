#include <stdio.h>
#include "the2.h"

int main(){
    char names[][20] = {"Bernd", "Aaron", "Ben", "Kieran", "Sead", 
                        "Emile", "Martin", "Alexandre", "Pierre", "Gabriel",
                        "Bukayo", "Cedric", "Mohamed", "Sead", "Calum",
                        "Thomas", "Granit", "Nuno"};  /* names to be added into storage */
    int i;              /* iterators */
    int IA_size = 3;    /* initial IndexArray size */
    int DA_size = 3;    /* default data array size */
    int** storage;      /* storage variable */
    int* DA_sizes;      /* data array sizes */

    storage = initialize_storage(IA_size, DA_size, &DA_sizes);  /* initialize the storage */
    
    for (i = 0; i < 18; i++)  /* for each person name in the list */
    {
        insert(storage, IA_size, names[i], DA_sizes);       /* insert a person name into storage */
        print_storage(storage, IA_size, DA_sizes);          /* print storage */

        /* Check if need IndexArray extension. */
        /* Sent references of storage, current IndexArray size and data array sizes */
        /* to not lost their references while updating them in the implemented functions */
        resize_IA(&storage, &IA_size, DA_size, &DA_sizes);  
        printf("-----------------------------------------\n");
    }

    free(DA_sizes);
    for(i = 0; i< IA_size; i++)
    {
        free(storage[i]);
    }
    free(storage);

	return 0;
}
