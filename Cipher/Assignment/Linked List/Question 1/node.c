#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int rollno;
    int standard;
    char division[10];
};

int main() {
    struct Student *s;

    // Allocate memory for one student node
    s = (struct Student*) malloc(sizeof(struct Student));

    // Take input
    printf("Enter Name: ");
    scanf("%s", s->name);

    printf("Enter Roll Number: ");
    scanf("%d", &s->rollno);

    printf("Enter Standard: ");
    scanf("%d", &s->standard);

    printf("Enter Division: ");
    scanf("%s", s->division);

    // Display Data
    printf("\n----- Student Details -----\n");
    printf("Name     : %s\n", s->name);
    printf("Roll No  : %d\n", s->rollno);
    printf("Standard : %d\n", s->standard);
    printf("Division : %s\n", s->division);

    // Free allocated memory
    free(s);

    return 0;
}
