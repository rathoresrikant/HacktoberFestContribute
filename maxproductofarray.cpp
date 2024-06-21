#include<bits/stdc++.h>
using namespace std;
#define ll long long int;
int main()
{
ll n;
cout<<"enter size of array"<<endl;
cin>>n;
int a[n];
for(ll i=0;i<n;i++)
{
cin>>a[i];
}
sort(a,a+n);
unsigned long long int prod=a[n]*a[n-1];
cout<<"required product is"<<prod<<endl;
return 0;
}
