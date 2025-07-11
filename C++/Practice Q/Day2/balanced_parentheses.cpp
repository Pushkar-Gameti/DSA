#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string expr) {
    stack<char> s;

    for (char ch : expr) {
        if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            if (s.empty()) return false;
            s.pop();
        }
    }

    return s.empty();
}

int main() {
    string expr = "((()))";
    cout << (isBalanced(expr) ? "Balanced" : "Not Balanced") << endl;

    return 0;
}
