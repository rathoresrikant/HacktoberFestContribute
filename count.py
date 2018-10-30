a=[]
a=list(int(x) for x in input().split(" "))
n=int(input())
c=0
for i in range(0,len(a)):
    if(a[i]==n):
        c+=1
print(c)
