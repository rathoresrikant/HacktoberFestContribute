v=['a','e','i','o','u','A','E','I','U','O']
str = input("Enter String")
delstr=[]
j=0
for i in str:
    print(i)
    if i not in v:
        delstr.append(i)
        j=j+1
print("String After Deleting Vowels :",''.join(delstr))

