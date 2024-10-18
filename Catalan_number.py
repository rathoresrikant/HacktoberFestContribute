def catalan_number(n):
    if n == 0 or n == 1:
        return 1
    
    catalan = [0] * (n + 1)
    catalan[0] = catalan[1] = 1
    
    for i in range(2, n + 1):
        for j in range(i):
            catalan[i] += catalan[j] * catalan[i - j - 1]
    
    return catalan[n]

# Example usage:
n = 5
print(f"The {n}th Catalan number is:", catalan_number(n))
