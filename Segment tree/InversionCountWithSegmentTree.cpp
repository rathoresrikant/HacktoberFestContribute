#include<bits/stdc++.h>
using namespace std;
#define siz 200000
long long int tree[4*siz+1],cnt;
pair<int,int> a[siz+1];
void update(int node,int start,int end,int ind)
{
    if(start==end)
        tree[node]=1;
    else
    {
         int mid=start+((end-start)>>1);
         if(ind<=mid)
            cnt+=tree[2*node+1],update(2*node,start,mid,ind);
         else
            update(2*node+1,mid+1,end,ind);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}
int main()
{
    int t,n,r;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].first);
            a[i].second=i;
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
        {
            update(1,1,n,a[i].second);
        }
        printf("%lld\n",cnt);
        for(int i=1;i<=4*n+1;i++)
       	tree[i]=0;
    }
}
