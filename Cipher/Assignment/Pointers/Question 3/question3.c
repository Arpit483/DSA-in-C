/*
   write a Program to read  array elements and print with addresses.

*/

#include <stdio.h>

int main()
{
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};

    int *p = arr;
    
    int i = 0;

    printf ("%s" , "Address \t\t Element");
    printf("\n");
    while (i <  sizeof(arr) / sizeof (arr[0]))
    {
        
        printf("%p \t  %d \n" , (void *)p  ,  *p );    // a pointer is shown by %p and we typecast it to void as a pointer is not of any datatype
        i++;
        p++;

    }
    
	
	return 0;
}