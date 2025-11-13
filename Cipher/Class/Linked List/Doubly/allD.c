#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dll
{
    int id;
    struct dll *prev;
    struct dll *next;
}dll;


dll* create(dll *head);
void display(dll *head);
void reverse_display(dll *head);
dll* ins_start(dll *head);
void ins_end(dll *head);

int main()
{
    dll *s = NULL;
    
    s = create(s);

    int ch;
    
    do
    {

      printf("------------Menu--------------\n");
      printf("Enter Your Choice \n");
      printf("1 . Display \n");
      printf("2 . Reverse Display \n");
      printf("3 . Insert Head \n");
      printf("4 . Insert End \n");

      printf("Enter Your Choice : ");
      scanf("%d" , &ch);

      switch (ch)
    
        {    
            case 1 : display(s);   
            break;

            case 2 : reverse_display(s);
            break;

            case 3 : s = ins_start(s);
            break;

            case 4 : ins_end(s);
            break;
        }

    }while(ch!=0);
}

dll* create(dll *head)
{
    int n;
    dll *new , *prev;

    do
    {
    
    new = (dll*)malloc(sizeof(dll));    
    printf("Enter ID For Node\n");
    scanf("%d" , &new->id);

    new->prev = NULL;
    new->next = NULL;

    if(head == NULL)
    {
        // new->prev = head; 
        head = new;
    }
    else
    {
        new ->prev = prev;
        prev->next = new;   
    }
    prev = new;
    
    printf("Do you want to enter a new node (0/1) \t");

    scanf("%d" , &n);

    }while(n == 1);

    return head;
}

void display(dll *head)
{
    while(head != NULL)
    {
        printf("ID is\t%d\n" , head->id);
        head = head->next;
    }
}

void reverse_display(dll *head)
{
    while(head->next != NULL)
    {
        head = head->next;
    }
    
    while(head != NULL)
    {
        printf("ID is\t%d\n" , head->id);
        head = head->prev;
    }
    
}


dll* ins_start(dll *head)
{
    dll *new;

    new = (dll*)malloc(sizeof(dll));    
    printf("Enter ID For Node\n");
    scanf("%d" , &new->id);


    head->prev = new;
    new->prev = NULL;
    new->next = head;
    head = new;

    return head;
}


void ins_end(dll *head)
{
    dll *new;

    new = (dll*)malloc(sizeof(dll));    
    printf("Enter ID For Node\n");
    scanf("%d" , &new->id);

    while(head->next !=NULL)
    {
        head = head->next;
    }

    head->next = new;
    new->prev = head;
    new ->next = NULL;
}

