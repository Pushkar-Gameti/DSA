/*
 * Problem Solved:
 * This program implements a singly linked list in C with insertions:
 * - at the beginning,
 * - at a specific middle position,
 * - at the end.
 * It also includes a display function and uses a menu-driven interface.
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for linked list node
typedef struct linkednode {
    int data;
    struct linkednode *next;
} node;

// Global pointers and node counter
node *temp, *start, *last;
int count = 0;

// Function prototypes
void createNode();
void insertFirst();
void insertMid();
void insertLast();
void display();

// Function to create a new node
void createNode() {
    temp = (node *)malloc(sizeof(node));  // Allocate memory for node
    printf("Enter new element: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    count++;  // Increase node count
}

// Main function with menu-driven interface
int main() {
    int ch;
    while (1) {
        printf("\n1 insertFirst\n2 insertMid\n3 insertLast\n4 display\n5 exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insertFirst();
                break;
            case 2:
                insertMid();
                break;
            case 3:
                insertLast();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid input\n");
        }
    }
    return 0;
}

// Insert node at the beginning
void insertFirst() {
    createNode();
    if (start == NULL) {
        start = temp;
        last = temp;
    } else {
        temp->next = start;
        start = temp;
    }
}

// Insert node at a specific middle position
void insertMid() {
    int position;
    node *p;
    createNode();

    if (start == NULL) {
        start = temp;
        last = temp;
    } else {
        printf("\nEnter the position: ");
        scanf("%d", &position);

        if (position == count) {
            last->next = temp;
            last = temp;
        } else if (position < count) {
            p = start;
            for (int i = 1; i < position - 1; i++) {
                p = p->next;
            }
            temp->next = p->next;
            p->next = temp;
        } else {
            printf("Invalid position\n");
        }
    }
}

// Insert node at the end
void insertLast() {
    createNode();
    if (start == NULL) {
        start = temp;
        last = temp;
    } else {
        last->next = temp;
        last = temp;
    }
}

// Display all elements of the list
void display() {
    if (start == NULL) {
        printf("\nList is empty\n");
    } else {
        temp = start;
        printf("\nLinked list elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
