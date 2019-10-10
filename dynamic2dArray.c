#include<stdio.h> 
#include<stdlib.h> 

int main() 
{ 
	int r, c,length=0; 
	int *ptr, **arr; 
	int count = 0,i,j;

	//taking row and column inputs
	scanf("%d",&r); 
	scanf("%d",&c); 
 

	length = sizeof(int *) * r + sizeof(int) * c * r; 
	arr = (int **)malloc(length); 

	// ptr is now pointing to the first element in of 2D array 
	ptr = (int *)(arr + r); 

	// for loop to point rows pointer to appropriate location in 2D array 
	for(i = 0; i < r; i++) 
		arr[i] = (ptr + c * i); 

	//taking all elemnts inputs
	for (i = 0; i < r; i++) 
		for (j = 0; j < c; j++) 
			scanf("%d",&arr[i][j]);

	for (i = 0; i < r; i++)
	{ 
		for (j = 0; j < c; j++) 
			printf("%d \t", arr[i][j]);
		printf("\n");
	}
	return 0; 
} 
