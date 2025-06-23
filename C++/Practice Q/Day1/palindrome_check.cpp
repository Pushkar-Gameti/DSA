#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s = "madam";
    string rev = s;
    reverse(rev.begin(), rev.end());

    if (s == rev)
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";

    return 0;
}