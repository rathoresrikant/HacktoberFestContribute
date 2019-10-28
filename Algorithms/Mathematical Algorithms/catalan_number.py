def catalan(n): 
    if n <=1 : 
        return 1 
    res = 0 
    for i in range(n): 
        res += catalan(i) * catalan(n-i-1) 
  
    return res 


i=int(input('Enter a number'))
catalan_num = catalan(i)

print(i)
