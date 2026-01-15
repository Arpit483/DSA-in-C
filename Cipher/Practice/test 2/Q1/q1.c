// Stack using array

#define MAX 4
int stk[MAX];
int top = -1;

#include<stdio.h>


void push(int data)
{
    if(top == MAX - 1)
    {
        printf("Stack is Full\n");
        return;
    }
    
    stk[++top] = data;
    printf("Element Pushed: %d\n" , stk[top]);
}

void pop()
{
    if(top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("Element Popped: %d\n", stk[top--]);
}

void display()
{
    for(int i = top ; i >= 0 ; i-- )
    {
        printf("| %d |\n" , stk[i]);
    }
    printf("\n");
}

void peek()
{
    printf("Element Peeked: %d\n" , stk[top]);
    
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    peek();
    display();
    pop();
    pop();
    peek();
    display();
    pop();
    pop();
    pop();

    
}