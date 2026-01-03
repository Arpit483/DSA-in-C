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


void mid_elm(dll* head)
{
    dll *p = head;
    dll *q = head;

    while(q != NULL && q->next != NULL)
    {
        p = p->next;
        q = q->next->next;
    }

    if(q != NULL)
    {
    printf("\nMiddle Node is: %d" , p->data);
    return;
    }
    else
    {
        printf("\nMiddle Nodes are: %d and %d" , p->prev->data , p->data);
        return;
    }

}

int main()
{
    dll* head = NULL;
    head = create(head);
    display(head);

    mid_elm(head);
}