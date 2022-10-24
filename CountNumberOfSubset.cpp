#include<iostream>
using namespace std;

int CountOfSubset(int set[],int n,int w){
	if(w==0)return 1;
	if(n==0) return 0;
	if(set[n-1]>w) return CountOfSubset(set,n-1,w);
	else return CountOfSubset(set,n-1,w)+CountOfSubset(set,n-1,w-set[n-1]);
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int diff;
    cin>>diff;
    int s1=(diff+sum)/2;
    cout<<CountOfSubset(arr,n,s1)<<endl;

}