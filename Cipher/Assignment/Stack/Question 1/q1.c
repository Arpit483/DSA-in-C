#define MAX 3
int stk[MAX];
int top = -1;
#include<stdio.h>

void push(int value)
{
    if(top == MAX -1)
    {
        printf("Stack is Full\n");
        return;
    }

    stk[++top] = value;
}

int pop()
{
    if(top == -1)
    {
        printf("Stack is Empty\n");
        return -1;
    }

    return stk[--top];
}


void display()
{
    for(int i = top ; i >= 0 ; i-- )
    {
        printf("%d  " , stk[i]);
    }
    printf("\n");
}


int main()
{
    push(10);
    push(20);
    push(30);

    display();

    push(40);

    
    pop();
    pop();
    display();
    pop();
    pop();
}
