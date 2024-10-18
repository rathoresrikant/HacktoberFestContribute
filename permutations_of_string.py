def permutations(string, prefix=""):
    if len(string) == 0:
        print(prefix)
    else:
        for i in range(len(string)):
            permutations(string[:i] + string[i+1:], prefix + string[i])

# Example usage:
input_string = "abc"
print("All permutations of the string are:")
permutations(input_string)
