def shell_sort(A):
    sublistcount= len(A) // 2
    while sublistcount > 0:
        for startposition in range(sublistcount):
            gap_insertion_sort(A,startposition,sublistcount)
        print("after increments of size",sublistcount,"the list is",A)
        sublistcount = sublistcount // 2
def gap_insertion_sort(A,start,gap):
    for i in range(start+gap,len(A),gap):
        presentvalue = A[i]
        position = i
        while position >= gap and A[position-gap]>presentvalue:
            A[position] = A[position-gap]
            position = position-gap
            A[position]=presentvalue
A=[542,236,254,565,220,127,996]
shell_sort(A)
print(A)                        
