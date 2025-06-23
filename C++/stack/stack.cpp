#include <iostream>
#include <cstdlib> // for exit()
using namespace std;

int stack[50];
int top = -1;

void push()
{
    if (top == 49)
        cout << "\nOverflow\n";
    else
    {
        top++;
        cout << "Enter the new element: ";
        cin >> stack[top];
    }
}

void pop()
{
    if (top == -1)
        cout << "\nUnderflow\n";
    else
    {
        cout << "Popped element: " << stack[top] << endl;
        top--;
    }
}

void peek()
{
    if (top == -1)
        cout << "\nUnderflow\n";
    else
        cout << stack[top] << " is on top\n";
}

void display()
{
    if (top == -1)
        cout << "\nUnderflow\n";
    else
    {
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int ch;
    while (true)
    {
        cout << "\n1: Push\n2: Pop\n3: Peek\n4: Display\n5: Exit\nChoose one option: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid input\n";
        }
    }
    return 0;
}
