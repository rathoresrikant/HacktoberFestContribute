n=int(input())
L=list(map(int,input().split()))
L1=[]
for i in range(len(L)):
  for j in range(len(L)):
    if i!=j:
      L1+=[L[i]*L[j]]
L1=sorted(L1)
print(L1[len(L1)-1])
