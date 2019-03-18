#include <stdio.h>
#define SIZE 10

int main(void)
{
    int arr[SIZE] = {26, 34543, 17, 31, 13, 543, 456, 1, 0, 2};
    int idx, target, tmp, swapped;

    printf("Bubble Sort\n");
    printf("Before Sorting: \n");
    for(idx=0; idx<SIZE; idx++)
    {
        printf("%d\t", arr[idx]);
    }
    printf("\n");

    // Optimised version
    for(idx=0; idx<SIZE-1; idx++)
    {
        swapped = 0;
        for(target=0; target<(SIZE-1)-idx; target++)
        {
            if(arr[target] > arr[target+1])
            {
                tmp = arr[target];
                arr[target] = arr[target+1];
                arr[target+1] = tmp;
                swapped = 1;
            }
        }
        if(!swapped)
            break;
    }

    // The Bubble Sort
/*    for(idx=0; idx<SIZE-1; idx++)
    {
        for(target=0; target<(SIZE-1)-idx; target++)
        {
            if(arr[target] > arr[target+1])
            {
                tmp = arr[target];
                arr[target] = arr[target+1];
                arr[target+1] = tmp;
            }
        }
    }*/

    printf("After Sorting: \n");
    for(idx=0; idx<SIZE; idx++)
    {
        printf("%d\t", arr[idx]);
    }
    printf("\n");


    return(0);
}
