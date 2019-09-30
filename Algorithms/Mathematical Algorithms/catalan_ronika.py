def binomialCoefficient(num, k):
	if (k > num - k):
		k = num - k

	res = 1

	for i in range(k):
		res = res * (num - i)
		res = res / (i + 1)
	return res

def catalan(n):
	c = binomialCoefficient(2*n, n)
	return c/(n + 1)


n = int(input("Enter the nth term for which Catalan number is to be found:"))
print (catalan(n))
