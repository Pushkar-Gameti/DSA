/*
 * This program defines a structure `student` to store a student's roll number and name.
 * It takes user input for both fields and then displays the entered information.
 */
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store student details
struct student {
    int rnum;          // Roll number
    char name[30];     // Name (max 29 characters + null terminator)
};

int main() {
    struct student a;

    // Prompt the user to enter roll number and name
    printf("Enter roll number and name of student:\n");

    // Input roll number
    scanf("%d", &a.rnum);

    // Clear input buffer (not reliable across platforms)
    fflush(stdin);

    // Input name (unsafe function usage)
    gets(a.name);

    // Output the entered data
    printf("\nRoll Number: %d\nName: %s\n", a.rnum, a.name);

    return 0;
}
