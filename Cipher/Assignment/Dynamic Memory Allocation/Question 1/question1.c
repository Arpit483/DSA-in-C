/*

      write a C program to create memory for int, char and float variable at run time.
     - create memory for int, char and float variables at run time using malloc() function
     - and before exiting the program release the memory allocated at run time by using free() function.
*/

#include<stdio.h>
#include<stdlib.h>


int main()
{
    int *a;
    char *c;
    float *f;

    a = (int*) malloc (sizeof(int));
    c = (char*) malloc (sizeof(char));
    f = (float*) malloc (sizeof(float)); 
    
    *a = 4;
    c = "Aad";
    *f = 3.14;

    printf("%d \n" , *a);
    printf("%s \n" , c);
    printf("%f \n" , *f);
    
    free(a);
    free(c);
    free(f);
	
	return 0;


}	 