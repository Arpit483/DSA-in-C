#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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


bool loop(dll* head)
{
    dll *p = head;
    dll *q = head;

    if(head == NULL)return false;
    while(q != NULL && q->next != NULL)
    {
        p = p->next;
        q = q->next->next;

        if(p == q) return true;
    }
    return false;

}


int main()
{
    dll* head = NULL;
    head = create(head);
}