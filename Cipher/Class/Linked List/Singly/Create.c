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


// -------------------------------------------------------------------------------------------------------



void search (s *head , int no)
{
    s *p = head;
    while(p != NULL)
    {
        if(p->no = no)
        {
            printf("%d \t %s" , p->no , p->name);
            return;
        }
        else
        {
            p = p->next;
        }
    }
}

// ----------------------------------------------------------------------------------------------------------


void reverse_print(s *p)
{

    if(p!=NULL)
    {
        return;
    }
    else
    {
        reverse_print( p ->next);
        printf("%d \t %s \n" , p->no , p->name);
    }
}

// ---------------------------------------------------------------------------------------------------------------


s* insert_at_point (s *head , int pos)
{
    s *p =head;
    s *nw = (s*) malloc(sizeof(s));
    scanf("%d" , &nw->no );
    scanf("%s" , nw->name );
    nw ->next = NULL;
    if(pos == 1)
    {
        nw ->next = p;
        p = nw;
        return p;
    }
    int i;

    for(i = 0 , p ; i<pos-1 && p!=NULL ; p = p->next , i++);

    if(p != NULL)
    {
        nw -> next = p ->next;
        p ->next = nw;
    }
    else
    {
        printf("INVALID POSTION");
        free(nw);
    }
    return p;
    
}


void delete_node (int post , s *head)
{
    s *p = head;
    s *q;
    int i;

    if (head == NULL)
    {
        printf("EMPTY LIST");
        return;
    }
    if(post == 1)
    {
        head = head ->next;
        printf("NODE DELETED");
        printf("%d" , p->no);
        free(head);
        free(p);
        return;
    }

    for (i = 1 ; i < post - 1 , p!=NULL ; i++)
    {
        p = p ->next;
    }

    // if position is invalid

    if(p == NULL || p->next == NULL )
    {
        printf("INVALID");
        return;
    }
    q = p ->next;
    p->next = q->next;
    printf("DELETED");
    free(q);
}


// --------------------------------------------------------------------------------------------


/*
Sorting of Linked List
*/

s* sort(s* head)
{
    s *p , *q =NULL;
    int temp_no;
    char temp_name[50];

    for (p =head ; p ->next !=NULL ; p = p ->next)
    {
        for (q =p ->next ; q !=NULL ; q = q ->next)
        {
            if(p ->no > q ->no)
            {
               temp_no = p->no;
                p->no = q->no;
                q->no = temp_no;

                
                strcpy(temp_name, p->name);
                strcpy(p->name, q->name);
                strcpy(q->name, temp_name);
            }
        }
    }
    return head;
}


// --------------------------------------------------------------------------------------------------

void middle (s *head)
{
    s *fast = head;
    s *slow = fast;
    while (fast != NULL && fast ->next != NULL)
    {
        fast = fast ->next->next;
        slow = slow->next;
    }
    printf("%d" , slow->no);
}

// -------------------------------------------------------------------------------------------------------------------------

void reverse_LL(s *head)
{

    s *r = NULL , *p = head , *q = NULL;

    while(p != NULL )
    {
        q = p ->next;

        p->next = r;

        r = p;

        p = q;
    }
    return r;
}

