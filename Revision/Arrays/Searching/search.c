#include <stdio.h>
#include <stdlib.h>

int LinearSeach(int arr[] , int s, int data )
{
    for (int i = 0; i < s;i++)
    {
        if(arr[i] == data)
        {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int arr[] , int s , int data)
{
    int low = 0;
    int high = s-1;

    while(low <= high)
    {
        int mid = (low) + (high - low) / 2;

        if(arr[mid] == data)
        {
            return mid;
        }
        else if(arr[mid] < data)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}


int main()
{
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("[");
    for (int i = 0; i < size;i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("]\n");

    printf("%d \n",LinearSeach(arr, size, 4));
    printf("%d \n",BinarySearch(arr, size, 7));
}