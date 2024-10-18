def reverse_string_using_stack(s):
    stack = []
    
    for char in s:
        stack.append(char)
    
    reversed_str = ''
    
    while stack:
        reversed_str += stack.pop()
    
    return reversed_str

# Example usage:
s = "Hello, World!"
print("Reversed string:", reverse_string_using_stack(s))
