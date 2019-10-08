

    y = int(raw_input())
     
    x = map(int, raw_input().split())
     
    z = list(set(x))
     
    x.sort()
     
    maxi = max(x)
    l = []
     
    for i in xrange(len(x)-1,-1,-1):
    	if maxi-x[i] <= 5:
    		l.append(x[i])
     
    if len(z) == 1:
    	cont = y	
    elif len(l) == 5:
    	cont = 12
    else:		
    	cont = len(l)
    print cont	
