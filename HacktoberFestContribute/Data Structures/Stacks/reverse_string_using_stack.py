string = raw_input()  # Original string
stack = []            # Stack 
s2 = ""          # Updated string

for i in range(len(string)):
  stack.append(string[i])

for i in range(len(string)):
  s2 += stack.pop()

print s2

