#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int start=0;
    int end=n-1;
    int first=-1; //first is the variable to store the first occurence in an array
    while(start<=end)
    {
        int mid=start+(end-start/2);
        if(k==a[mid])
        {
            first=mid;
            end=mid-1;
        }
        
        else if(k<a[mid])
        end=mid-1;

        else
        {
            start=mid+1;
        }
        
    }
    cout<<first<<endl;//to print the first occurence in an array
    return 0; 
}