#include<stdio.h>
#include<stdlib.h>

typedef struct csll
{
    int data;
    struct csll *next;
}csl;

csl* create(csl* head)
{
    int ans;
    csl* last;

    do
    {
        csl* nw = (csl*) malloc(sizeof(csl));
        printf("Enter Data :");
        scanf("%d" , &nw->data);
        nw->next = NULL;
        
        if(head == NULL)
        {
            nw->next = nw;
            head = nw;
        }
        else
        {
            nw->next = last->next;
            last ->next  = nw;
        }

        last = nw;

        printf("Do you want to enter a new node(0/1): ");
        scanf("%d" , &ans);

    }while(ans == 1);
    return head;
}


csl* display(csl* head)
{
    csl* p = head;

    do
    {
        printf("[%d] " , p->data);
        p = p->next;

    } while (p != head);
}


int main()
{
    csl* head = NULL;
    head = create(head);
    display(head);
}
