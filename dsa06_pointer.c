/*
    Program: Typed Pointer Demonstration in C
    Question: Illustrate how to use `int *` and `float *` to access memory addresses and values.
    Features:
    - Uses typed pointers for type safety.
    - Proper formatting for pointer and value printing.
*/

#include <stdio.h>

int main() {
    int a = 10;
    float b = 10.1f;

    // Declare typed pointers
    int *ptrInt = &a;
    float *ptrFloat = &b;

    // Print address and value of integer
    printf("Address of 'a' is: %p\n", (void *)ptrInt);
    printf("Value of 'a' is: %d\n", *ptrInt);

    // Print address and value of float
    printf("Address of 'b' is: %p\n", (void *)ptrFloat);
    printf("Value of 'b' is: %.2f\n", *ptrFloat);

    return 0;
}
