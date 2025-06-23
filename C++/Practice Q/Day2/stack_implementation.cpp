#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;  // Create a stack

    s.push(10);    // Push elements
    s.push(20);

    s.pop();       // Pop top element

    cout << "Top element: " << s.top() << endl;

    return 0;
}
