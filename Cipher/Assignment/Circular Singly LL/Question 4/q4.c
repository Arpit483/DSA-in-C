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

csl* ins_last (csl *last)
{
    csl *nw = (csl *)malloc(sizeof(csl));
    printf("Enter Data: ");
    scanf("%d", &nw->data);

    nw->next = last->next;
    last->next = nw;

    return nw;
}




int main()
{
    csl* last = NULL;
    last = create(last);
    display(last);

    last = ins_last(last);
    display(last);
}
