#define MAX 100
int stk1[MAX];
int stk2[MAX];
int top1 = -1;
int top2 = -1;

#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void push1(int data)
{
    if(top1 == MAX - 1)
    {
        printf("Stack is Full\n");
        return;
    }
    
    stk1[++top1] = data;
}

void push2(int data)
{
    if(top2 == MAX - 1)
    {
        printf("Stack is Full\n");
        return;
    }
    
    stk2[++top2] = data;
}

void pop1()
{
    if(top1 == -1)
    {
        printf("Stack is Empty\n");
        return;
    }
    return(stk1[top1--]);
}

void pop2()
{
    if(top2 == -1)
    {
        printf("Stack is Empty\n");
        return;
    }
    return(stk2[top2--]);
}





void display()
{
    for(int i = top ; i >= 0 ; i-- )
    {
        printf("| %d |\n" , stk[i]);
    }
    printf("\n");
}


void enq(int data)
{
    push1(data);
    push2(pop1());

}