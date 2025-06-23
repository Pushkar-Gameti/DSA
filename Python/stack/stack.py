stack = []
MAX_SIZE = 50

def push():
    if len(stack) >= MAX_SIZE:
        print("Overflow")
    else:
        value = int(input("Enter the new element: "))
        stack.append(value)

def pop():
    if not stack:
        print("Underflow")
    else:
        print("Popped element:", stack.pop())

def peek():
    if not stack:
        print("Underflow")
    else:
        print(stack[-1], "is on top")

def display():
    if not stack:
        print("Underflow")
    else:
        print("Stack elements (top to bottom):", *reversed(stack))

# Menu-driven logic without main()
while True:
    print("\n1: Push\n2: Pop\n3: Peek\n4: Display\n5: Exit")
    ch = int(input("Choose one option: "))
    
    if ch == 1:
        push()
    elif ch == 2:
        pop()
    elif ch == 3:
        peek()
    elif ch == 4:
        display()
    elif ch == 5:
        exit()
    else:
        print("Invalid input, please enter a valid option.")
