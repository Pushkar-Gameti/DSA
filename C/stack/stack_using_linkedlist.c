/*
This C program implements a basic **stack** using a **linked list**.
It allows the user to perform the following operations:
1. Push: Add an element to the top of the stack.
2. Pop: Remove the top element.
3. Peek: View the top element.
4. Display: Print all elements in the stack.
5. Exit: Terminate the program.
*/

#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct linkednode {
    int data;
    struct linkednode *next;
} node;

node *top = NULL, *temp = NULL;

// Push a new element onto the stack
void push() {
    temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        printf("\nMemory allocation failed!");
        return;
    }

    printf("\nEnter new element: ");
    scanf("%d", &temp->data);

    temp->next = NULL;
    if (top == NULL)
        top = temp;
    else {
        temp->next = top;
        top = temp;
    }

    printf("Element pushed: %d\n", temp->data);
}

// Pop the top element from the stack
void pop() {
    if (top == NULL)
        printf("\nStack is empty.\n");
    else {
        temp = top;
        printf("Element popped: %d\n", temp->data);
        top = top->next;
        free(temp);
        temp = NULL;
    }
}

// Peek at the top element
void peek() {
    if (top == NULL)
        printf("\nStack is empty.\n");
    else
        printf("Top element: %d\n", top->data);
}

// Display all elements in the stack
void display() {
    if (top == NULL) {
        printf("\nStack is empty.\n");
    } else {
        printf("Stack elements: ");
        temp = top;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    int ch;

    while (1) {
        // Display menu
        printf("\n1: Push\n2: Pop\n3: Peek\n4: Display\n5: Exit\nChoose one option: ");
        scanf("%d", &ch);

        // Perform selected operation
        switch (ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid input, please enter valid input.\n");
                break;
        }
    }

    return 0;
}
