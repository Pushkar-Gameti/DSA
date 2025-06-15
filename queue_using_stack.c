#include <stdio.h>
#include <stdlib.h>
#define MAX 50

// Stack arrays and their top pointers
int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

// Function prototypes
void push1(int);
int pop1();
void push2(int);
int pop2();
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

// Function to enqueue an element using stack1
void enqueue() {
    int num;
    if (top1 == MAX - 1) {
        printf("\nOverflow\n");  // stack1 is full
    } else {
        printf("\nEnter new element: ");
        scanf("%d", &num);
        push1(num);
    }
}

// Function to dequeue an element (simulate queue behavior using two stacks)
void dequeue() {
    int x;
    if (top1 == -1)
        printf("\nUnderflow\n");  // Queue is empty
    else {
        // Transfer all elements from stack1 to stack2
        while (top1 > -1) {
            x = pop1();
            push2(x);
        }

        // Pop the element to be dequeued
        printf("\n%d is deleted\n", pop2());

        // Transfer the remaining elements back to stack1
        while (top2 > -1) {
            x = pop2();
            push1(x);
        }
    }
}

// Function to display elements of the queue (as stored in stack1)
void display() {
    if (top1 == -1)
        printf("\nUnderflow\n");  // Queue is empty
    else {
        for (int i = 0; i <= top1; i++)
            printf("%d ", stack1[i]);
        printf("\n");
    }
}

// Push to stack1
void push1(int x) {
    stack1[++top1] = x;
}

// Pop from stack1
int pop1() {
    return stack1[top1--];
}

// Push to stack2
void push2(int x) {
    stack2[++top2] = x;
}

// Pop from stack2
int pop2() {
    return stack2[top2--];
}
