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

sll* del_key(sll* head , int key)
{
    sll* p = head->next;

    if(head->data == key)
    {
        printf("Deleting head: %d\n" , head->data);
        sll* temp = head;
        head = head ->next;
        temp->next = NULL;
        free(temp);
        return head;
    }

    while(p->next!= NULL && p->next->data != key)
    {
        p = p->next;
    }

    if(p->next == NULL)
    {
        printf("Data is not present");
    }
    else
    {
        printf("Data is Found: %d\n" , p->next->data);
        sll* temp = p->next;
        p->next = p->next->next;
        temp->next = NULL;
        free (temp);
        printf("Data Deleted\n");
        return head;
    }

}


sll* rev_ll(sll* head)
{
    sll* prev = NULL;
    sll* curr = head;
    sll* nxt = NULL;

    while(curr != NULL)
    {
        nxt = curr->next;
        curr->next = prev;

        prev = curr;

        curr = nxt;
    }

    return prev;
}


int main()
{
    sll* head = NULL;
    head = create(head);
    display(head);

    int n;
    printf("\nEnter Key to delete: ");
    scanf("%d" , &n);
    head = del_key(head , n);
    display(head);

    printf("\nReversing the Linkedlist\n");
    head = rev_ll(head);
    display(head);
}
