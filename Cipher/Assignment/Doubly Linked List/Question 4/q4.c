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

dll* ins_head(dll *head)
{
    printf("Inserting head node : \n");
    dll* nw = (dll*)malloc(sizeof(dll));
    printf("Enter Data : ");
    scanf("%d" , &nw->data);
    nw->prev = NULL;
    nw->next = head;
    head->prev = nw;

    return nw;
}

dll* ins_pos(dll *head , int pos)
{

    
    if (pos < 1)
    {
        printf("Invalid");
        return head;
    }

    if (pos == 1)
    {
        return ins_head(head);
    }

   dll *p = head;
   int n = 1;
   while(p != NULL && n < pos - 1)
   {
    p = p->next;
    n++;
   }

   if(p == NULL)
   {
    printf("Invalid");
    return head;

   }
   
   dll *nw = (dll*)malloc(sizeof(dll));

   printf("Enter Data : ");
   scanf("%d" , &nw->data);

    nw->next = p->next;
    nw->prev = p;

    if (p->next != NULL)
        p->next->prev = nw;

    p->next = nw;

    return head;

}

    
int main()
{
    dll *head = NULL;
    head = create(head);
    int n;
    printf("\nEnter Postion to Insert: ");
    scanf("%d" , &n);
    head = ins_pos(head , n);

    display(head);
}