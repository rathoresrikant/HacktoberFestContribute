import sympy

print("Enter Text : ")
text = input()
print("Enter key K1 : ")
key1 = int(input())
print("Enter key K2 : ")
key2 = int(input())

encrypted = ""
substitutions = {}

for i in range(len(text)):
    if text[i].isupper():
        c = 65
    elif text[i].islower():
        c = 97
    formula = chr(((((ord(text[i])- c)*key1)+key2) % 26) + c)
    encrypted += formula
    substitutions[text[i]] = formula


print("The encrypted text is:", encrypted)
print("Substitutions performed ->", substitutions)

# decrypting
decrypted=""
substitutions2={}

for i in range(len(encrypted)):
    if encrypted[i].isupper():
        c = 65
    elif encrypted[i].islower():
        c = 97

    formula2= chr(((sympy.mod_inverse(key1, 26) * (ord(encrypted[i]) - c - key2))
         % 26) + c)

    decrypted += formula2
    substitutions2[encrypted[i]] = formula2

print("decrytped text: ",decrypted)
print("Substitutins : ",substitutions2)