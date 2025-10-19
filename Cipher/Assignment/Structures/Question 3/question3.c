/*  

    Write a c program which demonstrate a nested structure 
	- define a structure employee inside a structure person.
    - structure person data: 
                        Name, Age, Date of birth, blood group.
    - structure employee data:
                        Company name, Emp id, salary, years of experiance.
						
	- create objects of structure and display the all details of a person.

*/
#include <stdio.h>

struct person 
{
    char name[20];
    int age;
    char dob[100];
    char BloodGrp[4];

    struct employee
    {
        char CompanyName[100];
        int EmpId;
        int salary;
        int Exp;

    }employee;
};



int main()
{
   
    struct person p = {"Arpit" , 18 , "12/03/2005" , "B+" , {"Self" , 01 , 100000 , 2} };
    printf("%-15s : %s\n", "Name", p.name);
    printf("%-15s : %d\n", "Age", p.age);
    printf("%-15s : %s\n", "DOB", p.dob);
    printf("%-15s : %s\n", "Blood group", p.BloodGrp);
    printf("----------------------------------------\n");
    printf("%-15s : %s\n", "Company", p.employee.CompanyName);
    printf("%-15s : %d\n", "Employee ID", p.employee.EmpId);
    printf("%-15s : %d\n", "Salary", p.employee.salary);
    printf("%-15s : %d\n", "Experience", p.employee.Exp);




   
   return 0;
 
}	