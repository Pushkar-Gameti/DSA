#include <stdio.h>

// Recursive function to check if array is sorted
void isSorted(int arr[], int idx, int size) {
    if (idx == size - 1) {
        printf("True\n");
        return;
    }
    if (arr[idx] < arr[idx + 1]) {
        isSorted(arr, idx + 1, size);
    } else {
        printf("False\n");
        return;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    isSorted(arr, 0, n);

    return 0;
}
