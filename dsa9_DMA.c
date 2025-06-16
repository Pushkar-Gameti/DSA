#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;

    // Read the number of elements from the user
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    // Dynamically allocate memory for 'n' integers
    int *p = (int *)malloc(n * sizeof(int));

    // Read 'n' integers into the allocated memory
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", (p + i));
    }

    // Print the entered integers
    printf("The entered integers are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n"); // Better output formatting
    free(p);
    return 0;
}

// /*
//  * This program dynamically allocates memory based on user input (number of integers),
//  * reads integers into the allocated memory using pointer arithmetic,
//  * and prints them. This improved version includes safety checks and better formatting.
//  */

// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int n;

//     // Prompt user for the number of integers
//     printf("Enter the number of integers: ");
//     if (scanf("%d", &n) != 1 || n <= 0) {
//         fprintf(stderr, "Invalid input. Please enter a positive integer.\n");
//         return 1;
//     }

//     // Allocate memory dynamically
//     int *p = (int *)malloc(n * sizeof(int));
//     if (p == NULL) {
//         fprintf(stderr, "Memory allocation failed.\n");
//         return 1;
//     }

//     // Input values
//     printf("Enter %d integers:\n", n);
//     for (int i = 0; i < n; i++) {
//         printf("Element %d: ", i + 1);
//         if (scanf("%d", p + i) != 1) {
//             fprintf(stderr, "Invalid input. Please enter integers only.\n");
//             free(p);
//             return 1;
//         }
//     }

//     // Output values
//     printf("\nYou entered:\n");
//     for (int i = 0; i < n; i++) {
//         printf("Element %d: %d\n", i + 1, *(p + i));
//     }

//     // Free dynamically allocated memory
//     free(p);

//     return 0;
// }
