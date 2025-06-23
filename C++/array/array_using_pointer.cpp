#include <iostream>
using namespace std;

int main() {
    int a[5];
    int* ptr = a; // Pointer to array

    cout << "Enter 5 integers:\n";
    for (int i = 0; i < 5; i++) {
        cin >> *(ptr + i); // Pointer arithmetic
    }

    cout << "The entered integers are:\n";
    for (int i = 0; i < 5; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    return 0;
}
