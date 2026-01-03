//write a c program to Create a doubly linked list and Sort the doubly linked list while creation.
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
        else if(nw->data < head->data)
        {
            nw->next = head;
            head->prev = nw;
            head = nw;
        }
        else
        {
            dll* p = head;
            while(p->next != NULL && p->next->data < nw->data)
            {
                p = p->next;
            }

            nw->next = p->next;
            nw->prev = p;
            if (p->next != NULL)
                p->next->prev = nw;

            p->next = nw;
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



int main()
{
    dll* head = NULL;
    head = create(head);
    display(head);

}