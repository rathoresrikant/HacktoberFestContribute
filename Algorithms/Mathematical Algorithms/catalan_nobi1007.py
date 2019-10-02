def inner(x): 
    fact=1
    for i in range(1,x+1):   
        fact*=i
    return fact
    
n = int(input().strip())
catalan_num = inner(2*n)//(inner(n)*inner(n+1))
print(catalan_num)