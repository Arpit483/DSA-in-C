#include<stdio.h>
#include<stdlib.h>
#define MAX_S 6

int stk[MAX_S];
int top = -1;

void push(int value)
{
    if(top == MAX_S-1){
        printf("Full");
        return; 
    }
    stk[++top] = value;
}

int pop()
{
    if(top == -1)
    {
        printf("Empty");
        return -1;
    }
    return stk[top--];

}

void display(){
    if(top == -1){
        printf("Stack Empty!\n");
        return;
    }
    for (int i = top ; i >= 0 ; i--){
        printf("%d   ", stk[i]);   
    }
    printf("\n");  
}

int peek(){
    return stk[top];
}

int main()
{
push(10);
push(20);
printf("%d" , pop());
display(); 


}

