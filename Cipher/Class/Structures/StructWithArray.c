#include <stdio.h>

struct student
{
    int rollno ;
    char name[20];
    char city[20];
};

int main()
{
    struct student s[5];
    int i;
    
    for (i = 0 ; i < 5 ; i++)
    {
        printf("Enter Roll Number \n");
        scanf("%d" , &s[i].rollno);
        
        printf("Enter Name \n");
        scanf("%s" , s[i].name);

        printf("Enter City \n");
        scanf("%s" , s[i].city);
    }

    printf("---- Student Details ---- \n");

    for (i = 0; i < 5; i++)
    {
        printf(" RollNo :  %d \n" , &s[i].rollno );
        printf(" Name :  %s \n" , s[i].name );
        printf(" City :  %s \n" , s[i].city );
        printf("\n");
        
    }

    return 0;
    
}