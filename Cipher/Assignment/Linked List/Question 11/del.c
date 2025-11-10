/*write a c program to Create a Singly linked list and Delete the node in the given position*/


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
std* del(std *head , int pos);

int main(void)
{
    std *start = NULL;
    start = create(start);

    printf("---------------------------Display---------------------------\n");
    display(start);

    int pos;
    printf("Enter The Node Position You Want to Delete");
    scanf("%d" , &pos);

    start = del(start , pos);
    printf("---------------------------After Delete Head---------------------------\n");
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

std* del(std *head , int pos)
{
    std *p = head;
    std *q = NULL;


    if(pos == 1)
    {
        head =  head ->next;
        free(p);
        return head;
    }

    else
    {
        for(int i = 1 ; i < pos && p != NULL ; i++ )
        {
            q = p;
            p = p->next;
        }

      if(p == NULL) 
        {
            printf("Invalid position! No node deleted.\n");
            return head;
        }

        q->next = p->next;
        free(p);

    }

    return head;
} 