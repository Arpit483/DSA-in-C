/*

   Write a C program to read a one dimensional array, print sum of all elements along with inputted array elements using Dynamic Memory Allocation.
   - allocate memory for one dimensional array and print the array elements along with sum of all elements. 
   - Memory will be allocated in this program using malloc() and released using free().

*/
#include<stdlib.h>
#include<stdio.h>

int main()
{
    int *arr , n;
    int sum = 0;
    printf("Enter number in Elements");
    scanf("%d" , &n);    
    arr = (int *)malloc(n * sizeof(int )); 

    printf("Enter the Elements: ");
    for (int i = 0 ; i < n ; i++)
    {
        scanf("%d" , &arr[i]);
    }

    for (int i = 0 ; i < n ; i++)
    {
        printf("[%d] \t" , arr[i]);

        sum = sum + i;
    }

    printf("\nSum is : %d" , sum);
	return 0;

}