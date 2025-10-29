#include <stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student
{
    int no;
    char name[20];
    struct student *next;
}s;

int main(void)
{
    s *nw;
    nw = (s*) malloc(sizeof(s));
    
    printf("Enter Number and Name \n ");
    scanf("%d  %s" , &nw->no , nw->name);
    printf("%d  %s" , nw->no , nw -> name );
    nw->next = NULL;
    return 0;
}