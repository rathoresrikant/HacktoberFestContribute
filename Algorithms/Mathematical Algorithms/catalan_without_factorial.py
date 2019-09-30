'''Python program to find the nth catalan number without using the computationally intensive factorial function'''

number = int(input('Enter a number: '))



def catalan(n):
    if n <= 1: return 1

    numerator, denominator = 1, 1
    
    for i in range(2, n+1):
      numerator *= (n+i)
      denominator *= i
    return int(numerator/denominator)

print( catalan(number) )
