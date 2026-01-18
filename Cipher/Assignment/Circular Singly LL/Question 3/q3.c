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

csl* ins_head(csl* last)
{
    csl *nw = (csl *)malloc(sizeof(csl));
    printf("Enter Data: ");
    scanf("%d", &nw->data);

    nw->next = last->next;
    last->next = nw;
    return last;
}


csl* ins_pos(csl* last , int pos)
{
    if(pos == 1)
    {
        return ins_head(last);
    }
    
    csl *temp = last->next;
    
    for (int i = 1; i < pos-1 && temp != last ; i++)
    {
        temp = temp->next;
    }

    csl *nw = (csl *)malloc(sizeof(csl));
    printf("Enter Data: ");
    scanf("%d", &nw->data);

    nw->next = temp->next;
    temp->next = nw;

    if(temp == last)
    {
        last = nw;
    }

    return last;
}





int main()
{
    csl* last = NULL;
    last = create(last);
    display(last);

    printf("Enter Postion :");
    int pos;
    scanf("%d", &pos);
    last = ins_pos(last, pos);    
    display(last);
}
