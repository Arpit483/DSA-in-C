#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student 
{
    int no;
    char name[20];
    struct student *next;
}s;

s* create (s *head);
void display( s *p);
void alt_display(s* head);

int main(void)
{
    s *start = NULL;

    start = create(start);              // Head pointer is stored in start since create fn returns head
    display(start);                     // Head pointer is passed
    
}

s* create (s *head)               // Storing the value of structure pointer and returing it not the copy of structure
{
    int ans;
    s *new , *last;
    do
    {
        new = (s*)malloc(sizeof(s));
        printf("Enter Number And Name of The Student \n");
        scanf("%d %s" , &new->no , new->name);
        new -> next = NULL;
        
        if(head == NULL)
        {
            head = new;
        }
        else
        {
            last -> next = new;                // From 2nd iternation
        }

    last = new;                      // First node this will get executed 
    
    printf("Do You Want to add a new node(0/1) : \n");

    scanf("%d" , &ans);

    }while(ans == 1);

    return head;
}

void display(s *head )
{
    s *p = head;
    if(p = NULL)
    {
        return; 
    }
    else
    {
        do
        {
            printf("%d, %s  \n" , p ->no , p->name );
            p = p->next;
        }while (p ->next !=NULL);
    }
}

/* -------------------------------------------------------------------------------------------------*/

void alt_display(s* head)
{
    s *p = head;
    if(p == NULL)
    {
        return;
    }
    else
    {
        /*
        do
        {
            printf("%d , %s " , p-> no , p->name );
            p = (p->next)->next;
        }
        while(p -> next != NULL);
        */

        do
        {
            printf("%d , %s " , p-> no , p->name );
            if(p->next = NULL){
                break;
            }
            p = p->next->next;

        } while (p != NULL);
        
    }
} 


void swap (s *head)
{
    s *p = head;
    while (p != NULL && p->next != NULL)
    {
    
    int a = p->no;
    char name[20];
    strcpy(name, p->name);

    p->no = p->next->no;
    strcpy(p->name , p->next->name);

    p->next->no = a;
    strcpy(p->next->name ,  name);

    p = p ->next->next;

    }
}