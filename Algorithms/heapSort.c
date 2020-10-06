//HEAP-SORT
#include<stdio.h>
#include<stdlib.h>
void max_heapify(struct maxheap* Mheap,int i)
{
	int largest=i;
	int left=(i << 1)+1;
	int right=(i+1) << 1;
	if(left< Mheap -> a && Mheap -> arr[left]>Mheap->arr[largest])
		largest=left;
	if(right< Mheap -> a && Mheap -> arr[right]>Mheap->arr[largest])
		largest=right;
	if (largest!=i)
	{
		swap(&Mheap -> arr[largest],&Mheap->arr[i]);
		max_heapify(Mheap,largest);
	}
}
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
struct maxheap
{
	int* arr;
	int a;
};
struct maxheap* buildheap(int *arr,int s)
{
	int i;
	struct maxheap* Mheap=(struct maxheap*)malloc(sizeof(struct maxheap));
	Mheap -> a=s;
	Mheap -> arr=arr;
	for(i=(Mheap -> a -2)/2;i>=0;i--)
		max_heapify(Mheap,i);
	return Mheap;
}
void heapsort(int* arr,int size)
{
	struct maxheap* Mheap=buildheap(arr,size);
	while(Mheap -> a > 1)
	{
		swap(&Mheap -> arr[0],&Mheap -> arr[Mheap->a-1]);
		--Mheap -> a;
	}
	max_heapify(Mheap,0);
}
void printArray(int* arr, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}
 
/* Driver program to test above functions */
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, size);
 
    heapSort(arr, size);
 
    printf("\nSorted array is \n");
    printArray(arr, size);
    return 0;
}
