/*
 * This program defines a `student` structure with roll number and name fields.
 * It collects data for 3 students from user input and then prints the entered details.
 */
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store student data
struct student {
    int rnum;         // Roll number
    char name[30];    // Student's name
};

int main() {
    struct student s[3]; // Array to store data of 3 students
    int i;

    // Input loop for student data
    for (i = 0; i < 3; i++) {
        printf("\nEnter roll number and name for student %d:\n", i + 1);

        // Input roll number
        scanf("%d", &s[i].rnum);

        // Clear the input buffer (not reliable across platforms)
        fflush(stdin);

        // Input name using gets (unsafe)
        gets(s[i].name);
    }

    // Output the collected student data
    printf("\nStudent Details:\n");
    for (i = 0; i < 3; i++) {
        printf("\nRoll Number: %d\nName: %s\n", s[i].rnum, s[i].name);
    }

    return 0;
}
