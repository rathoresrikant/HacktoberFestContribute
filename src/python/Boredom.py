    raw_input()
     
    aux = [0]*100007
     
    for i in map(int,raw_input().split()):
     aux[i] += i
     
     
    a = b = 0
     
    for i in aux:
    	a,b = max(a, i+b), a
     
    print a
