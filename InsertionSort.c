#include<stdio.h>
int main()
{
	int i,n,A[100],j;
	printf("Enter size of array:");
	scanf("%d",&n);
	printf("Enter %d elements:",n);
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	for (i=1;i<(n-1);i++)
	{	
		j=i;
		while(j>0 && A[j+1]>A[j])
		{
			int t = A[j];
			A[j] = A[j-1];
			A[j-1] = t;
			j--;
		}
	}
	printf("Sorted array in ascending order:");
	for(i = 0; i < n; i++)
	{
		printf("%d \n",A[i]);
	}
	return 0;
}
