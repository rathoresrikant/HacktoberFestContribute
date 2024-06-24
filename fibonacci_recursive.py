def fibonacci(n):
	"""
	This function prints the Nth Fibonacci number.

	>>> fibonacci(3)
	1
	>>> fibonacci(10)
	55

	The input value can only be an integer, but integers lesser than or equal to 0 are invalid, since the series is not defined in these regions.
	"""
	if n<=0:
		return "Incorrect input."
	elif n==1:
		return 0
	elif n==2:
		return 1
	else:
		return fibonacci(n-1)+fibonacci(n-2)

number=4
print(fibonacci(number))