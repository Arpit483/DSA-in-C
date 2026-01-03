#include <stdio.h>
#include<stdlib.h>

typedef struct dll
{
    int data;
    struct dll *next;
    struct dll *prev;
}dll;

dll* create(dll* head)
{
    dll *last;
    int ans;
    do{
        dll* nw = (dll*) malloc(sizeof(dll));
        printf("Enter Data: ");
        scanf("%d" , &nw->data);
        nw->next = NULL;
        nw->prev = NULL;

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

        printf("Do you want to insert a new node(0/1): ");
        scanf("%d" , &ans);

    }while(ans == 1);

    return head;
}

void display(dll *head)
{
    dll *p = head;

    while(p!=NULL)
    {
        printf("[ %d ]" , p->data);
        p = p ->next;
    }
    printf("\n");
    
}


void search(dll * head, int s)
{
    dll *p = head;
    while(p != NULL)
    {
        if(p ->data == s)
        {
            printf("Found The Element: %d" , p->data);
            return;
        }
        p = p->next;
    }

    printf("Not Found");
}


int main()
{
    dll * head = NULL;
    head = create(head);

    display(head);

    printf("Enter Data to find: ");
    int n;
    scanf("%d" , &n);
    search(head , n);
}
