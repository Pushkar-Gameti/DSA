/*
Q: Write a C program to convert an infix expression to postfix notation using a stack. The expression may include +, -, *, /, ^, and parentheses ().
*/
#include <stdio.h>
#include <ctype.h>

int top = -1;               // Stack top pointer
char stack[50];             // Stack to hold operators and parentheses

// Function declarations
int precedence(char);       // To determine operator precedence
void push(char);            // Push operator to stack
char pop();                 // Pop operator from stack

int main() {
    char str[20], x;
    
    printf("Enter infix expression: ");
    gets(str);  // Taking input expression from user (e.g., a+b*c)

    // Loop through each character in the infix expression
    for (int i = 0; str[i] != '\0'; i++) {

        // If the character is an operand (alphabet), print it
        if (isalpha(str[i])) {
            printf("%c", str[i]);
        }

        // If it's an opening parenthesis, push it onto the stack
        else if (str[i] == '(') {
            push(str[i]);
        }

        // If it's a closing parenthesis, pop and print until '(' is found
        else if (str[i] == ')') {
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        }

        // If it's an operator (+, -, *, /, ^)
        else {
            // Pop and print all operators with higher or equal precedence
            while (precedence(stack[top]) >= precedence(str[i])) {
                printf("%c", pop());
            }
            // Push current operator to stack
            push(str[i]);
        }
    }

    // Pop and print any remaining operators in the stack
    while (top > -1) {
        printf("%c", pop());
    }

    return 0;
}

// Function to return precedence level of operators
int precedence(char symbol) {
    if (symbol == '^')
        return 3;   // Highest precedence
    else if (symbol == '*' || symbol == '/')
        return 2;
    else if (symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;   // For '(' or invalid characters
}

// Function to push character onto stack
void push(char item) {
    stack[++top] = item;
}

// Function to pop character from stack
char pop() {
    return stack[top--];
}
