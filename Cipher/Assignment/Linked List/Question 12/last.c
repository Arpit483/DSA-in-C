/*write a c program to Create a Singly linked list and Delete the node at the last position*/


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
std* last(std *head );

int main(void)
{
    std *start = NULL;
    start = create(start);

    printf("---------------------------Display---------------------------\n");
    display(start);

    start = last(start);
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

std* last(std *head )
{
    std *p = head;
    std *q = NULL;

    while(p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    free(p);

    return head;
} 