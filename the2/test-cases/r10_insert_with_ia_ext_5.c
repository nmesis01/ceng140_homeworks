#include <stdio.h>
#include "the2.h"

int main(){

char names[][15] = {
"Jermaine", "Kierra", "Sandra", "Ainsley", "Samantha", "Jace", "Everett", "Sariyah", "Lacey", "Sara", "Yahir", "Jordi", "Aiden", "Viola", "Diego", "Denise", "Hope", "Tristan", "Elsie", "Beatrice", "Lance", "Reed", "Jamie", "Mara", "Irvin", "Lucille", "Cheyenne", "Lindsay", "Sterling", "Phyllis", "Peggy", "Mary", "Myles", "Isabella", "Lorelei", "Russell", "Kiley", "Nolan", "Davina", "Rodrigo", "Mirabella", "Beryl", "Jasmine", "Tegan", "Jarrett", "Jacqueline", "Lenny", "Brenda", "Leland", "Steve", 
"Zackary", "Sawyer", "Jakob", "Lachlan", "Nellie", "Octavia", "Jeanette", "Loren", "Kendra", "Adelyn", "Jaylen", "Charlotte", "Aubrey", "June", "Zander", "Judith", "Braxton", "Ibrahim", "Bryce", "Ira", "Bowen", "Andrew", "Marcus", "Rex", "Selena", "Jodi", "Makenzie", "Eva", "Matthew", "Benito", "Troy", "Tyler", "Anastasia", "Jared", "Nico", "Felix", "Brynn", "Serena", "Blair", "Chad", "Nia", "Kyla", "Mohammed", "Natalia", "Kirk", "Lea", "Wyatt", "Jim", "Mavis", "Erin", 
"Mabel", "Mckayla", "Gary", "Wanda", "Rosalyn", "Vanessa", "Rose", "Sophie", "Sloane", "Ryder", "Rosemary", "Dawn", "Helena", "Heidi", "Madelyn", "Irving", "Leone", "Dominique", "Pearl", "Layla", "Meredith", "Ethan", "Samir", "Myla", "Sadie", "Jordyn", "Charley", "Nina", "Joann", "Nayeli", "Kya", "Aaliyah", "Virgil", "Jaden", "Eddie", "Makayla", "Gail", "Wiley", "Cathy", "Libby", "Alena", "Lucy", "Edward", "Giuliana", "Brittany", "Hazel", "Inez", "Asa", "Aisha", "Lora", 
"Dane", "Kristine", "Velma", "Elijah", "Cheryl", "Anna", "Beau", "Colby", "Laura", "Emily", "Vince", "Marley", "Dillon", "Jose", "Grant", "Valerie", "Waylon", "Oceana", "Tavion", "Devon", "Annalise", "Casey", "Zuriel", "Vera", "Noah", "Lee", "April", "Rosie", "Toni", "Lulu", "Cherish", "Sarah", "Zora", "Trent", "Tyrone", "Cristian", "Kendall", "Uriel", "Santiago", "Tori", "Rachel", "Darcy", "Devin", "Salvador", "Gannon", "Larry", "Raiden", "Liz", "James", "Sally"
};

    int i;              /* iterators */
    int IA_size = 9;    /* initial IndexArray size */
    int DA_size = 6;    /* default data array size */
    int** storage;      /* storage variable */
    int* DA_sizes;      /* data array sizes */

    storage = initialize_storage(IA_size, DA_size, &DA_sizes);  /* initialize the storage */
    
    for (i = 0; i < 200; i++)  /* for each person name in the list */
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
