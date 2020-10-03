#include<iostream>
using namespace std;
int main(){
int n;
cout<<"Enter the size of the array"<<endl;
cin>>n;

int arr[n];
cout<<"Enter the Elements of the array"<<endl;
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
int max = INT_MIN;

int currMax = 0;

for(int i=0;i<n;i++){

    currMax+=arr[i];

    if(currMax<0){

        currMax = 0;

    }

    if(currMax>max){

        max = currMax;

    }
}
cout<<"Maximum contiguous sum is : "<<max<<endl;

}
