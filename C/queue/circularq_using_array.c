/*
    Circular Queue Using Array in C

    This program implements a circular queue using a static array.
    It supports enqueue, dequeue, and display operations via a menu.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the circular queue

int queue[MAX];
int rear = -1, front = -1;

// Function to insert an element in the circular queue
void enqueue() {
    if (((rear + 1) % MAX) == front) {
        printf("\nQueue Overflow! Cannot enqueue more elements.\n");
    } else {
        if (front == -1) {
            rear++;
            front++;
        } else if ((rear == MAX - 1) && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        printf("\nEnter new element: ");
        scanf("%d", &queue[rear]);
        printf("Element %d inserted successfully.\n", queue[rear]);
    }
}

// Function to delete an element from the circular queue
void dequeue() {
    if (front == -1) {
        printf("\nQueue Underflow! No elements to dequeue.\n");
    } else {
        printf("Element %d is deleted from the queue.\n", queue[front]);
        if (front == rear) {
            front = rear = -1;  // Queue becomes empty
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

// Function to display all elements in the circular queue
void display() {
    int i;
    if (front == -1) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nQueue elements: ");
        i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", queue[rear]);  // Print the last element
    }
}

// Main function with menu
int main() {
    int ch;

    while (1) {
        printf("\n========== Circular Queue Menu ==========\n");
        printf("1: Enqueue\n2: Dequeue\n3: Display\n4: Exit\n");
        printf("Choose one option: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                enqueue();  // Add new element to queue
                break;
            case 2:
                dequeue();  // Remove front element
                break;
            case 3:
                display();  // Display queue contents
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid input. Please enter a valid option (1-4).\n");
                break;
        }
    }

    return 0;
}
