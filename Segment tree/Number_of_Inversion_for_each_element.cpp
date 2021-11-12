// Program to find the number of inversions for each element of the permutation.
#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
vector<ll> ar,seg;
void update(ll pos,ll low,ll high,ll id)
{	if(low == high)	
	{	seg[pos] = 1;
		return ;
	}
	ll mid=(low+high)/2;
	if(id<=mid)	update(2*pos+1,low,mid,id);
	else	update(2*pos+2,mid+1,high,id);
	seg[pos] = seg[2*pos+1] + seg[2*pos+2];
}
ll query(ll pos,ll low,ll high,ll st,ll end)
{	if(high<st || low>end)	return 0;
	if(low>=st && high<=end)	return seg[pos];
	ll mid=(low+high)/2;
	return query(2*pos+1,low,mid,st,end) + query(2*pos+2,mid+1,high,st,end);
}
int main()
{	ll n;
	cin>>n;
	ar.resize(n);
	seg.resize(4*(n+5),0);
	for(ll i=0;i<n;i++)	cin>>ar[i];
	ll ans[n];
	for(ll i=0;i<n;i++)
	{	if(ar[i]==n)	{	ans[i]=0;update(0,0,n-1,ar[i]-1);continue;	}
		ans[i]=query(0,0,n-1,ar[i],n-1);
		update(0,0,n-1,ar[i]-1);
	}
	for(ll i=0;i<n;i++)	cout<<ans[i]<<" ";
}