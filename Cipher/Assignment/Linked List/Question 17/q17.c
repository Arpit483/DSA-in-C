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
void reverse(std *head);

int main(void)
{
    std *start = NULL;
    start = create(start);

    printf("---------------------------Display---------------------------\n");
    display(start);


    reverse(start);

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
        printf("%d \t" , p->rollno);
        p = p->next;
    }
    printf("\n");
}


void reverse(std *head)
{
    

    if(head ==NULL)
        return;
    
    reverse(head->next);        
    printf("%d \t " ,head->rollno);
    

}

