
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
std* end(std *head);

int main(void)
{
    std *start = NULL;
    start = create(start);

    printf("---------------------------Display---------------------------\n");
    display(start);

    start = end(start);
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

std* end(std *head)
{
    std *q = head;
    std *new = (std*) malloc(sizeof(std));
    
    printf("Enter Roll Number \n");
    scanf("%d" , &new->rollno);

    printf("Enter Name \n");
    scanf("%s" , new->name);

    new->next = NULL;

    while(q ->next != NULL)
    {
        q = q->next;
    }

    q ->next = new;

    return head;
} 