def is_balanced(expr):
    stack = []

    for ch in expr:
        if ch == '(':
            stack.append(ch)
        elif ch == ')':
            if not stack:
                return False
            stack.pop()

    return len(stack) == 0

expr = "((()))"
print("Balanced" if is_balanced(expr) else "Not Balanced")
