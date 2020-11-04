def selection_sort(a):
	for i in range(len(a)-1):
		min = i
		for j in range(i+1, len(a)):
			if(a[j]<a[min]):
				min = j
		a[i],a[minimum]=a[minimum],a[i]
	print("after selection sort:")
	print(a)
unsorted_list =[6,4,23,7,2,5,8,3,2,234,6,0,2,5]
selection_sort(unsorted_list)
