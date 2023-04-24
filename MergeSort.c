#include<stdio.h>

void merge(int a[11],int low, int mid, int high)
{
	int l1,l2,i,b[11];
	for(l1=low,l2=mid+1,i=low;l1<=mid&&l2<=high;i++)
	{
		if(a[l1]<=a[l2])
			b[i] = a[l1++];
		else
			b[i] = a[l2++];
	}
	while (l1<=mid)
		b[i++] = a[l1++];
	while(l2<=high)
		b[i++] = a[l2++];
	for(i=low;i<=high;i++)
		a[i]=b[i];
}
void sort(int a[], int low, int high)
{ 	
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		sort(a,low,mid);
		sort(a,mid+1,high);
		merge(a,low,mid,high);
	}

}
int main()
{
	int i,a[11],n;
	printf("Enter number of elements:");
	scanf("%d",&n);
	printf("Enter elements");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,0,n-1);
	printf("List after sorting:");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;	
}
