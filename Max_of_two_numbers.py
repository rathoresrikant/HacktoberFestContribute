def max_of_two(a, b):
    return a ^ ((a ^ b) & -(a < b))

# Get input from the user
a = int(input("Enter the first number: "))
b = int(input("Enter the second number: "))

print("Max of two numbers is:", max_of_two(a, b))