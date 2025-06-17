/*
    Circular Queue Using Linked List in C

    This program implements a circular queue using a singly linked list.
    It supports enqueue (insertion), dequeue (deletion), and display operations.
    The 'last' pointer points to the rear of the queue, and last->next points to the front.
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for the circular queue
typedef struct linkednode {
    int data;
    struct linkednode *next;
} node;

node *last = NULL, *temp = NULL;  // Global pointers

// Function to insert an element into the queue
void enqueue() {
    temp = (node*)malloc(sizeof(node));
    printf("\nEnter the element: ");
    scanf("%d", &temp->data);

    if (last == NULL) {
        // First element case
        last = temp;
        last->next = temp;  // Circular link to itself
    } else {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
    printf("Element %d enqueued successfully.\n", temp->data);
}

// Function to remove an element from the queue
void dequeue() {
    if (last == NULL) {
        printf("\nQueue is empty. Cannot dequeue.\n");
    }
    else if (last->next == last) {  // Only one element
        printf("Element %d dequeued.\n", last->data);
        free(last);
        last = NULL;
    } else {
        temp = last->next;
        printf("Element %d dequeued.\n", temp->data);
        last->next = temp->next;
        free(temp);
        temp = NULL;
    }
}

// Function to display the queue
void display() {
    if (last == NULL) {
        printf("\nQueue is empty.\n");
    } else {
        temp = last->next;
        printf("\nQueue elements: ");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != last->next);
        printf("\n");
    }
}

int main() {
    int ch;  // User's menu choice

    // Menu-driven program
    while (1) {
        printf("\n========== Circular Queue Menu ==========\n");
        printf("1: Enqueue\n2: Dequeue\n3: Display\n4: Exit\n");
        printf("Choose one option: ");
        scanf("%d", &ch);

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
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid input. Please choose a valid option.\n");
                break;
        }
    }

    return 0;
}
