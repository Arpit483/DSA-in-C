#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct stkLL
{
    int data;
    struct stkLL *next;
}stkl;

bool isEmpty(stkl* top)
{
    if(!top)
    {
        return true;
    }
    return false;
}

stkl* push(stkl* top , int data)
{
    stkl* nw = (stkl*) malloc(sizeof(stkl));
    nw->data = data;
    nw->next = top;
    return nw;
}

stkl* pop(stkl* top)
{
    if(isEmpty(top))
    {   
        printf("Stack is Empty\n");    
        return NULL;
    }

    stkl* t = top->next;
    printf("Element Popped is : %d\n" , top->data);
    free(top);
    return t;
}

void display(stkl* top)
{
    stkl* temp = top;
    while(temp != NULL)
    {
        printf("| %d |\n" , temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    stkl* top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);
    top = push(top, 50);
    display(top);
    top = pop(top);
    top = pop(top);
    top = pop(top);
    top = pop(top);
    top = pop(top);
    top = pop(top);
    display(top);
}