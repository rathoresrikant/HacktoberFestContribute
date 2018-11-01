#include<iostream>
using namespace std;
int main()
{
	int n;
	int a[100];
	int i=0;
	int j=0;
	int cnt=0;
	int n1=0;
	int n2=0;
	cout<<"Enter the size of the array: ";
	cin>>n;
	cout<<"Enter the array Elements: ";
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	int pro=a[0]*a[1];
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if((a[i]*a[j])>pro){
				n1=a[i];
				n2=a[j];
				pro=a[i]*a[j];
			}
		}
	}
	cout<<"The 1st number is "<<n1<<endl;
	cout<<"The 2nd number is "<<n2<<endl;
	cout<<"The maximum product is "<<pro;
	return 0;
	system("PAUSE");
}
