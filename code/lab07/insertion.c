#include <stdio.h>
#define SIZE 10

int main(void)
{
    int arr[SIZE] = {26, 34543, 17, 31, 13, 543, 456, 1, 0, 2};
    int idx, cmp, shift, tmp;

    printf("Insertion Sort\n");
    printf("Before Sorting: \n");
    for(idx=0; idx<SIZE; idx++)
    {
        printf("%d\t", arr[idx]);
    }
    printf("\n");

    // The Insertion Sort
    for(cmp=1; cmp<SIZE; cmp++)
    {
        for(idx=0; idx<cmp; idx++)
        {
            if(arr[idx] > arr[cmp])
            {
                tmp = arr[idx];
                arr[idx] = arr[cmp];

                for(shift = cmp; shift > idx; shift--)
                    arr[shift] = arr[shift-1];
                arr[shift+1] = tmp;
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
