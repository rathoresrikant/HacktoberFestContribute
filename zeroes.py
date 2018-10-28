L=list(map(int,input().split()))
L1=[]
L2=[]
for i in L:
  if i!=0:
    L1+=[i]
  else:
    L2+=[i]
print(L1+L2)
