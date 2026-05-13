#include <stdio.h>
//#include <bits/stdc++.h> To be include in C++

void insertion_sort(int nums[] , int numsSize)
{
    
}


void selection_sort(int nums[] , int numsSize)
{
    for (int i = 0; i < numsSize - 1 ; i++)
    {
        int min = i;
        for (int j = i+1; j < numsSize ; j++)
        {
            if(nums[j] < nums[i] )
            {
                min = j;
            }
        }
        int temp = nums[min];
        nums[min] = nums[i];
        nums[i] = temp;
    }
}

int main()
{
    int nums[] = {1, 4, 7, 8, 9, 6, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }
 
    printf("\n");
 
    selection_sort(nums, numsSize);
 
    printf("\n");
 
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }
}