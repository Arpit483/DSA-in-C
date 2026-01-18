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

csl* del_pos(csl* last, int pos)
{

    csl *p = last->next;
    
    if(pos == 1)
    {
        last->next = p->next;
        free(p);
        return last;
    }
    
    for (int i = 1; i < pos - 1 && p!= last ; i++)
    {
        p = p->next;
    }

    if(p == last)
    {
        printf("Invalid Position");
    }

    csl* temp = p->next;
    p->next = temp->next;

    if(temp == last)
        last = p;

    free(temp);
    return last;
}

int main()
{
    csl* last = NULL;
    last = create(last);
    display(last);
    last = del_pos(last, 1);
    display(last);
}
