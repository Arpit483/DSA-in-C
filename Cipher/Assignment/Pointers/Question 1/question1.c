/* 
   Write a Program to swap elements between two array using pointers.

*/
#include <stdio.h>

int main()
{
	int *p1;                                          // initialize the pointers
    int *p2;
    int i = 0 ;

    int arr[5] = {1,2,3,4,5};                        // array    
    int arr2[5] = {6,7,8,9,0};
    //printf("%d" , arr);
    p1 = arr;                                       // values of address assigned to pointers
    p2 = arr2;
    // printf("%d" , *p1);

    while(i < 6){

        int temp = *p1;                           // pointer swap elements
        *p1 = *p2;
        *p2 = temp;

        p1++;                                    // add pointer values
        p2++;
        i++;
    }

    printf("%s " , " Array 1 : ");
    for (int j = 0; j < sizeof(arr)/4 ; j++)
    {
        
        printf(" %d  ", arr[j]);
    }
    
    printf("\n");
    printf("%s " , " Array 2 : ");
    for (int j = 0; j < sizeof(arr)/4 ; j++)
    {
        printf(" %d  ", arr2[j]);
    }
	
	return 0;
}  