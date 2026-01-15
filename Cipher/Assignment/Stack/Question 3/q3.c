#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <stdbool.h>

typedef struct stack
{
    char data;
    struct stack *next;
} stk;

bool isEmpty(stk *top)
{
    return (top == NULL);
}

stk* push(stk *top , char c)
{
    stk *nw = (stk *)malloc(sizeof(stk));
    nw->data = c;
    nw->next = top;
    return nw;
}

stk* pop(stk *top)
{
      if(isEmpty(top))
    {   
        printf("Stack is Empty\n");    
        return NULL;
    }

    stk* t = top->next;
    free(top);
    return t;
}

void display(stk *top)
{
    stk *temp = top;
    while(temp != NULL)
    {
        printf("| %c |\n" , temp->data);
        temp = temp->next;
    }
    printf("\n");
}

stk* check(stk *top , char *str)
{

    for (int i = 0; str[i] != '\0' ; i++)
    {
        if(str[i] == '{' || str[i] == '[' ||str[i] ==  '(')
        {
            top = push(top, str[i]);
        }

        if(str[i] == '}' &&top != NULL && top->data == '{')
        {
            top = pop(top);
        }

        if(str[i] == ']' && top != NULL && top->data == '[')
        {
            top = pop(top);
        }
        if(str[i] == ')' &&  top != NULL && top->data == '(')
        {
            top = pop(top);
        }

    }

    return top;
}



int main()
{
    stk *top = NULL;
    printf("Enter Character to Check: ");
    char str[100];
    scanf("%s", str);
    top = check(top, str);
    if(isEmpty(top))
    printf("Balanced\n");
    else
    printf("Not Balanced\n");

}

