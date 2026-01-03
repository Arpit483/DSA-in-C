/* 

  write a C program to read and print the student details using structure and Dynamic Memory Allocation.
  - create a structure with student details and print the inputted details. 
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
  std* nw = (std*) malloc(sizeof(std));
  printf("Enter Name : ");
  scanf("%s" , nw->name);

  printf("\nEnter RollNo : ");
  scanf("%d" , &nw->rollno);
  
  printf("%s -> %d " ,nw->name,  nw->rollno);

  free(nw);

  return 0;

}