#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    reverse(arr, arr + n);  // STL function

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}