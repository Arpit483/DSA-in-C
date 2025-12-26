// Write a program to reverse a array without using any additional array the reversal must happen in the same array using elemnet swapping
// 1 2 3 4 5 
// 5 4 3 2 1
// Time Taken -> 15 min
#include <stdio.h>

void ar(int arr[],int s)
{
    int p = 0;   
    int n;
    int q = s - 1;

    while(p < (s-1)/2 && q >= (s-1)/2)
    {
        n = arr[p];
        arr[p] = arr[q];
        arr[q] = n;
        
        p = p + 1;
        q = q - 1;
    }
    
}

int main()
{
    int array[5] = {1,2,3,4,5};
    
    for(int i = 0 ; i < 5 ; i++)
    {
        printf("%d \n" , array[i] );
    }


    int size = sizeof(array) / sizeof(array[0]);
    ar(array , size) ;

    for(int i = 0 ; i < 5 ; i++)
    {
        printf("%d \n" , array[i] );
    }


    printf("\nTime Taken 20 min");

}