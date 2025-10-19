/* 

    write a C program to create, declare and initialize structure.
    - define a structure "student", which includes the details of students,
    - declare an object of the structure and initialize the structure members.
	
*/

#include<stdio.h>
#include<string.h>

typedef struct student
{
    int rollno;
    char name[20];
    int marks;

}sd; 


int main()
{
   
   sd s;
   strcpy(s.name , "Sara");
   s.rollno = 20;
   s.marks = 10;

   printf("%s" , s.name);

   return 0;

}	