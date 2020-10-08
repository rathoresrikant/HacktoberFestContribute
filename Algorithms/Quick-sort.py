#cook your dish here
#this is code by keshav
def partition(lst, low, high):
    i = (low - 1)  # index of smaller element
    pivot = lst[high]  # pivot
    for j in range(low, high):
        # If current element is smaller than or
        # equal to pivot
        if lst[j] <= pivot:
            # increment index of smaller element
            i = i + 1
            lst[i], lst[j] = lst[j], lst[i]

    lst[i + 1], lst[high] = lst[high], lst[i + 1]
    return (i + 1)
# The main function that implements QuickSort
# arr[] --> Array to be sorted,
# low  --> Starting index,
# high  --> Ending index
# Function to do Quick sort
def quickSort(lst, low, high):
    if len(lst) == 1:
        return lst
    if low < high:
        # pi is partitioning index, arr[p] is now
        # at right place
        pi = partition(lst, low, high)
        # Separately sort elements before
        # partition and after partition
        quickSort(lst, low, pi - 1)
        quickSort(lst, pi + 1, high)


# Driver code to test above
lst = list(map(int,input().split()))
n = len(lst)
quickSort(lst, 0, n - 1)
print("Sorted list is:")
for i in range(n):
    print(lst[i]),
