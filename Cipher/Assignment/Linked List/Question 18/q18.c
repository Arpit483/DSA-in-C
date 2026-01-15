#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SinglyLL
{
    char name[50];
    int data;
    struct SinglyLL *next;
}sll;

sll* create (sll*head)
{
    int ans;
    sll *nw , *last;

    do
    {
        nw = (sll*) malloc (sizeof(sll));

        printf("Enter Roll Number: ");
        scanf("%d" , &nw->data);


        if(head == NULL)
        {
            head = nw;
        }
        else
        {
            last ->next = nw;
        }
        last = nw;

        printf("Do you want to enter a new node (0/1): ");
        scanf("%d" , &ans);

    }while(ans == 1);

    return head;

}


void display (sll*head)
{
    sll*p = head;
    
    while(p != NULL)
    {
        printf("%d \t" , p->data);
        p = p->next;
    }
    printf("\n");
}


sll* revert(sll* head)
{
    sll *curr = head;
    sll* prev = NULL;
    sll* next = NULL;

    while(curr != NULL)
    {
        next = curr->next;
        curr ->next  = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}


int main(void)
{
    sll*head = NULL;
    head = create(head);

    display(head);

    head = revert(head);
    display(head);


}

