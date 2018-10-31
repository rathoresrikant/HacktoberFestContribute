#include<iostream>
using namespace std;
int main()
{
	int n;
	int a[100];
	int i=0;
	int j=n-1;
	int cnt=0;
	cout<<"Enter the size of the array: ";
	cin>>n;
	cout<<"Enter the array Elements: ";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		if(a[i]==0){
			cnt++;
		}
	}
	for(i=0;i<n-cnt;i++){
		if(a[i]==0){
			for(j=n-1;j>=0;j--){
			if(a[j]!=0){
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			break;
		}
		else{
			cout<<"All Elements are 0s.";
		}}}}
	for(i=0;i<n;i++){
		cout<<a[i]<<"\t";
}
	return 0;
	system("PAUSE");
}
