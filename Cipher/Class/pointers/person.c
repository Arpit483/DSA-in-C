#include <stdio.h>
#include <string.h>

typedef struct person 
{
    int age;
    char name[10];
}person;

int main()
{
    person p1 , p2 ;
    printf("Enter The P1 person details : \n");
    printf("Enter The P1 person age :");
    scanf("%d" , &p1.age);
    printf("Enter The Person p1 name  :");
    scanf("%s" , p1.name);

    printf("Enter The P2 person details : \n");
    printf("Enter The P2 person age :");
    scanf("%d" , &p2.age);
    printf("Enter The Person p2 name  :");
    scanf("%s" , p2.name);

    if(p1.age > p2.age)
    {
        printf("P1 Person is Elder .... \n");
        printf("Age : %d\n" , p1.age);
        printf("Name : %s\n" , p1.name);
    }
    else if (p2.age > p1.age)
    {
        printf("P2 Person is Elder .... \n");
        printf("Age : %d\n" , p2.age);
        printf("Name : %s\n" , p2.name);
    }
    else
    {
        printf("Both p1 and p2 has same age \n");
    }

    return 0;

}