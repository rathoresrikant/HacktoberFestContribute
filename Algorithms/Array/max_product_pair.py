def maxProductPair(arr, l):
	if l < 2:
		#if there are less then 2 elements present in there is no pair possible
		print ("no possible pair availible")
	else:
		if l == 2:
			#if length is equals to 2 this will be the only pair 
			printPair(arr[0], arr[1])
		else:
			'''
			now if there are more than 2 elements in array 
			we have to consider there sign(positive or negative) also

			so to overcome this problem we will compare product of first 2 
			and last 2 elements this simply covers all posibilites

			eg: if there are elements such as -4 -3 1 2 
			then 12(-4*-3) will be the maximum product and not 2(1*2) 
			'''
			
			if (arr[0] * arr[1]) > (arr[-2] * arr[-1]):
				printPair(arr[0], arr[1])
			elif (arr[0] * arr[1]) < (arr[-2] * arr[-1]):
				printPair(arr[-2], arr[-1])
			else:
				'''
				This is a special case when product of first 2 and last 2 elements 
				comes same

				eg : [-4,-2,2,4]
				'''
				printPair(arr[0], arr[1])
				printPair(arr[-2], arr[-1])


def printPair(a,b):
	print ("pair of elements with maximum product is", end=" ")
	print ("(", a, ",",b, ")", sep="") 


if __name__ == "__main__":
	'''
	taking input of array as space separated variable

	input(): function takes input as a string

	split(): function splits all elements with spaces 

	map(): takes 2 arguments a function and a iterable
		   and applies this function to the iterable

	list(): function gives us elements as list

	sorted() : this function sortes all array elements in increasing order 
	'''
	print ("enter array :", end = " ")
	array = sorted(list(map(int,input().split())))

	#getting the length of array by using len() function 
	length = len(array)
	maxProductPair(array, length)
