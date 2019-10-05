/*
   ProblemStatement: Merge Sort in Python using divide and conquer algorithm
   MergeSort is best example of a divide-and-conquer algorithm. 
   The algorithm divides the array in two halves, recursively sorts them and 
   finally merges the two sorted halves.
 */
 
 def merge(low,mid,high):
    global roll
    temp = []
    h =  low
    j = mid + 1
    while((h <= mid) and  (j<=high)):
        if roll[h] < roll[j]:
            temp.append(roll[h])
            h = h + 1
        else:
            temp.append(roll[j])
            j = j + 1
    if h > mid :
        for k in range(j,high+1):
            temp.append(roll[k])
    if j > high :
        for k in range(h,mid+1):
            temp.append(roll[k])
    temp.reverse()
    for k in range(low,high+1):
        roll[k] = temp.pop()
        
 def merge_sort(low,high):
    if low < high:
        mid = (low + high) // 2
        merge_sort(low,mid)
        merge_sort(mid+1,high)
        merge(low,mid,high)  
        
 roll = [41, 5, 82, 9, 12, 45, 49, 32, 96] /*roll is the list of items to be sorted */
 merge_sort(0, len(roll)-1)
 print("Sorted roll-",roll)
