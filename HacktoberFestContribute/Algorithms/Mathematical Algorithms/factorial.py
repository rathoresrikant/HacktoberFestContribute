#!/usr/bin/python3

"""
Python function that calculates the factorial of a given number.
Accepts command line arguments or interactive user input
"""

import sys


def factorial(n):
		res = i = 1
		while i <= n:
			res *= i
			i += 1
		return res

def RecursiveFactorial(n):
    if n == 0:
        return 1
    res = n * RecursiveFactorial(n-1)
    return res

		
def main():
	if len(sys.argv) > 1:
		for arg in sys.argv[1:]:
			print("Factorial of {} is: {}".format(arg, factorial(arg)))
	else:
		num = input("Insert a number to find its factorial: ")
		try:
			n = int(num)
		except Exception as e:
			print("Error: {} is not a number!".format(num))
		print("Factorial of {} is: {}".format(n, factorial(n)))
		#print("Factorial of {} is: {}".format(n, RecursiveFactorial(n)))

if __name__ == '__main__':
	main()
