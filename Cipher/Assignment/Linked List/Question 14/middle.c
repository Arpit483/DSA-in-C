/*write a c program to Create a Singly linked list and Find and print the middle element*/

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
void middle(std *head);


int main(void)
{
    std *start = NULL;
    start = create(start);

    printf("---------------------------Display---------------------------\n");
    display(start);


    printf("---------------------------After---------------------------\n");
    middle(start);

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

void middle(std *head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    std *a = head, *b = head;

    while (a != NULL && a->next != NULL)
    {
        b = b->next;
        a = a->next->next;
    }

    printf("Middle Student == Roll No: %d , Name: %s\n", b->rollno, b->name);
}