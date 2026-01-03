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

}

dll* del_head(dll *head)
{
    if(head == NULL)
    {
        printf("Invalid No Head");
        return head;
    }
    printf("\n");
    
    dll* p = head->next;
    head ->next = NULL;
    free(head);
    
    return p;
}



dll* del_pos(dll* head , int pos)
{
    if(pos < 1)
    {
        printf("Invalid");
        return head;
    }

    if(pos == 1)
    {
        return del_head(head);
    }

    int n = 1;
    dll* p = head;
    while(p != NULL && n < pos)
    {
        p = p->next;
        n++;
    }


    p->prev->next = p->next;
    if(p->next!= NULL)
        p->next->prev = p->prev;

    p->next = p->prev = NULL;
    free(p);

    return head;
}

int main()
{
    dll* head = NULL;
    head = create(head);
    display(head);
    printf("\nEnter Postion to delete: ");
    int n;
    scanf("%d" , &n);
    head = del_pos(head , n);
    display(head);
}