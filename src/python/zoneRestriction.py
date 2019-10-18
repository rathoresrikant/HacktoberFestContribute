

    n,h,m = map(int, raw_input().split())
     
    aux = [0]*n
     
    for i in range(m):
    	l,r,x = map(int, raw_input().split())
     
     
    	for i in range(l-1, r):
    		aux[i] = x**2
    for i in range(len(aux)):
    	if aux[i] == 0:
    		aux[i] = h**2
    		
    			
