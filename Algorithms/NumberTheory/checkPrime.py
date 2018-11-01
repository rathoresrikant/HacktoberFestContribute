import math

n = int(input("Enter a Number: "))
sqrtn = math.ceil(math.sqrt(n))

for i in range(2,sqrtn+1):
  if n%i==0:
    print('%d is not prime!' %n)
    quit()

print('%d is prime!' %n)