#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,s=0;
    cout<<"Enter The size of an Array ";
    cin>>n;
    int arr[n];
    cout<<"Insert the Elements of Array ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cout<<"Enter the element those occuerence to be find";
    cin>>k;
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        if(arr[i]==k)
        {
            s=1;
            while(arr[i]==arr[i+1])
            {    s++;   i++;    }
            break;
        }
    }
    cout<<s<<endl;
    return 0;
}
