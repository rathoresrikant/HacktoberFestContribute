#include<iostream>
#include<algorithm>
using namespace std;
//program that gives last occurence of an element in a sorted array using binary search
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
    int last=-1; //last is the variable to store the first occurence in an array
    while(start<=end)
    {
        int mid=start+(end-start/2);
        if(k==a[mid])
        {
            last=mid;
            start=mid+1;
        }
        
        else if(k<a[mid])
        end=mid-1;

        else
        {
            start=mid+1;
        }
        
    }
    cout<<last<<endl;//to print the last occurence in an array
    return 0; 
}
//Time complexity:O(logn)