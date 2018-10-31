def no_operators(a,b):
  while b!=0:
    data=a&b
    a=a^b
    b=data<<1
  return a
x=no_operators(50,100)
print(x)
