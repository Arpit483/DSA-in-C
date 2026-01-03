#include<stdio.h>
#include<stdlib.h>

typedef struct csl
{
    int data;
    struct csl *next;
}cll;

cll* create(cll* head)
{
    cll* last;
    int ans;

    do
    {
        cll* nw = (cll*) malloc(sizeof(cll));
        nw->next = nw;
        printf("\nEnter Data to Insert: ");
        scanf("%d" , &nw->data);

        if(head == NULL)
        {
            head = nw;
        }
        else
        {
            nw->next = last->next;
            last->next = nw;
        }
        last = nw;
        printf("Do you want to insert a new node(0/1): ");
        scanf("%d" , &ans);
    } while (ans == 1);

    return head;
}


void display(cll *head)
{
    cll* p = head;
    int n = 0;
    
    do
    {
        printf("[ %d ]" , p->data);
        p = p->next;
        n++;

    }while(p!= head);

    printf("\n%d" , n);
}

int main()
{
    cll* head = NULL;
    head = create(head);

    display(head);
}


