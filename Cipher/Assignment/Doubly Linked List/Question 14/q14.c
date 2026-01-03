#include<stdio.h>
#include<stdlib.h>

typedef struct DLL
{
    int data;
    struct DLL *prev;
    struct DLL *next;
}dll;

dll* create(dll *head)
{
    int ans;
    dll *nw , *last;

    do
    {
        nw = (dll*)malloc(sizeof(dll));
        printf("Enter Data: ");
        scanf("%d" , &nw->data);
        nw->next = nw->prev = NULL;

        if(head == NULL)
        {
            head = nw;
        }
        else
        {
            last ->next = nw;
            nw->prev = last;
        }

        last = nw;
        
        printf("Do You want to Insert a new node (0/1): ");
        scanf("%d" , &ans);

    }while(ans==1);

    return head;
}

void display(dll *head)
{
    dll *p = head;
    
    while(p!=NULL)
    {
        printf("[ %d ] " , p->data);
        p = p->next;
    }

    printf("\n");
}



void ins_end(dll* head , int data)
{
    dll *p = head;
    while(p->next!= NULL)
    {
        p = p->next;
    }
    dll* nw = (dll*)malloc(sizeof(dll));
    nw->data = data;
    p->next = nw;
    nw->prev = p;
    nw->next = NULL;
}

dll* sort_two(dll* head1 , dll* head2 , dll* head3)
{
    dll *p = head1;
    dll *q = head2;

    while(p!= NULL && q!=NULL)
    {

        if(head3 == NULL)
        {
            head3 = (dll*)malloc(sizeof(dll)); 
            if(p->data > q->data)
            {
               
                head3->data = q->data;
                head3->prev = head3->next = NULL; 
                q = q->next;
            }
            else
            {
                head3->data = p->data;
                head3->prev = head3->next = NULL; 
                p = p->next;
            }
            continue;
        }
        
        if(p->data > q->data)
        {
            ins_end(head3 , q->data);
            q = q->next; 
        }
        else
        {
            ins_end(head3 , p->data);
            p = p->next;
        }
    }
    if(q == NULL && p != NULL)
    {
        while(p!=NULL)
        {
            ins_end(head3 , p->data);
            p = p->next;
        }
    }
    else if(p == NULL && q!= NULL)
    {
        while(q!=NULL)
        {
            ins_end(head3 , q->data);
            q = q->next;
        }
    }

    return head3;
}



int main()
{
    dll* head1 = NULL;
    head1 = create(head1);
    display(head1);

    dll* head2 = NULL;
    head2 = create(head2);
    display(head2);

    dll* head3 = NULL;
    head3 = sort_two(head1 , head2 , head3);

    display(head3);
}