#include <stdio.h>

/*
    Program: Bubble Sort with Pass-wise Output
    This program sorts a static array of integers using Bubble Sort and displays the array after each pass.
*/

int main() {
    int list[10] = {23,12,42,21,7,32}; // Array of elements
    int n = 6, i, j, k, temp;

    // Outer loop for passes
    for (i = 0; i < n - 1; i++) {
        // Inner loop for comparisons
        for (j = 0; j < n - 1 - i; j++) {
            if (list[j] > list[j + 1]) {
                // Swap if elements are in the wrong order
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }

        // Print array after each pass
        printf("\nPass %d: ", i + 1);
        for (k = 0; k < n; k++) {
            printf("%d ", list[k]);
        }
    }

    // Final sorted output
    printf("\nFinal Sorted list is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }

    return 0;
}
