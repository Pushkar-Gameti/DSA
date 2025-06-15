/*
 * This program defines a `student` structure with fields for roll number and name.
 * It demonstrates the use of structure pointers by using a pointer to access and 
 * manipulate the structure fields. It reads and prints a student's data.
 */
#include <stdio.h>
#include <stdlib.h>

// Define the structure for student
struct student {
    int rnum;          // Roll number
    char name[30];     // Name (max 29 characters + null terminator)
};

int main() {
    struct student a, *p;  // Declare a structure and a pointer to it
    p = &a;                // Assign the address of 'a' to pointer 'p'

    printf("Enter roll number:\n");

    // Input roll number using structure pointer
    scanf("%d", &p->rnum);

    // Flush input buffer (not portable or recommended)
    fflush(stdin);

    // Input name using gets() — this is unsafe
    gets(p->name);

    // Print the student details using pointer
    printf("\nRoll: %d\nName: %s\n", p->rnum, p->name);

    return 0;
}
