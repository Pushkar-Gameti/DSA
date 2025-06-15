/*
 * This program reads 5 integers from the user using pointer arithmetic,
 * and then prints the entered values.
 */
#include <stdio.h>

int main() {
    // Declare an array of 5 integers and a pointer to int
    int a[5], *ptr;
    
    // Set the pointer to the address of the first element of the array
    ptr = a; // Equivalent to: ptr = &a[0];

    // Read 5 integers from user input
    printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", (ptr + i));  // Pointer arithmetic to access each array element
    }

    // Print the entered integers
    printf("The entered integers are:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n"); // Add newline for cleaner output

    return 0;
}
