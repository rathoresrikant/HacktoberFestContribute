def reverse_string_using_stack(input_string):
    stack = []
    
    for char in input_string:
        stack.append(char)
    
    reversed_string = ''
    while stack:
        reversed_string += stack.pop()
    
    return reversed_string

# Example usage
if __name__ == "__main__":
    input_str = "Hello, World!"
    reversed_str = reverse_string_using_stack(input_str)
    print("Original string:", input_str)
    print("Reversed string:", reversed_str)
