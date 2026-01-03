#include <stdio.h>
#include<stdlib.h>

typedef struct sll
{
    int data;
    struct sll *next;
}sll;

sll* create(sll* head)
{
    sll *last;
    int ans;
    do{
        sll* nw = (sll*) malloc(sizeof(sll));
        printf("Enter Data: ");
        scanf("%d" , &nw->data);
        nw->next = NULL;

        if(head == NULL)
        {
            head = nw;
        }
        else
        {
            last ->next = nw;
        }
        
        last = nw;

        printf("Do you want to insert a new node(0/1): ");
        scanf("%d" , &ans);

    }while(ans == 1);

    return head;
}

void display(sll *head)
{
    sll *p = head;

    while(p!=NULL)
    {
        printf("[ %d ]" , p->data);
        p = p ->next;
    }
    printf("\n");
    
}

void ins_end(sll* head , int data)
{
    sll* p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }
    sll* nw = (sll*) malloc(sizeof(sll));

    nw->data = data;

    nw->next = NULL;

    p->next = nw;

}


int main()
{
    sll* head = NULL;
    head = create(head);

    display(head);
    printf("Enter Data to insert at end: ");
    int n;
    scanf("%d" , &n);
    
    ins_end(head , n);

    display(head);

}
