// Program to implement a linear queue using array in C

#include <stdio.h>
#include <stdlib.h>

#define MAX 50             // Maximum size of the queue

int queue[MAX];            // Array to hold queue elements
int r = -1, f = -1;        // 'r' for rear, 'f' for front

// Function declarations
void enqueue();
void dequeue();
void display();

int main() {
    int ch;  // Variable to store user's choice

    // Infinite loop to show menu again and again
    while (1) {
        // Display menu options
        printf("\n1: Enqueue\n2: Dequeue\n3: Display\n4: Exit\nChoose one option: ");
        scanf("%d", &ch);  // Take user input

        // Perform operation based on user choice
        switch (ch) {
            case 1:
                enqueue();     // Add new element to queue
                break;
            case 2:
                dequeue();     // Remove front element
                break;
            case 3:
                display();     // Display queue contents
                break;
            case 4:
                exit(0);       // Exit the program
            default:
                printf("Invalid input, please enter valid input\n");
                break;
        }
    }

    return 0;
}

// Function to add element to the queue
void enqueue() {
    if (r == MAX - 1) {
        // Queue is full
        printf("\nOverflow");
    } else {
        if (f == -1) {
            // If inserting the first element
            f++;
            r++;
        } else {
            // Move rear forward for next element
            r++;
        }
        printf("\nEnter new element: ");
        scanf("%d", &queue[r]);  // Add element to rear
    }
}

// Function to remove element from the queue
void dequeue() {
    if (f == -1) {
        // Queue is empty
        printf("\nUnderflow");
    } else {
        // Print and remove the front element
        printf("%d is deleted", queue[f]);
        f++;  // Move front pointer forward

        // Reset if queue becomes empty
        if (f > r) {
            f = -1;
            r = -1;
        }
    }
}

// Function to display queue elements
void display() {
    if (f == -1) {
        // Queue is empty
        printf("\nUnderflow");
    } else {
        // Print elements from front to rear
        printf("\nQueue elements: ");
        for (int i = f; i <= r; i++) {
            printf("%d ", queue[i]);
        }
    }
}
