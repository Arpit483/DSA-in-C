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



void swap(int *p , int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

void compare_two(dll* head)
{
    dll* p = head;

    while(p!=NULL && p->next!= NULL)
    {
        if(p->data > p->next->data)
        {
            swap(&p->data , &p->next->data);
        }

        p = p->next->next;
    }

}


int main()
{
    dll* head = NULL;
    head = create(head);
    display(head);

    compare_two(head);
    display(head);

}