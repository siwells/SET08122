#include <stdio.h>

#define MAX 5

void insert(int*, int pos, int num);
void delete(int *, int pos);
void reverse(int*);
void display(int*);
void search(int*, int num);

int main(void)
{
    int array[MAX];

    insert(array, 1, 11);
    insert(array, 2, 12);
    insert(array, 3, 13);
    insert(array, 4, 14);
    insert(array, 5, 15);

    printf("Array Contents: \n");
    display(array);

    delete(array, 5);
    delete(array, 2);

    printf("After Deletion: \n");
    display(array);

    insert(array, 2, 222);
    insert(array, 5, 555);

    printf("Array Insertion: \n");
    display(array);

    reverse(array);

    printf("After Reversal: \n");
    display(array);

    search(array, 222);
    search(array, 666);

    return 0;
}


void insert(int* array, int pos, int num)
{
    int idx;

    for(idx = MAX-1; idx>= pos; idx--)
    {
        array[idx] = array[idx-1];
    }
    array[idx] = num;
}

void delete(int * array, int pos)
{
    int idx;
    for(idx = pos; idx<MAX; idx++)
    {
        array[idx-1] = array[idx];
    }
    array[idx-1] = 0;
} 

void reverse(int* array)
{
    int idx;
    for(idx=0; idx<MAX/2; idx++)
    {
        int temp = array[idx];
        array[idx] = array[MAX-1-idx];
        array[MAX-1-idx] = temp;
    }
}

void display(int* array)
{
    int idx;
    for(idx=0; idx < MAX; idx++)
    {
        printf("%d\t", idx);
    }
    printf("\n");

    for(idx=0; idx < MAX; idx++)
    {
        printf("%d\t", array[idx]);
    }
    printf("\n");
}

void search(int* array, int num)
{
    int idx;
    for(idx=0; idx<MAX; idx++)
    {
        if(array[idx] == num)
        {
            printf("%d found in position %d\n", num, idx+1);
            return;
        }
    }
    if(idx == MAX)
        printf("%d not found in array\n", num);
}

