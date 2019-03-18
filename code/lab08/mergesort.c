#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void _mergesort(int*, int, int);
void merge(int*, int, int, int);

int main(void)
{
    int data[SIZE] = {9, 8, 79, 63, 7, 45, 17, 22, 10, 3};
    int i;

    printf("Mergesort\n");
    printf("Before sorting...\n");

    for(i=0; i<SIZE; i++)
    {
        printf("%d\t", data[i]);
    }
    printf("\n");

    _mergesort(data, 0, SIZE-1);

    printf("After sorting...\n");

    for(i=0; i<SIZE; i++)
    {
        printf("%d\t", data[i]);
    }
    printf("\n");

    return(0);
}

void _mergesort(int data[], int left, int right)
{
    if (left < right) 
    { 
        int middle = left+(right-left)/2; 

        _mergesort(data, left, middle); 
        _mergesort(data, middle+1, right); 
  
        merge(data, left, middle, right); 
    }
}

void merge(int data[], int left, int middle, int right)
{
    int left_idx, right_idx, merged_idx; 
    int left_size = middle - left + 1; 
    int right_size =  right - middle; 

    int *tmp_left = (int*) calloc(left_size, sizeof(int));
    int *tmp_right = (int*) calloc(right_size, sizeof(int));

    for (left_idx = 0; left_idx < left_size; left_idx++) 
        tmp_left[left_idx] = data[left + left_idx]; 
    for (right_idx = 0; right_idx < right_size; right_idx++) 
        tmp_right[right_idx] = data[middle + 1+ right_idx]; 
  
    left_idx = 0;  
    right_idx= 0;  
    merged_idx = left;  
    while (left_idx < left_size && right_idx < right_size) 
    { 
        if (tmp_left[left_idx] <= tmp_right[right_idx]) 
        { 
            data[merged_idx] = tmp_left[left_idx]; 
            left_idx++; 
        } 
        else
        { 
            data[merged_idx] = tmp_right[right_idx]; 
            right_idx++; 
        } 
        merged_idx++; 
    } 
  
    while (left_idx < left_size) 
    { 
        data[merged_idx] = tmp_left[left_idx]; 
        left_idx++; 
        merged_idx++; 
    } 
  
    while (right_idx < right_size) 
    { 
        data[merged_idx] = tmp_right[right_idx]; 
        right_idx++; 
        merged_idx++; 
    }
    free(tmp_left);
    free(tmp_right);
}

