/*
  This program sorts an array of integers using the Quick Sort algorithm
  with the Lomuto partitioning scheme.
*/

#include <stdio.h>

int partition(int arr[], int start, int end) {
    int pivot = arr[end];     // Choose the last element as pivot
    int i = start - 1;        // Index for smaller elements

    for (int j = start; j < end; j++) {
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap pivot to its correct position
    i++;
    int temp = arr[end];
    arr[end] = arr[i];
    arr[i] = temp;

    return i;  // Return pivot index
}

void quickSort(int arr[], int start, int end) {
    if (start < end) {
        int pivotIndex = partition(arr, start, end);

        // Recursively sort elements before and after partition
        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}

int main() {
    int arr[] = {61,42,12,75,82,31};
    int n = 6;

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
