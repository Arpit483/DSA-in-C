/*
   write a C program to read and print an employee's detail using structure.
   - read and print the employee's details like name, employee id, salary etc using structure. 
*/

#include<stdio.h>
#include<string.h>

typedef struct employee 
{
    char name [20];
    int id;
    int salary;

}emp;

int main()
{
    emp e;
    strcpy(e.name , "Someone");
    e.id = 23261;
    e.salary = 1000000;
    
    printf("%s \t %s \n%s \t %d \n%s \t %d \n" , "Name" , e.name , "ID" , e.id , "Salary" , e.salary);

	
	return 0;


}