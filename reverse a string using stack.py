# Function to reverse a string using a stack
def reverse_string(input_string):
    # Initialize an empty stack
    stack = []

    # Push all characters of the string onto the stack
    for char in input_string:
        stack.append(char)

    # Pop characters from the stack to form the reversed string
    reversed_string = ''
    while stack:
        reversed_string += stack.pop()

    return reversed_string

# Example usage
input_str = "Hello, World!"
reversed_str = reverse_string(input_str)
print(f"Original String: {input_str}")
print(f"Reversed String: {reversed_str}")
