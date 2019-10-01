import math
t = int(input())
for _ in range(t):
    x,y = map(float,input().split())
    if (x==0 or x==12):
        if (y==0 or y==60):
            diff = abs((x*30)-(y*6))
        else:
            diff = abs((y*6)-(y*0.5))
    else :
        if (y==0 or y==60):
            diff = abs((x*30)-(y*6))
        else:
            diff = abs((y*6)-(x*30+y*0.5)) 
    diff = min(diff,360-diff)
    print (math.floor(diff))
