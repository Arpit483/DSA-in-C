/*

   Write a function which reads pointers of 2 different array as arguments, 
   return the pointer of array which elements are sum of  two array element. 
*/

#include <stdio.h>

void addArray(int *p , int *q);

int main()
{
    int arr1[5] = {1,2,3,4,5}; 
	int arr2[5] = {1,2,3,4,5};

    int *p = arr1;
    int *q = arr2;

    
    addArray(p , q);
    
    return 0;
}

void addArray(int *p , int *q)
{
    int i = 0;
    int finalArray[5];
    
    while(i < 5)
    {
        
        
        int n = *p + *q ;

        finalArray[i] = n; 

        p++;
        q++;
        i++;
    }

      for (int i = 0; i < 5; i++)
    {
        printf("%d   " , finalArray[i]);
    }



}