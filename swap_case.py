str1=input()
str1=list(str1)
len1=len(str1)
for i in range(len1):
    
    if (ord(str1[i])>=97 and ord(str1[i])<=122):
        
        str1[i]=(str1[i]).upper()
        
        
    elif (ord(str1[i])>=65 and ord(str1[i])<=90):
        str1[i]=str1[i].lower()
print("".join(str1))
