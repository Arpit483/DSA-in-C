//write a c program to sort the doubly linked list.
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
    if(head == NULL){
        printf("Linked List is Empty");
        return;
    }
    dll *p = head;
    
    while(p!=NULL)
    {
        printf("[ %d ] " , p->data);
        p = p->next;
    }    

    printf("\n");
}

dll* sort(dll* head)
{
    for(dll* p = head ; p != NULL ; p = p->next)
    {
        for(dll* q = p->next ; q != NULL ; q = q->next)
        {
            if(p->data > q->data)
            {
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
    return head;
}



int main()
{
    dll* head = NULL;
    head = create(head);
    display(head);
    head = sort(head);
    display(head);

}