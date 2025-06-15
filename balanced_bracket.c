#include <stdio.h>
#include <string.h>

// Stack implementation
char stack[20];
int top = -1;

// Function to push character to stack
void push(char);

// Function to pop character from stack
char pop();

int main() {
    char str[20], t;  // `str` input string, `t` temporary popped character
    int f = 1, i;     // `f` flag to track balance status

    // Taking input from user
    printf("Enter the string: ");
    gets(str);  // Unsafe in general, but acceptable for small inputs in academic settings

    // Loop through each character of string
    for (i = 0; str[i] != '\0'; i++) {

        // If opening bracket, push to stack
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(str[i]);
        }

        // If closing bracket
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {

            // If stack is empty, brackets are not balanced
            if (top == -1) {
                f = 0;
            } else {
                t = pop();  // Pop the last opening bracket

                // Check for mismatched pair
                if (str[i] == ')' && (t == '{' || t == '[')) {
                    f = 0;
                }
                if (str[i] == '}' && (t == '(' || t == '[')) {
                    f = 0;
                }
                if (str[i] == ']' && (t == '{' || t == '(')) {
                    f = 0;
                }
            }
        }
    }

    // If stack is not empty at end, then not balanced
    if (top >= 0)
        f = 0;

    // Final output
    if (f == 1) {
        printf("Balanced ");
    } else {
        printf("Not balanced");
    }

    return 0;
}

// Push function to add character to stack
void push(char a) {
    stack[++top] = a;
}

// Pop function to remove character from stack
char pop() {
    return stack[top--];
}