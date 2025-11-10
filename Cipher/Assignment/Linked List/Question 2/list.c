#include <stdio.h>
#include <stdlib.h>


typedef struct Student
{
    char Name[50];
    int rollno;
    int std;
    char Div[10];
    struct Student *next;
}std;

std* create (std *h);

void display (std *h);

int main(void)
{

    std *head = NULL;

    head = create(head);
    display(head);

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
        printf("%s" , "Enter Std : ");
        scanf("%d" , &new->std);
        printf("Enter Division :");
        scanf("%s" , new->Div);
        
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

void display (std *h)
{
    std *curr = h;
    
    while(curr != NULL)
    {
        printf("Name -> %s \n" , curr->Name);
        printf("Std ->  %d \n" , curr->std);
        printf("Division -> %s \n" , curr->Div);
        printf("RollNo -> %d \n" , curr->rollno);
        curr = curr ->next;
    }
    
}