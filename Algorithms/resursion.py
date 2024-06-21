def sumOfDigits(str):
	if len(str)==0:
		return 0

	else:
		value = str[0]
		sum=int(value) +int(sumOfDigits(str[1:]))           
		return sum
###########################################################
sum = 0 

def countZeros(n):
    if n<10 :
        if  n==0:
            return 1
        else :
            return 0 
    smaller_no =n//10
    if (n//10==n/10):
        return countZeros(smaller_no)+1
    else:
        return countZeros(smaller_no)
   ##########################################################
    
    
    def factorial(n):
    if (n==0):
        return 1
    fact= n*factorial(n-1)
    print(fact)
    return fact
    
    
    #########################################
    def sumtill(n):
    if n==0:
        return 0
    sum= n +sumtill(n-1)
    print (sum)
    return sum
    ####################################################################
    def print1toN(n):
    if n==0:
        return
    print1toN(n-1)
    print(n)
    
    def printNto1(n):
    if n==0:
        return
    print(n)
    printNto1(n-1)
    
    ########################################################################
