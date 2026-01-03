//write a c program to Create a doubly linked list, accept a key, and delete the node which contains the key element.
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

}

dll* del_head(dll* head)
{
    if(head == NULL)
        return NULL;
    
    dll* p = head->next;
    if(p != NULL)
        p->prev = NULL;

    free(head);
    return p;

}

dll* del_key(dll* head , int key)
{
    dll* p = head;
    if(head == NULL)
    {
        printf("Linked List is empty");
        return head;
    }

    while(p!=NULL && p->data != key)
    {
        p = p->next;
    }

    if(p == NULL)
    {
        printf("Element not found");
        return head;
    }

    if(p == head)
    {
        return del_head(head);
    }

    
    p->prev->next = p->next;
    
    if(p->next!=NULL)
        p->next->prev = p->prev;

    p->next = p->prev = NULL;
    
    free(p);

    return head;

}

int main()
{
    dll* head = NULL;
    head = create(head);
    display(head);
    printf("\nEnter Data to delete: ");
    int n;
    scanf("%d" , &n);
    head = del_key(head , n);
    display(head);

}