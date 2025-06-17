/*
    Queue Implementation Using Singly Linked List in C

    This program implements a queue using a singly linked list.
    It supports three main operations:
        1. Enqueue - Adding an element to the rear of the queue
        2. Dequeue - Removing an element from the front of the queue
        3. Display - Displaying all elements in the queue
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct linkednode {
    int data;
    struct linkednode *next;
} node;

// Global pointers for queue front and rear
node *temp, *rear, *front;

// Function to add an element to the queue
void enqueue() {
    temp = (node*)malloc(sizeof(node));
    printf("\nEnter the new element: ");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if (rear == NULL) {
        front = temp;
        rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

// Function to remove an element from the queue
void dequeue() {
    if (rear == NULL) {
        printf("\nQueue is empty.\n");
    } else if (front == rear) {
        printf("%d is deleted\n", front->data);
        free(front);
        front = NULL;
        rear = NULL;
    } else {
        temp = front;
        printf("%d is deleted\n", temp->data);
        front = front->next;
        free(temp);
        temp = NULL;
    }
}

// Function to display all elements in the queue
void display() {
    if (rear == NULL) {
        printf("\nQueue is empty.\n");
    } else {
        temp = front;
        printf("\nQueue elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function with menu-driven interface
int main() {
    int ch;  // Variable to store user's choice

    while (1) {
        // Display menu options
        printf("\n1: Enqueue\n2: Dequeue\n3: Display\n4: Exit\nChoose one option: ");
        scanf("%d", &ch);  // Take user input

        // Perform operation based on user choice
        switch (ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid input, please enter a valid option.\n");
        }
    }

    return 0;
}
