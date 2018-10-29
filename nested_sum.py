def nestSum(a):
	sum2=0
	sum1=0
	for i in a:
		if isinstance(i,list):
			sum1+=nestSum(i)
		else:
			sum2+=i
	return(sum2+sum1)

import ast
l=input("Enter nested list (eg [x,[y,z]]): ")
x=ast.literal_eval(l)
no=nestSum(x)
print("Sum of elements = "+str(no))
