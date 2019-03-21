#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "OAHashTable.h"

#define SIZE 11



int main()
{
    struct OAHashTable *hashTable = initOAHashTable(SIZE);
    // Intialise random number generator
    // seeding with the system time
    srand(time(NULL));
    // Initialise with given keys and random data
    insert(hashTable,6, rand());
    insert(hashTable,2, rand());
    insert(hashTable,13, rand());
    insert(hashTable,5, rand());
    insert(hashTable,17, rand());
    insert(hashTable,39, rand());
    insert(hashTable,1, rand());
    insert(hashTable,12, rand());
    printKeys(hashTable);
	search(hashTable, 6);
	search(hashTable, 39);
	search(hashTable, 100);
    printPerformance(hashTable);
    destroy(hashTable);
    return 0;
}
