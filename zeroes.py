l=list(map(int,input().split()))
m=[]
for i in l:
    if i==0:
        m.append(i)
        l.remove(i)
    else:
        continue
l=l+m
print(l)
