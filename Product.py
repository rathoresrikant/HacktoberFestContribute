
n=input()
n=int(n)
l=[]
l=[int(x) for x in input().split(" ")]
l=sorted(l)
l=l[::-1]
print(l[0],l[1])
