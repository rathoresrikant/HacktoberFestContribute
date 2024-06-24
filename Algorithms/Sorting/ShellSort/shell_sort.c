#include <stdio.h>
int shellSort(int arr[], int n) 
{ 
	for (int gap = n/2; gap > 0; gap /= 2) 
	{ 
		for (int i = gap; i < n; i += 1) 
		{ 
			int temp = arr[i]; 
			int j;			 
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
				arr[j] = arr[j - gap]; 
			arr[j] = temp; 
		} 
	} 
	return 0; 
} 

void printArray(int arr[], int n) 
{ 
	for (int i=0; i<n; i++) 
		printf("%d ",arr[i]);
} 

int main() 
{ 
	int n;
    printf("enter the size of the array : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nenter array elements: ");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
	printf("Array before sorting: \n"); 
	printArray(arr, n); 
	shellSort(arr, n); 
	printf("\nArray after sorting: \n"); 
	printArray(arr, n); 

	return 0; 
} 
