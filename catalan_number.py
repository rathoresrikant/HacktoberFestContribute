n=int(input("Enter the number"))
catalan=[0 for i in range(n+1)]
catalan[0]=1
catalan[1]=1
res=[]
for i in range(2,n): 
  catalan[i]=0
  for j in range(i):
    catalan[i]+=catalan[j]*catalan[i-j-1]
print(catalan)
