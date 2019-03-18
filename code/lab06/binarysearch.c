#include <stdio.h>

#define SIZE 10
int main(void)
{
    int arr[SIZE] = {1, 2, 3, 9, 11, 13, 17, 25, 57, 90};
    int mid = 0, lower = 0, upper = SIZE-1, key = 0, found = 0;

    printf("Enter number to search for: ");
    scanf("%d", &key);

    for(mid=(lower+upper)/2; lower <= upper; mid=(lower+upper)/2)
    {
        if(arr[mid] == key)
        {
            printf("Your number is at position %d of our array\n", mid);
            found = 1;
            break;
        }
        if(arr[mid] > key)
            upper = mid-1;
        else
            lower = mid+1;
    }
    if(!found)
        printf("%d is not in the array\n", key);
        return 0;
    return(0);
}

