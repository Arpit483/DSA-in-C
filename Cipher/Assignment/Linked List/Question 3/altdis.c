#include <stdio.h>
#include <stdlib.h>

typedef struct student 
{
    int rollno;
    char Name[50];
    struct student *next;
}std;

std* create (std *head);
void alt_dis(std* head);

int main(void)
{
    std *start = NULL;

    start = create(start);
    alt_dis(start);

}


std* create (std *head)
{
    int ans;
    std *new ,*last;

    do
    {
        new = (std*) malloc(sizeof(std));
        printf("Enter Roll Number : ");
        scanf("%d" , &new->rollno);

        printf("Enter Name : " );
        scanf("%s" , new->Name );
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

        printf("Do you want to enter a new node (0/1)");
        scanf("%d" , &ans);
    }
    while(ans == 1);

    return head;
}


void alt_dis(std* head)
{
    std *curr = head;
    
    while(curr != NULL)
    {
        printf("Name : \t %s \n" , curr->Name);
        printf("Roll Number : \t  %d \n" , curr->rollno);

        curr = curr->next->next;
    }
}