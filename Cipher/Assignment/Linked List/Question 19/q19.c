/*
write a c program to Create a Singly linked list  and perform menu driven which includes following functions:
          - create(),
          - Insert(),
          - Delete(),
          - Reverse(),
          - print()
*/

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


sll* del(sll *head , int pos)
{
    sll *p = head;
    sll *q = NULL;


    if(pos == 1)
    {
        head =  head ->next;
        free(p);
        return head;
    }

    else
    {
        for(int i = 1 ; i < pos && p != NULL ; i++ )
        {
            q = p;
            p = p->next;
        }

      if(p == NULL) 
        {
            printf("Invalid position! No node deleted.\n");
            return head;
        }

        q->next = p->next;
        free(p);

    }

    return head;
} 


sll* ins_pos(sll *head, int pos)
{
    sll *p = head;
    sll *new;

    new = (sll*) malloc(sizeof(sll));

    printf("Enter Data: ");
    scanf("%d" , &new->data);

    new ->next = NULL;

    if(pos == 1)
    {
        new ->next = p;
        head = new;
    }

    else
    {
        for(int i = 2  ; i < pos && p != NULL; i++)
        {
            p = p ->next; 
        }

        new ->next = p ->next;
        p->next = new;
    }

    return head;
}

int main(void)
{
    sll*head = NULL;
    int ch , val , pos;

    do
    {
        printf("1. Create \n2. Insert \n3. Delete \n4. Reverse \n5. Print  \n6. Exit");
        printf("\nEnter Choice: ");
        scanf("%d" , &ch);

        switch(ch)
        {
            case 1:
                head = create(head);
                break;

            case 2:
                printf("Enter Postion to insert: ");
                scanf("%d" , &pos);
                head = ins_pos(head , pos);
                break;

            case 3:
                printf("Enter Postion to Delete: ");
                scanf("%d" , &pos);
                head = del(head , pos);
                break;

            case 4: 
                printf("Reversing the Linked List: ");
                head = revert(head);
                break;

            case 5: 
                display(head);
                break;

            default: 
                printf("Invalid Choice");
                break;
        }
    }while(ch != 6);


}

