
n=int(input("Enter the n-th  of Newman Conway Sequence "))
arr=[0]*(n+1)
arr[1],arr[2]=1,1
for i in range(3,n+1):
    arr[i]=arr[arr[i-1]]+arr[i-arr[i-1]]
print(arr[n])