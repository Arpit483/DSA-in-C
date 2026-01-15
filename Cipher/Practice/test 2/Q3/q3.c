#define MAX 100
char stk[MAX];
int top = -1;

#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void push(char ch[1])
{
    if(top == MAX - 1)
    {
        printf("Stack is Full\n");
        return;
    }
    
    stk[++top] = ch[0];
}

void pop()
{
    if(top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }
    stk[top--];
}


bool isEmpty()
{
    if(top == -1)
    {
        return true;
    }
    return false;    
}



void display()
{
    for(int i = top ; i >= 0 ; i-- )
    {
        printf("| %c |\n" , stk[i]);
    }
    printf("\n");
}


void check(char ch , int s)
{
    
 for (int i = 0; i < s; i++)
    {
        push(ch[i]);
        
        if(stk[top] == "{" && ch[i] == "}" )
            pop();
            pop();
        
        if(stk[top] == "(" && ch[i] == ")" )
            pop();
            pop();

        if(stk[top] == "[" && ch[i] == "]" )
            pop();
            pop();

    }
 
}



int main()
{
    int s;
    printf("Enter the size of the string: ");
    scanf("%d" , &s);

    char ch[s];
    scanf("%s" , ch);
    char *e = ch;
    //printf("%c" , ch[0]);
    //printf("%s\n" , ch[0]);


    // while(e!=0)
    // {
    //     printf("%c " , e);
    // }
   

    // if(isEmpty())
    // {
    //     printf("Balanced");
    //     return 1;
    // }
    
    // printf("Unbalanced");

}



