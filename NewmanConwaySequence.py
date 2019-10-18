def newmanConwaySequence(n):
    if n==1 or n==2:
        return 1
    return newmanConwaySequence(newmanConwaySequence(n-1))+newmanConwaySequence(n-newmanConwaySequence(n-1))

n=int(input("Enter a number"))
print(newmanConwaySequence(n))