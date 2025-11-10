#include<stdio.h>
#include<stdlib.h>
#include <string.h>


typedef struct Student
{
    char Name[50];
    int rollno;
    struct Student *next;
}std;


std* create (std *h);

std* swap (std *h);

void display(std *head);

int main(void)
{
    std *start = NULL;
    start = create(start);

    printf("Before Swap is used \n");
    display(start);

    start = swap(start);
    printf("After Swap is Used \n");
    display(start);

}


std* create(std *head)
{
    int ans;
    std *new , *last;
    
    do
    {
        new = (std*) malloc(sizeof(std));
        printf("%s" , "Enter Name : ");
        scanf("%s" , new->Name);
        printf("%s" , "Enter Roll No : ");
        scanf("%d" , &new->rollno);
        
        new->next = NULL;

        if(head == NULL)
        {
            head = new;    
        }
        else
        {
            last ->next = new;            
        }

        last = new;
    
        printf("Do you want to add new node (0/1) ");
        scanf("%d" , &ans);

    }while(ans == 1);

    return head;

}


std* swap (std *head)
{
    if(head == NULL || head->next == NULL)
    {return head;}
    

    std *a = head;
    std *b = head->next;
    std temp;
    
    while(a != NULL && b != NULL)
    {
        temp.rollno = a ->rollno;
        a->rollno = b->rollno;
        b->rollno = temp.rollno;
      
        strcpy(temp.Name , a->Name);
        strcpy(a->Name , b->Name); 
        strcpy(b->Name , temp.Name);
        
        a  = b->next;
       if (a != NULL)
        {b = a->next;}
    }

    return head;
}


void display(std *head)
{
    std *p = head;
    while(p != NULL)
    {
        printf("Name: %s  Roll: %d\n", p->Name, p->rollno);
        p = p->next;
    }
}


