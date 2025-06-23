# Ye program 5 integers user se leta hai aur fir unhe print karta hai

print("Enter 5 integers:")
a = [0] * 5  # 5 elements ki list banayi

for i in range(5):
    a[i] = int(input(f"Element {i+1}: "))

print("The entered integers are:")
for i in range(5):
    print(a[i], end=' ')

print()  # Clean output ke liye new line
