#include <stdio.h>
#include "the2.h"

int main(){

char names[][15] = {
"Esin", "Ceyda", "Bedir", "Harun", "Bulent", "Gamze", "Arda", "Orhan", "Leyla", "Bahri", "Ahmet", "Serkan", "Baha", "Nadir", "Ozan", "Elif", "Gulay", "Emine", "Kadir", "Yesim", "Anil", "Gulcin", "Bayram", "Gulizar", "Gizem", "Ugur", "Hava", "Amina", "Ramazan", "Hasan", "Ayman", "Can", "Gurkan", "Selma", "Gulden", "Asim", "Gokhan", "Adem", "Rabia", "Mahmut", "Tugba", "Esma", "Deniz", "Ayse", "Arif", "Atilla", "Sadi", "Elmas", "Baran", "Sevgi", "Fatih", "Erdem", "Furkan", "Abbas", "Selim", "Gul", "Dilhan", "Evren", "Eren", "Ece", "Nihan", "Yavuz", "Sahra", "Asil", "Abdullah", "Dilek", "Berk", "Burcu", "Cemre", "Hamza", "Hakan", "Busra", "Ufuk", "Davut", "Banu", "Hale", "Aylin", "Emrah", "Gulsah", "Zehra", 
};


    int i;              /* iterators */
    int IA_size = 7;    /* initial IndexArray size */
    int DA_size = 4;    /* default data array size */
    int** storage;      /* storage variable */
    int* DA_sizes;      /* data array sizes */

    storage = initialize_storage(IA_size, DA_size, &DA_sizes);  /* initialize the storage */
    
    for (i = 0; i < 80; i++)  /* for each person name in the list */
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