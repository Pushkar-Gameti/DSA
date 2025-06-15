#include <stdio.h>
#include <process.h>   // For exit()
#include <stdlib.h>    // For general utility functions

// Function declarations
int push(int[], int);          // Push element and return new top
int pop(int[], int);           // Pop element and return new top
void peek(int[], int);         // View top element
void display(int[], int);      // Display entire stack

int main() {
    int stack[50], top = -1;   // Stack array and top initialized to -1
    int ch, ele;               // ch = choice input by user

    // Infinite loop to keep menu running
    while (1) {
        printf("\n1: Push\n2: Pop\n3: Peek\n4: Display\n5: Exit\nChoose one option: ");
        scanf("%d", &ch);   // Take user choice

        switch (ch) {
            case 1:
                top = push(stack, top);    // Update top after push
                break;
            case 2:
                top = pop(stack, top);     // Update top after pop
                break;
            case 3:
                peek(stack, top);          // Just view top element
                break;
            case 4:
                display(stack, top);       // Show stack contents
                break;
            case 5:
                exit(0);                   // Exit program
            default:
                printf("Invalid input, please enter valid input");
                // Don't call main() again — it's a bad practice.
                break;
        }
    }

    return 0;
}

// Function to push element to stack
int push(int stack[], int top) {
    if (top == 49)  // Max size of stack is 50 (0–49)
        printf("\nOverflow\n");
    else {
        top++;  // Increase top pointer
        printf("Enter the new element: ");
        scanf("%d", &stack[top]);  // Add element at new top
    }
    return top;
}

// Function to pop element from stack
int pop(int stack[], int top) {
    if (top == -1)  // Stack is empty
        printf("\nUnderflow\n");
    else {
        printf("Popped element: %d", stack[top]);
        top--;  // Remove top element
    }
    return top;
}

// Function to view top element without removing
void peek(int stack[], int top) {
    if (top == -1)
        printf("\nUnderflow\n");
    else
        printf("%d is on top", stack[top]);
}

// Function to display all stack elements
void display(int stack[], int top) {
    int i;
    if (top == -1)
        printf("\nUnderflow\n");
    else {
        printf("Stack elements: ");
        for (i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
    }
}