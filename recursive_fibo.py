def fibo(a):
	if a==1:
		return(0)
	elif a==2:
		return(1)
	else:
		return(fibo(a-1)+fibo(a-2))

i=int(input("Enter i : "))
print(str(i)+"th element of fibonacci series is "+str(fibo(i)))