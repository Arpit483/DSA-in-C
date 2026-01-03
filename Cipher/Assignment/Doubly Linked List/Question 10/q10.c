//write a c program to Delete duplicate values(nodes) in doubly linked list.
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
    if(head == NULL){
        printf("Linked List is Empty");
        return;
    }
    dll *p = head;
    
    while(p!=NULL)
    {
        printf("[ %d ] " , p->data);
        p = p->next;
    }    

    printf("\n");
}

dll* del_dup(dll* head)
{
    for(dll* p = head ; p!=NULL ; p = p->next)
    {
        dll* q = p->next;

        while(q!=NULL)
        {
            if(p->data == q->data)
            {   
                dll* temp = q;
                q = q->next;

                temp->prev->next = temp->next;
                if(temp->next != NULL)
                    temp->next->prev = temp->prev;               

                free(temp);
            }
            else
            {
                q = q->next;

            }


        }
    }
    return head;

}


int main()
{
 dll* head = NULL;
 head = create(head);
 display(head);
 head = del_dup(head);
 display(head);
    
}