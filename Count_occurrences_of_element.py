
# Python3 program to count  
# occurrences of an element 
  
# Returns number of times x  
# occurs in arr[0..n-1] 
def countOccurrences(arr, n, x): 
    res = 0
    for i in range(n): 
        if x == arr[i]: 
            res += 1
    return res 
   
# Driver code 
arr = [1, 2, 2, 2, 2, 3, 4, 7 ,8 ,8] 
n = len(arr) 
x = 2
print (countOccurrences(arr, n, x)) 
