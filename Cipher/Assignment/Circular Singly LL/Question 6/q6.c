#include<stdio.h>
#include<stdlib.h>

typedef struct csll
{
    int data;
    struct csll *next;
}csl;

csl* create(csl* last)
{
    int n;
    printf("Enter Number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        csl *nw = (csl *)malloc(sizeof(csl));
        printf("Enter Data :");
        scanf("%d" , &nw->data);
    
        if(last == NULL)
        {
            last = nw;
            last->next = last;
        }
        else
        {
            nw->next = last->next;
            last->next = nw;
            last = nw;
        }

    }
    return last;
}


void display(csl* last)
{
    csl* temp = last;

    if(last == NULL)
    {
        printf("List is Empty");
        return;
    }
    temp = last->next;
    do
    {
        printf("[%d] " , temp->data);
        temp = temp->next;

    } while (temp != last->next);

    printf("\n");
}

csl* del_key(csl* last , int key)
{
    csl *p = last;
    csl *q = p->next;
    
    // if its the last node

    if(last->data == key)
    {

        if(last->next == last)
        {
            free(last);
            return NULL;
        }

        while(q->next != last)
        {
            q = q->next;
        }
        q->next = last->next;
        free(last);
        return q;
    }

    //if not last node

    while(q!= last && q->data!= key)
    {
        p = q;
        q = q->next;

        if(q == last && q->data != key)
        {
            printf("Key not found\n");
            return last;
        }

    }

    p->next = q->next;
    free(q);
    return last;
}

int main()
{
    csl* last = NULL;
    last = create(last);
    display(last);

    printf("Enter data to delete: ");
    int key;
    scanf("%d", &key);
    last = del_key(last, key);
    display(last);
}
