#include<stdio.h>
#include<stdlib.h>

int BinarySearch(int arr[], int key , int s)
{
    int low = 0;
    int high = s - 1;
    
    while(low < high)
    {
        int mid = (low) + (high - low) / 2;
    

        if(arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid] >  key)
        {
            high = mid - 1;
        }
        else 
        {
            low = mid + 1;
        }

    }

    return -1;

}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = BinarySearch(arr, 4, 9);
    printf("%d", n);
}