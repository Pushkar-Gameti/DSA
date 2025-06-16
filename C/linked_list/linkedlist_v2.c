#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
typedef struct linkednode {
    int data;
    struct linkednode *next;
} node;

// Global pointers for temporary use, start of the list, and last node
node *temp, *start, *last;

// Function to create a new node and read data from user
void createNode() {
    temp = (node*)malloc(sizeof(node));  // Allocate memory for new node
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter new element: ");
    scanf("%d", &temp->data);
    temp->next = NULL;  // New node initially points to NULL
}

// Function to display the contents of the linked list
void display() {
    if (start == NULL) {
        printf("\nList is empty (Underflow).\n");
    } else {
        printf("\nLinked List Elements: ");
        temp = start;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int no, i;
    printf("Enter number of nodes: ");
    scanf("%d", &no);

    for (i = 0; i < no; i++) {
        createNode();  // Create a new node
        if (start == NULL) {
            // First node case
            start = temp;
            last = temp;
        } else {
            // Append new node at the end
            last->next = temp;
            last = temp;
        }
    }

    display();  // Display all node values
    return 0;
}
