#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Singly_LL
{
    int data;
    struct Singly_LL *next;
}sll;


// * Create Function

sll* create(sll* head)
{
    int ans;
    sll *new, *prev;
    do
    {
        new = (sll *)malloc(sizeof(sll));
        printf("Enter Data: ");
        scanf("%d" , &new->data);
        new->next = NULL;

        if(head == NULL)
        {
            head = new;
        }
        else
        {
            prev->next = new;
        }

    prev = new;

    printf("Do you want to Enter a new node: ");
    scanf("%d", &ans);

    }while(ans == 1);

    return head;
}


// * Node

sll* node(int data)
{
    sll *curr = (sll *)malloc(sizeof(sll));
    curr->data = data;
    curr-> next = NULL;

    return curr;
}


// *Insert fn

sll* generic_insert(sll* head, sll* prev, sll* mid, sll* next )
{
    mid->next = next;
    prev->next = mid;
    return head;
}

// * Delete fn

sll* generic_delete(sll*head , sll* prev, sll* del_node)
{
    prev->next = del_node->next;
    free(del_node);
    return head;
}

// * Search fn

int search_node(sll *head , int data)
{
    sll *p = head;

    while( p!= NULL && p->data != data )
    {
        p = p->next;
    }
    
    if(p == NULL)
    {
        return 0;
    }
    
    return p->data;

}

// * Insert Start

sll* insert_start(sll*head , int data)
{
    return generic_insert(node(data) , head, node(data), head->next);
}

// * Insert End

sll* insert_end(sll*head , int data)
{
    sll *p = head;

    while(p->next != NULL && p->next->next!= NULL)
    {
        p = p->next;
    }

    return generic_insert(head , p, node(data), p->next);
}

// * Display Function

void display(sll* head)
{
    if(head == NULL)
    {
        printf("Linked List is Empty");
        return;
    }
    sll *curr = head;
    printf("[Start]->");

    while(curr!= NULL)
    {
        printf("[%d]->", curr->data);
        curr = curr->next;
    }
    printf("[END]");
}



int get_end(sll* head)
{
    if(head == NULL)
    {
        return 0;
    }
    
    sll *p = head;

    while(p->next!= NULL)
    {
        p = p->next;
    }
    
    return p->data;
}



int main()
{
    sll *head = NULL;
    head = create(head);
    display(head);
    printf("\n%d" , get_end(head));
}