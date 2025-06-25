#include <stdio.h>
#include <string.h>

// Recursive function to find first and last occurrence of a character
void findOccurrence(char str[], int idx, char element) {
    static int first = -1;
    static int last = -1;

    // Base case
    if (idx == strlen(str)) {
        printf("\nFirst occurrence of '%c' is at index: %d", element, first);
        printf("\nLast occurrence of '%c' is at index: %d\n", element, last);
        return;
    }

    if (str[idx] == element) {
        if (first == -1) {
            first = idx;  // First time match
        }
        last = idx;  // Keep updating last on every match
    }

    findOccurrence(str, idx + 1, element);
}

int main() {
    char str[] = "abaacdaefaah";
    char element = 'a';

    printf("String: %s\n", str);
    findOccurrence(str, 0, element);

    return 0;
}
