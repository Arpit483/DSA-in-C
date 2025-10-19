/* 

    Create a structure "Students" with below member variables:
	- Name of student,
    - Roll no. Of Student,
    - array of 5 Subject marks,
	- Total Percentage 
    
- Calculate the Percentage for "N" number of students,
- Display all details for all students,
- Display the details of topper.
(use array of structure)
*/

#include <stdio.h>

#define SUBJECTS 5

struct Student {
    char name[50];
    int rollNo;
    float marks[SUBJECTS];
    float percentage;
};

int main() {
    struct Student s[100]; 
    int n;
    int i, j;
    int topperIndex = 0;
    float total, highest = 0.0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    
    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);

        printf("Enter name: ");
        scanf("%s", s[i].name);

        printf("Enter roll number: ");
        scanf("%d", &s[i].rollNo);

        total = 0;
        printf("Enter marks of %d subjects:\n", SUBJECTS);
        
        for (j = 0; j < SUBJECTS; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%f", &s[i].marks[j]);
            total += s[i].marks[j];
        }


        s[i].percentage = total / SUBJECTS;

        
        if (s[i].percentage > highest) {
            highest = s[i].percentage;
            topperIndex = i;
        }
    }

    
    printf("\n================== Student Details ==================\n");
    printf("%-15s %-10s %-15s\n", "Name", "Roll No", "Percentage");
    printf("-----------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-15s %-10d %-15.2f\n", s[i].name, s[i].rollNo, s[i].percentage);
    }

    printf("\n================== Topper Details ==================\n");
    printf("Name       : %s\n", s[topperIndex].name);
    printf("Roll No.   : %d\n", s[topperIndex].rollNo);
    printf("Percentage : %.2f%%\n", s[topperIndex].percentage);

    return 0;
}

 
	