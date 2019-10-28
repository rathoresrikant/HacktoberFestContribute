def prime(r):
    for a in range(2,r+1):
        flag=0
        for i in range(2,a//2+1):
            if(a%i==0):
                flag=1
        if(flag==0):
            print(a)
prime(input("enter a range")
