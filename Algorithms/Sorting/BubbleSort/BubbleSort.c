#include<stdio.h>
#include<stdlib.h>
int* input(int n);
int* sort(int arr[],int n);
void display(int arr[],int n);
int main(void){
	int n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int *arr=input(n);
	printf("\nArray before sorting: ");
	display(arr,n);
	arr=sort(arr,n);
	printf("\nArray after sorting: ");
	display(arr,n);
	return 1;
}
void display(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
int* input(int n){
	int *arr=(int*)malloc(n*sizeof(int)),i;
	for(i=0;i<n;i++){
		printf("Input %d: ",i+1);
		scanf("%d",arr+i);
	}
	return arr;
}
int* sort(int arr[],int n){
	int i,j,c;
	for(i=0;i<n;i++){
		c=0;
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				c=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=c;
				c=1;
			}		
		}
		if(c==0)
			break;
	}	
	return arr;
}
