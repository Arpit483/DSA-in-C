//Write a function to calculate the sum of all elements of an array

#include<stdio.h>

int sum_all(int arr[] , int n)
{
    int sum = 0;
    for(int i = 0 ; i  < n ; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
	int arr[5] = {1,2,3,4,5};
    int s = sizeof(arr) / sizeof(arr[0]);

    printf("Sum is: %d" , sum_all(arr , s));
	return 0;
}


