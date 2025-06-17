#include <stdio.h>

/*
    Program: Selection Sort with Pass-wise Output
    Description: This program sorts an integer array using Selection Sort 
                 and prints the array after each sorting pass.
*/

int main() {
    int a[6] = {23, 12, 42, 21, 7, 32}; // Static array to be sorted
    int n = 6;
    int i, j, k, min, temp;

    // Outer loop for passes
    for (i = 0; i < n; i++) {
        min = i;

        // Inner loop to find the index of the minimum element
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }

        // Swap current element with the found minimum
        if(min!=i){
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }

        // Print array after each pass
        printf("\nPass %d: ", i + 1);
        for (k = 0; k < n; k++) {
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
