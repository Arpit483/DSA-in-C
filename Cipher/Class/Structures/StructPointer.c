#include <stdio.h>
#include <stdlib.h>

typedef struct student 
{
    int rollno;
    int marks;
    char name[20];
    char city[20];
}s;

int main (void)
{
    int n;
    int i;
    printf("Enter The Number of Students -> ");
    scanf("%d" , &n);

    s *p;
    p = (s*) malloc (n * sizeof(s));

    if(p == NULL)
    {
        printf("Critical Failure");
        return 1;
    }
 
  

    for (i = 0 ; i < n ; i++)
    {
        printf("Enter Roll Number \n");
        scanf("%d" , &p[i].rollno);
        
        printf("Enter Name \n");
        scanf("%s" , p[i].name);

        printf("Enter City \n");
        scanf("%s" , p[i].city);

        printf("\n");
    }

    printf("---- Student Details ---- \n");

    for (i = 0; i < n; i++)
    {
        printf(" RollNo :  %d \n" , &p[i].rollno );
        printf(" Name :  %s \n" , p[i].name );
        printf(" City :  %s \n" , p[i].city );
        printf("\n");
        
    }

    free(p);
    return 0;


}