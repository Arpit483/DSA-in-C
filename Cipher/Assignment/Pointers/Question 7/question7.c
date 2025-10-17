/*

   Write a Program to read and print student details using structure pointer. 

*/

#include <stdio.h>

typedef struct Student
{
   int rollNo;
   char Name[20];

}std;

int main()
{
   std s1 = {21 , "Hello"};
   
   std *p;

   p = &s1;
   
   printf("%d \n" , p -> rollNo );
   printf("%s" , p -> Name);

	return 0;
}

