/*write a c program to Create a Singly linked list and sort the linked list*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char name[50];
    int rollno;
    struct student *next;
}std;

std* create (std *head);
void display (std *head);
std* sort (std *head);

int main(void)
{
    std *start = NULL;
    start = create(start);

    printf("---------------------------Display---------------------------\n");
    display(start);
     
    start = sort(start);
    printf("---------------------------After---------------------------\n");
    display(start);

}

std* create (std *head)
{
    int ans;
    std *new , *last;

    do
    {
        new = (std*) malloc (sizeof(std));

        printf("Enter Roll Number \n");
        scanf("%d" , &new->rollno);

        printf("Enter Name \n");
        scanf("%s" , new->name);
        
        if(head == NULL)
        {
            head = new;
        }
        else
        {
            last ->next = new;
        }
        last = new;

        printf("Do you want to enter a new node (0/1) \n");
        scanf("%d" , &ans);

    }while(ans == 1);

    return head;

}


void display (std *head)
{
    std *p = head;
    
    while(p != NULL)
    {
        printf("Roll Number : %d \t Name: %s \n" , p->rollno , p->name);
        p = p->next;
    }
}


std* sort (std *head)
{
    for(std *p = head ; p!=NULL ; p = p->next)
    {
        for(std *q = p->next ; q!=NULL ; q = q->next)
        {
            if(q->rollno < p->rollno)
            {
                std temp;
                temp.rollno = p->rollno;
                p->rollno = q->rollno;
                q->rollno = temp.rollno;

                strcpy(temp.name , p->name);
                strcpy(p->name , q->name);
                strcpy(q->name , temp.name);
            }
        }
    }

    return head;
}