#include <stdio.h>
#include <string.h>

struct student 
{

    int rollno;
    char name[20];

};


int main()
{
    struct student s = {45 , "Rohit"};               // Inline Initialization
    printf("Student Roll No : %d\n " , s.rollno);
    printf("Student Name : %s\n " , s.name);

    s.rollno = 17;                                  // piece meal Initialization
    strcpy(s.name , "Dhiraj");
    printf("Student Roll No : %d\n" , s.rollno);
    printf("Student Name : %s\n" , s.name);

    printf("Enter The Student roll no. : ");        // User Input
    scanf("%d" , &s.rollno);                        // used & to show address of interger value
    printf("Enter The Student name : ");
    scanf("%s" , s.name);                           // shows address of forst element of array of char 
    printf("Student Roll No  %d\n" , s.rollno);
    printf("Student Name  %s\n" , s.name);


    return 0;

}