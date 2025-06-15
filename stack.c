#include <stdio.h>
#include <process.h>  // For exit() function (optional, stdlib.h is enough)
#include <stdlib.h>

// Declare stack array and top pointer globally
int stack[50];  // Stack of max size 50
int top = -1;   // Initially stack is empty

// Declare function prototypes
void push();
void pop();
void peek();
void display();

int main() {
    int ch;  // Variable to store user's choice

    // Infinite loop to show menu again and again
    while (1) {
        // Display menu options
        printf("\n1: Push\n2: Pop\n3: Peek\n4: Display\n5: Exit\nChoose one option: ");
        scanf("%d", &ch);  // Take user input

        // Perform operation based on user choice
        switch (ch) {
            case 1:
                push();     // Add new element to stack
                break;
            case 2:
                pop();      // Remove top element
                break;
            case 3:
                peek();     // Show top element
                break;
            case 4:
                display();  // Show all elements
                break;
            case 5:
                exit(0);    // Exit the program
            default:
                printf("Invalid input, please enter valid input");
                // Avoid calling main() recursively; it causes stack overflow
                break;
        }
    }

    return 0;
}

// Push function: adds element to top of stack
void push() {
    if (top == 49)  // Check if stack is full
        printf("\nOverflow\n");
    else {
        top++;  // Increment top
        printf("Enter the new element: ");
        scanf("%d", &stack[top]);  // Take input and insert at top
    }
}

// Pop function: removes element from top of stack
void pop() {
    if (top == -1)  // If stack is empty
        printf("\nUnderflow\n");
    else {
        printf("Popped element: %d\n", stack[top]);  // Show element to be removed
        top--;  // Decrement top
    }
}

// Peek function: shows top element without removing
void peek() {
    if (top == -1)
        printf("\nUnderflow\n");
    else {
        printf("%d is on top\n", stack[top]);
    }
}

// Display function: shows all elements in stack from top to bottom
void display() {
    int i;
    if (top == -1)
        printf("\nUnderflow\n");
    else {
        printf("Stack elements (top to bottom): ");
        for (i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
    }
}