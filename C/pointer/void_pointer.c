// This program demonstrates how to use a void pointer to store and access 
// the address and values of both int and float variables using typecasting.

#include <stdio.h>

int main() {
    void *p;            // Declare a void pointer
    int a = 10;         // Integer variable
    float b = 10.1f;    // Float variable

    // Pointing to integer and displaying value
    p = &a;
    printf("\n[Integer Section]");
    printf("\nAddress of 'a' is: %p", (void *)p);
    printf("\nValue of 'a' is: %d", *(int *)p);

    // Pointing to float and displaying value
    p = &b;
    printf("\n\n[Float Section]");
    printf("\nAddress of 'b' is: %p", (void *)p);
    printf("\nValue of 'b' is: %.2f\n", *(float *)p);

    return 0;
}
