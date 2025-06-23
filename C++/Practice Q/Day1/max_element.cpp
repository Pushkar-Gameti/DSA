#include <iostream>
using namespace std;

int main() {
    int arr[] = {3, 7, 2, 9, 5};
    int n = 5, max = arr[0];

    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    cout << "Max: " << max;
    return 0;
}