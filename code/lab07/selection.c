#include <stdio.h>
#define SIZE 10

int main(void)
{
    int arr[SIZE] = {26, 34543, 17, 31, 13, 543, 456, 1, 0, 2};
    int idx, target, tmp;

    printf("Selection Sort\n");
    printf("Before Sorting: \n");
    for(idx=0; idx<SIZE; idx++)
    {
        printf("%d\t", arr[idx]);
    }
    printf("\n");

    // The Selection Sort
    for(idx=0; idx<SIZE-1; idx++)
    {
        for(target=idx+1; target<SIZE; target++)
        {
            if(arr[idx] > arr[target])
            {
                tmp = arr[idx];
                arr[idx] = arr[target];
                arr[target] = tmp;
            }
        }
    }

    printf("After Sorting: \n");
    for(idx=0; idx<SIZE; idx++)
    {
        printf("%d\t", arr[idx]);
    }
    printf("\n");


    return(0);
}
