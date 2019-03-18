#include <stdio.h>
#include <stdlib.h>

struct DataItem* delete(struct DataItem*);
void display(void);
void insert(int, int);
int hashCode(int);
struct DataItem* search(int);

#define SIZE 10
struct DataItem 
{
    int data;
    int key;
};

struct DataItem* hashArray[SIZE];
struct DataItem* tempItem;
struct DataItem* item;

int main(void)
{
    tempItem = (struct DataItem*) malloc(sizeof(struct DataItem));
    tempItem -> data  =-1;
    tempItem -> key = -1;

    display();
    
    insert(1, 20);
    insert(2, 70);
    insert(42, 80);
    insert(4, 25);
    insert(12, 44);
    insert(14, 32);
    insert(17, 11);
    insert(37, 97);
    insert(10, 0);
    insert(9,999);
    insert(22,94399);
    insert(321,9999);

    display();

    item = search(37);
    if(item != NULL)
    {
        printf("Element found: %d\n", item->data);
    } 
    else 
    {
        printf("Element not found\n");
    }
    
    item = delete(item);
    if(item != NULL)
    {
        printf("Element found: %d\n", item->data);
    } 
    else 
    {
        printf("Element not found\n");
    }
    display();

    item = search(37);
    if(item != NULL)
    {
        printf("Element found: %d\n", item->data);
    } 
    else 
    {
        printf("Element not found\n");
    }
    display();
    
    return(0);
}

struct DataItem* delete(struct DataItem* item)
{
    int key = item -> key;
    int hashIndex = hashCode(key);

    while(hashArray[hashIndex] != NULL)
    {
        if(hashArray[hashIndex] -> key == key)
        {
            struct DataItem *temp = hashArray[hashIndex];
            hashArray[hashIndex] = NULL;
            return temp;
        }
        ++hashIndex;
        hashIndex %= SIZE;
    }
    return NULL;
}

void display(void)
{
    int i;
    for(i=0; i<SIZE; i++)
    {
        if(hashArray[i] != NULL)
            printf(" (%d,%d)", hashArray[i] -> key, hashArray[i] -> data);
        else
            printf(" ~,~ ");
    }
    printf("\n");
}

void insert(int key, int data)
{
    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
    item -> data = data;
    item -> key = key;

    int hashIndex = hashCode(key);
    while(hashArray[hashIndex] != NULL && hashArray[hashIndex] -> key != -1)
    {
        ++hashIndex;
        hashIndex %= SIZE;
    }
    hashArray[hashIndex] = item;
}

int hashCode(int key)
{
    return key % SIZE;
}

struct DataItem* search(int key)
{
    int hashIndex = hashCode(key);
    while(hashArray[hashIndex] != NULL)
    {
        if(hashArray[hashIndex] -> key == key)
            return hashArray[hashIndex];

        ++hashIndex;
        hashIndex %= SIZE;
    }

    return NULL;
}
