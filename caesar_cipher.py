n = int(input())
ip = input()
k = int(input())
str_ = ""
for i in ip:
    if 65<=ord(i)<=90:
        x = chr(((ord(i)-65+k)%26)+65)
    elif 97<=ord(i)<=122:
        x = chr(((ord(i) - 97 + k) % 26) + 97)
    else:
        str_+=i
        continue
    str_+=x
print(str_)

