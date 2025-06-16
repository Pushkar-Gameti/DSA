/*
    Program: Using Void Pointers in C
    Question: Demonstrates how to assign and dereference different types (int, float) using a void pointer.
    Improvements:
    - Corrects the use of format specifiers for pointer and data type printing.
    - Provides clearer output formatting.
*/

#include <stdio.h>

int main() {
    void *p;
    int a = 10;
    float b = 10.1f;

    // Point to integer and print
    p = &a;
    printf("Address of a is: %p\n", (void *)p);        
    printf("Value of a is: %d\n", *(int *)p);          

    // Point to float and print
    p = &b;
    printf("Address of b is: %p\n", (void *)p);        
    printf("Value of b is: %.2f\n", *(float *)p);      

    return 0;
}
