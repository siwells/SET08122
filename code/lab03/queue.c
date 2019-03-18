#include <stdio.h>

#define MAX 10

void enqueue(int *, int, int *, int *);
int dequeue(int *, int *, int *);
int empty(int *);

int main()
{
    int arr[MAX];
    int front = -1, rear = -1;

    enqueue(arr, 23, &front, &rear);
    enqueue(arr, 9, &front, &rear);
    enqueue(arr, 11, &front, &rear);
    enqueue(arr, -10, &front, &rear);
    enqueue(arr, 25, &front, &rear);
    enqueue(arr, 16, &front, &rear);
    enqueue(arr, 17, &front, &rear);
    enqueue(arr, 22, &front, &rear);
    enqueue(arr, 19, &front, &rear);
    enqueue(arr, 30, &front, &rear);
    enqueue(arr, 32, &front, &rear);

    int i;
    for(int idx=0; idx<MAX+1; idx++)
    {
        if(!empty(&front))
        {
            i = dequeue(arr, &front, &rear);
            printf("Received Dequeued item: %d\n", i);
        }
    }

    return 0;
}

void enqueue(int *arr, int item, int *pfront, int *prear)
{
    if(*prear == MAX-1)
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        printf("Enqueuing: %d\n", item);
        (*prear)++;
        arr[*prear] = item;

        if(*pfront == -1)
            *pfront = 0;
    }
}

int empty(int *pfront)
{
    if(*pfront == -1)
    {
        printf("Queue is empty\n");
        return 1;
    }
    else
        return 0;
}

int dequeue(int *arr, int *pfront, int *prear)
{
    int data = arr[*pfront];
    printf("Dequeueing: %d\n", data);
    
    arr[*pfront] = 0;
    if(*pfront == *prear)
        *pfront = *prear = -1;
    else
        (*pfront)++;
        
    return data;
}
