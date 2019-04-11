#include <stdio.h>
#include <stdlib.h>
#include "OAHashTable.h"


int hashCode(int key, int size)
{
    return key % size;
}

int insert(struct OAHashTable *hashTable, int key, int data)
{
    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
    item -> data = data;
    item -> key = key;

    int hashIndex = hashCode(key, hashTable->size);
    int numTries = 0;
    if(hashTable->buckets[hashIndex] != NULL)
    {
        hashTable->numCollisions++;
    }
    while(hashTable->buckets[hashIndex] != NULL && numTries < hashTable->size)
    {
        numTries++;
        ++hashIndex;
        hashIndex %= hashTable->size;
    }
    if(numTries == hashTable->size)
    {
        return -1;
    }
    else
    {
        hashTable->buckets[hashIndex] = item;
    }
    hashTable->numInsertions++;
    return 0;
}

void destroy(struct OAHashTable *hashTable)
{
	for(int i=0; i<hashTable->size; i++)
	{
		if(hashTable->buckets[i] != NULL)
		{
			free(hashTable->buckets[i]);
		}
 	 }
 	 free(hashTable);
 }
 
 struct OAHashTable* initOAHashTable(int size)
 {
 	
 	struct OAHashTable *hashTable = (struct OAHashTable*)malloc(sizeof(struct OAHashTable));
     // Use calloc to initialise the buckets to NULL, so that we can test
     // for empty buckets.
 	hashTable->buckets = (struct DataItem**)calloc(size, sizeof(struct DataItem*));
 	hashTable->size = size;
    hashTable->numCollisions = 0;
    hashTable->numProbes = 0;
    hashTable->numInsertions = 0;
    hashTable->numSearches = 0;
 	return hashTable;
 }

void printKeys(struct OAHashTable* hashTable)
{
    printf("[");
    for(int i=0; i<hashTable->size -1; i++)
    {
        if(hashTable->buckets[i] != NULL)
        {
            printf("%d, ", hashTable->buckets[i]->key);
        }
        else
        {
            printf("-, ");
        }
    }
    // Print the last element without a comma and space, just to be neat
    
    if(hashTable->buckets[hashTable->size-1] != NULL)
    {
        printf("%d", hashTable->buckets[hashTable->size-1]->key);
    }
    else
    {
        printf("-");
    }
    printf("]\n");
    
}

void printPerformance(struct OAHashTable *hashTable)
{
    printf("Number of insertions: %d\n", hashTable->numInsertions);
    printf("Number of collisions: %d\n", hashTable->numCollisions);
    printf("Load factor: %.3f\n", (double)hashTable->numInsertions/hashTable->size);
    printf("%% of insertions that collided: %.1f\n", (double)hashTable->numCollisions/hashTable->numInsertions*100);
    printf("Average number of probes per search: %f\n", (double)hashTable->numProbes/hashTable->numSearches);
}

struct DataItem* search(struct OAHashTable* hashTable, int key)
{
    hashTable->numSearches++;
    int hashIndex = hashCode(key,hashTable->size);
    int numTries = 0;
    while(hashTable->buckets[hashIndex] != NULL && numTries < hashTable->size)
    {
        numTries++;
        hashTable->numProbes++;
        if(hashTable->buckets[hashIndex]->key == key)
            return hashTable->buckets[hashIndex];
        
        ++hashIndex;
        hashIndex %= hashTable->size;
    }
    
    return NULL;
}
