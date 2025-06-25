#include <stdio.h>
#include <string.h>

// Function to print string in reverse using recursion
void printRev(char str[], int idx) {
    if (idx < 0) return;  // Base case
    printf("%c", str[idx]);
    printRev(str, idx - 1);
}

int main() {
    char str[] = "abcd";
    int n = strlen(str);  // Get length of string

    printf("Original string: %s\n", str);
    printf("Reversed string: ");
    printRev(str, n - 1);  // Start from last character
    printf("\n");

    return 0;
}
