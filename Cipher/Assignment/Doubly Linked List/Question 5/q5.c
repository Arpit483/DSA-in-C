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

}



void ins_end(dll* head)
{
    dll *p = head;
    while(p->next!= NULL)
    {
        p = p->next;
    }
    dll* nw = (dll*)malloc(sizeof(dll));
    printf("\nEnter Data: ");
    scanf("%d" , &nw->data);

    p->next = nw;
    nw->prev = p;
    nw->next = NULL;
}


int main()
{
    dll* head = NULL;
    head = create(head);
    display(head);
    ins_end(head);
    display(head);
}