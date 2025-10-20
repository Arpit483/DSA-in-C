/*  

   write a C program to input and print text using Dynamic Memory Allocation.
   - create memory for text string at run time using malloc() function, 
   - text string will be inputted by the user and displayed.
   - Using free() function  release the occupied memory.

*/

#include<stdio.h>
#include <stdlib.h>

void single();
void multiple();

int main()
{
    
	single();
    // printf("\n");
    multiple();
    
	return 0;
}   
   

void single() 
{

    char *c;
    c = (char *) malloc (sizeof(char));

    printf("%s" , "Enter A String : \n");
    scanf("%s" , c );

    printf("%s \n" , c);

    free(c);
}

void multiple()
{
    char *c;
    int i;
    printf("Enter Size of String : ");
    scanf("%d" , &i);

    c = (char *) malloc (i + 1);                     // For Null Terminator ->  In C, strings are arrays of characters that always end with a special character called the null terminator, written as: \0 It tells this is where the string ends
    
    printf("\nEnter The String : ");
    scanf("%s" , c);

    printf("%s" , c);

    free(c);


}