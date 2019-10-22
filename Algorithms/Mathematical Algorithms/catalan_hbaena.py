def catalan_number(n:int):
    mult = 1
    for k in range(2, n+1):
        mult *= (n + k)/k
    return mult


print(catalan_number(10))
