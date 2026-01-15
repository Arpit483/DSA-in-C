#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SinglyLL
{
    char name[50];
    int data;
    struct SinglyLL *next;
}sll;

sll* create(sll* head)
{
    int ans;

        sll* nw = (sll*) malloc(sizeof(sll));
        printf("Enter Data: ");
        scanf("%d" , &nw->data);
        nw->next = NULL;

    printf("Do You want to continue(0/1): ");
    scanf("%d", &ans);
    
    if(ans ==1)
    {
        nw->next = create(nw->next);
    }

    return nw;
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



int main()
{
    sll* head = NULL;

    head = create(head);
    display(head);
}