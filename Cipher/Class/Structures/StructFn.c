#include <stdio.h>
#include <stdlib.h>

typedef struct student 
{
    int rollno;
    int marks;
    char name[20];
    char city[20];
}s;

void accept(s *s, int n);
void display(s *s, int n);

int main(void)
{
    int n;
    printf("Enter the Number of Students -> ");
    scanf("%d" , &n);

    s *p;

    p = (s*) malloc (n * sizeof(s));
    
    if (p == NULL)
    {
        printf("Critical Erorr");
        return 1;
    }

    accept(p , n);
    display(p , n);

    free(p);
    return 0;
}

void accept( s *s, int n){
    int i;
    for (i = 0 ; i < n ; i++)
    {
        printf("Enter Roll Number \n");
        scanf("%d" , &s[i].rollno);
        
        printf("Enter Name \n");
        scanf("%s" , s[i].name);

        printf("Enter City \n");
        scanf("%s" , s[i].city);
    }
}


void display (s *s , int n)
   {
    int i;
    printf("---- Student Details ---- \n");

    for (i = 0; i < n; i++)
    {
        printf(" RollNo :  %d \n" , &s[i].rollno );
        printf(" Name :  %s \n" , s[i].name );
        printf(" City :  %s \n" , s[i].city );
        printf("\n");
        
    }

   }


