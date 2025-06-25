/*
  This program sorts an array using Merge Sort algorithm.
  It uses divide-and-conquer strategy to recursively sort and merge.
*/

#include <stdio.h>

void merge(int arr[], int start, int mid, int end) {
    int i = start, j = mid + 1;
    int temp[end - start + 1]; // Temporary array for merging
    int k = 0;

    // Merge elements from both halves
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements from left half
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from right half
    while (j <= end) {
        temp[k++] = arr[j++];
    }

    // Copy merged elements back to original array
    for (int l = 0; l < (end - start + 1); l++) {
        arr[start + l] = temp[l];
    }
}

void mergesort(int arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        mergesort(arr, start, mid);      // Sort left half
        mergesort(arr, mid + 1, end);    // Sort right half

        merge(arr, start, mid, end);     // Merge both halves
    }
}

int main() {
    int arr[] = {12, 31, 35, 8, 32, 17};
    int n = 6;

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    mergesort(arr, 0, n - 1);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
