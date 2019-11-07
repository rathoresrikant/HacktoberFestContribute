#Prints prime numbers.
def prime(end ,start=0):
	numbers=list(range(start,end+1))
	result=list()
	for x in numbers:
		for y in range(2,x):
			if x%y==0:
				break
			else:
				result.append(x)
				break
	return result
print(prime(int(input("Enter end number: ")), int(input("Enter start number:")))) #Prints result in List.
# Code by S. U. Lokesh