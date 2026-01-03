#include <stdio.h>

struct Student
{
    int roll;
    char name[20];
    float marks;
};


void searchStudent(struct Student *s, int n, int searchRoll);

int main()
{
    struct Student s[50];
    int n, i, searchRoll;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of Student %d\n", i + 1);

        printf("Roll No: ");
        scanf("%d", &(s + i)->roll);

        printf("Name: ");
        scanf("%s", (s + i)->name);

        printf("Marks: ");
        scanf("%f", &(s + i)->marks);
    }

    
    printf("\nEnter Roll No to search: ");
    scanf("%d", &searchRoll);

    
    searchStudent(s, n, searchRoll);

    return 0;
}

void searchStudent(struct Student *s, int n, int searchRoll)
{
    int i, found = 0;

    for (i = 0; i < n; i++)
    {
        if ((s + i)->roll == searchRoll)
        {
            printf("\n--- Student Found ---\n");
            printf("Roll No: %d\n", (s + i)->roll);
            printf("Name: %s\n", (s + i)->name);
            printf("Marks: %.2f\n", (s + i)->marks);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent with Roll No %d not found.\n", searchRoll);
    }
}
