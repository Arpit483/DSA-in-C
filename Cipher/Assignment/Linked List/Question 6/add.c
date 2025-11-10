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
std* add(std *head);

int main(void)
{
    std *start = NULL;
    start = create(start);

    printf("---------------------------Display---------------------------\n");
    display(start);

    start = add(start);
    printf("---------------------------After Add---------------------------\n");
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

std* add (std *head)
{
    if(head == NULL || head->next == NULL)
        return head;
        
    std *a = head , *b = head->next;
    std *new;   


    while(a != NULL && b != NULL)
    {
        new = (std*) malloc (sizeof(std));
        new ->rollno = a ->rollno + b->rollno;

        strcpy(new->name, a->name);
        strcat(new->name, b->name);

        new->next = NULL;

        new ->next = b ->next;
        b->next = new;

        a = new->next;
        if(a != NULL)
        {
            b = a->next;
        }

    }
    
    return head;    
}