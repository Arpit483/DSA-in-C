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
void swap (s *head);
void con_add (s *p);

int main(void)
{
    // s *start = NULL;

    // start = create(start);              
    
    // void alt_display(start);
    // void swap (start);
    // void con_add (start);

    s *start = NULL;

    start = create(start);                          // Head pointer is stored in start since create fn returns head
    printf("\n--- Original List ---\n");
    display(start);                                // Head pointer is stored in start since create fn returns head  ||||| Head pointer is passed

    printf("\n--- Alternate Display ---\n");
    alt_display(start);

    printf("\n--- After Swapping Consecutive Nodes ---\n");
    swap(start);
    display(start);

    printf("\n--- After Adding Consecutive Nodes ---\n");
    con_add(start);
    display(start);


    return 0;


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
    if(p == NULL)
    {
        return; 
    }
    else
    {
        while (p !=NULL)
        {
            printf("%d, %s  \n" , p ->no , p->name );
            p = p->next;
        }
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
            if(p->next == NULL){
                break;
            }
            p = p->next->next;

        } while (p != NULL);
        
    }
} 


void swap (s *head)
{
    s *p = head;
    s*q;
    while (p != NULL && p->next != NULL)
    {
    q = p->next;
    int a = p->no;
    char name[20];
    strcpy(name, p->name);

    p->no = q->no;
    strcpy(p->name , q->name);

    q->no = a;
    strcpy(q->name ,  name);

    p = q->next;

    }
}


/*
-----------------------------------------------------------------------------------
*/


// Add 2 consecutive nodes

void con_add (s *p)
{
    s *q , *nw;
    
    while(p != NULL && p->next != NULL)
    {
        q = p -> next;
        nw = (s *) malloc (sizeof(s));
        
        nw->no = p->no + q->no;

        snprintf(nw->name ,sizeof(p->name) ,"%s_%s" , p->name,q->name );
        nw ->next = q->next;
        q->next = nw;
        p = nw->next;
    }
}
