'''
1. take input from user:
    n=no of elements
    lista=list of elements(unsorted)

2. take random index i,j using random.randin and replace elements on that i,j index
3. repaet step 2 until list is sorted
'''
import random
n = int(input("enter no of elements"))
lista = []
listb = []
print("enter unsorted elements")
for k in range(n):
    temp = int(input())
    lista.append(temp)
listb = lista
def checksort(listb):
    i = random.randint(0, len(listb)-1)
    j = random.randint(0, len(listb)-1)
    temp2 = listb[i]
    listb[i] = listb[j]
    listb[j] = temp2
    return listb
    
while (not listb == sorted(lista)):
    if (not listb == sorted(lista)):
        checksort(listb)
    elif(listb == sorted(lista)):
        break

for k in range(n):
    print(listb[k],' ',end='')