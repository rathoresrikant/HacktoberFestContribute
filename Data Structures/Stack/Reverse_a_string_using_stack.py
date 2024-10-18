def reverse_string(input_string):
    stack = []
    for char in input_string:
        stack.append(char)
    reversed_string = ''
    while stack:
        reversed_string += stack.pop()
    return reversed_string

string = "Hello, World!"
reversed_str = reverse_string(string)
print(f"Original string: {string}")
print(f"Reversed string: {reversed_str}")
