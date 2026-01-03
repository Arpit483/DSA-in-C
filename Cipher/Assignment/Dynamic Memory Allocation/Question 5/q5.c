/*

    write a C program to read and print the N student details using structure and Dynamic Memory Allocation.
    - create a structure with N number of student details and print the inputted details. 
	- Memory to store and print structure will be allocated at run time by using malloc() and released by free().

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
  int rollno;
  char name[20];

}std;

int main()
{
   int n;
   printf("Enter the Number of Students: ");
   scanf("%d" , &n);

   std* s =  (std*)malloc(n * sizeof(std));

   for (int i = 0; i < n; i++)
   {
    printf("Roll No: ");
    scanf("%d" , &s[i].rollno);

    printf("Name: ");
    scanf("%s" , s[i].name);

   }
   

   for (int i = 0; i < n; i++)
   {
   
   printf("%s -> %d \n" , s[i].name , s[i].rollno);

   }

   
   free(s);
   return 0;


}