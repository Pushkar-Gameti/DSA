#include <stdio.h>

/*
    Program: Insertion Sort with Pass-wise Output
    Description: Sorts an array using Insertion Sort and prints the array after each pass.
*/

int main() {
    int a[6] = {23, 12, 42, 21, 7, 32};
    int n = 6, i, j, key;

    for (i = 1; i < n; i++) {
        key = a[i];         // Current element to be placed
        j = i - 1;

        // Shift elements of sorted part to the right
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        // Place the key at its correct position
        a[j + 1] = key;

        // Print the array after each pass
        printf("\nPass %d: ", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", a[k]);
        }
    }

    // Final sorted output
    printf("\nFinal Sorted list is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
