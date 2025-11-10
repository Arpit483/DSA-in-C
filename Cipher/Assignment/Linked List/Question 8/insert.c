/*write a c program to Create a Singly linked list and Insert a node in the given position.*/

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
std* ins_pos(std *head, int pos);

int main(void)
{
    std *start = NULL;
    start = create(start);

    printf("---------------------------Display---------------------------\n");
    display(start);

    int p;
    printf("Enter Position of Node to be  inserted");
    scanf("%d" , &p);

    start = ins_pos(start , p);
    printf("---------------------------After Insertion---------------------------\n");
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

std* ins_pos(std *head, int pos)
{
    std *p = head;
    std *new;

    new = (std*) malloc(sizeof(std));

    printf("Enter Roll Number");
    scanf("%d" , &new->rollno);

    printf("Enter Name");
    scanf("%s" , new->name);

    new ->next = NULL;

    if(pos == 1)
    {
        new ->next = p;
        head = new;
    }

    else
    {
        for(int i = 2  ; i < pos && p != NULL; i++)
        {
            p = p ->next; 
        }

        new ->next = p ->next;
        p->next = new;
    }

    return head;
}