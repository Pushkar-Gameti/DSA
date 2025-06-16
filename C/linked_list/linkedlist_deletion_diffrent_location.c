/*
 * This program implements a singly linked list in C.
 * It provides functionalities to insert and delete nodes at the beginning, middle, and end,
 * as well as display the contents of the list.
 */

#include <stdio.h>
#include <stdlib.h>

// Definition of node structure
typedef struct linkednode {
    int data;
    struct linkednode *next;
} node;

node *start = NULL, *temp = NULL, *last = NULL;
int count = 0;

// Function declarations
void createNode();
void insertFirst();
void insertMid();
void insertLast();
void deleteFirst();
void deleteMid();
void deleteLast();
void display();

// Function to create a new node
void createNode() {
    temp = (node *)malloc(sizeof(node));  // Allocate memory for node
    printf("Enter new element: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    count++;  // Increase node count
}

// Function to delete the first node
void deleteFirst() {
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        temp = start;
        start = start->next;
        free(temp);
        temp = NULL;
        count--;
    }
}

// Function to delete a node at a specific position (middle)
void deleteMid() {
    int node_no;
    node *p;

    if (start == NULL)
        printf("\nList is empty.\n");
    else {
        printf("\nEnter node number to delete: ");
        scanf("%d", &node_no);

        if (count < node_no || node_no < 1)
            printf("\nNo such node exists.\n");
        else {
            temp = start;
            for (int i = 1; i < node_no; i++) {
                p = temp;
                temp = temp->next;
            }
            p->next = temp->next;
            free(temp);
            temp = NULL;
            count--;
        }
    }
}

// Function to delete the last node
void deleteLast() {
    if (start == NULL)
        printf("\nList is empty\n");
    else if (start == last) {
        free(last);
        start = NULL;
        last = NULL;
        count--;
    } else {
        temp = start;
        while (temp->next != last)
            temp = temp->next;
        temp->next = NULL;
        free(last);
        last = temp;
        count--;
    }
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

// Main menu-driven driver function
int main() {
    int ch;
    while (1) {
        printf("\n1: insertFirst\n2: insertMid\n3: insertLast\n4: deleteFirst\n5: deleteMid\n6: deleteLast\n7: display\n8: exit\nEnter choice: ");
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
                deleteFirst();
                break;
            case 5:
                deleteMid();
                break;
            case 6:
                deleteLast();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid input\n");
        }
    }
    return 0;
}
