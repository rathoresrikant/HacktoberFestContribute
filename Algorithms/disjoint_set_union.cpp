# include <bits/stdc++.h>
#define flash ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define endl '\n'
#define ll long long int
#include <tr1/unordered_map>
#define ld long double
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f(i,a,b)  for(long long i=a;i<b;i++)
#define all(c) (c).begin(),(c).end()
#include <map>
using namespace std;

void initialize(ll *arr,ll * size,ll n)
{
	for(ll i=0;i<n;i++)
	{
		arr[i]=i;
		size[i]=1;
	}
}
ll root(ll *arr,ll i)
{
	while(arr[i]!=i)
	{
		arr[i]=arr[arr[i]];
		i=arr[i];
	}
	return i;
}

bool find(ll *arr,ll a,ll b)
{
	if(root(arr,a)==root(arr,b))
	{
		return true;
	}
	else
	{
		return false;
	}
}
void weighted_union(ll *arr,ll * size ,ll a,ll b)
{
	ll root_a=root(arr,a);
	ll root_b=root(arr,b);
	if(size[root_a]>=size[root_b])
	{
		arr[root_b]=arr[root_a];
		size[root_a]+=size[root_b];
		size[root_b]=0;
	}
	else
	{
		arr[root_a]=arr[root_b];
		size[root_b]+=size[root_a];
		size[root_a]=0;
	}
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\user\\Desktop\\coding problems\\in.txt","r",stdin);
    freopen("C:\\Users\\user\\Desktop\\coding problems\\output.txt","w",stdout);
  #endif


     flash;
     ///////////////////////////////////////////////////////////////////////////////////////

     

ll n,m;
cin>>n>>m;
ll arr[n],size[n];
initialize(arr,size,n);
for(ll i=0;i<m;i++)
{
	ll a,b;
	cin>>a>>b;
	a--;
	b--;
	weighted_union(arr,size,a,b);
	ll sizer[n];
	for(ll j=0;j<n;j++)
	{
		sizer[j]=size[j];
	}
	sort(sizer,sizer+n);
	for(ll j=0;j<n;j++)
	{
		if(sizer[j]!=0)
		{
cout<<sizer[j]<<" ";
		}
	}
	cout<<endl;
}












    ///////////////////////////////////////////////////////////////////////////////////////

     return 0;

}
