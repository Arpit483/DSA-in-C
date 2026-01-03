#include<stdio.h>
#include<stdlib.h>

typedef struct csl
{
    int data;
    struct csl *next;
    struct csl *prev;
}cll;

cll* create(cll* head)
{
    cll* last;
    int ans;

    do
    {
        cll* nw = (cll*) malloc(sizeof(cll));
        nw->next = nw;
        nw->prev = nw;
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
    
    do
    {
        printf("[ %d ]" , p->data);
        p = p->next;
        

    }while(p!= head);

    printf("\n");

}

void display_back(cll *head)
{
    cll* p = head->next;

    if(p == head->next)
    {
        return; 
    }
    display_back(p->next);
    printf("[%d]" , p->data);

    

}

void del_end(cll *head)
{
    cll* p = head;
    
    do
    {
        p = p->next;
    }while(p->next->next!= head);

    cll* temp = p->next;

    p->next = temp->next;
    temp->next = NULL;
    free(temp);
}

void ins_end(cll *head , int data)
{
    cll* p = head;
    
    do
    {
        p = p->next;
    }while(p->next!= head);

    cll* nw = (cll*) malloc(sizeof(cll));
    nw->data = data;

    nw->next = p->next;
    p->next = nw;

}

int main()
{
    cll* head = NULL;
    head = create(head);

    display(head);
    ins_end(head , 100);
    display(head);
    del_end(head);
    display(head);

    display_back(head);

}