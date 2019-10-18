#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define re1(x) scanf("%lld",&x)
#define re2(x,y) scanf("%lld%lld",&x,&y)
#define re3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define pr(x) printf("%lld\n",x);
#define pb push_back
#define mp make_pair
ll n,u,q;
ll arr[10010];
ll BIT_1[10020];
ll BIT_2[10020];
void update1(ll index,ll val){
	index+=1;
	while(index<=n){
		BIT_1[index]+=val;
		index+=(index&(-index));
		//go to next element to be updated
	}
}
ll query1(ll index){
	index+=1;
	// as bittree has one extra element
	ll sum=0;
	while(index>0){
		sum+=BIT_1[index];
		index-=(index&(-index));
	}
	return sum;
}
void update2(ll index,ll val){
	index+=1;
	while(index<=n){
		BIT_2[index]+=val;
		index+=(index&(-index));
		//go to next element to be updated
	}
}
ll query2(ll index){
	index+=1;
	// as bittree has one extra element
	ll sum=0;
	while(index>0){
		sum+=BIT_2[index];
		index-=(index&(-index));
	}
	return sum;
}
void update_r(ll l,ll r,ll val){
	update1(l,val);
	update1(r+1,-val);
	update2(l,val*(l-1));
	update2(r+1,-val*r);
}
ll sum(ll x){
	return ((query1(x)*x)-query2(x));
}
ll range_sum(ll l,ll r){
	return sum(r)-sum(l-1);
}
int main(){
	ll t;
	re1(t);
	while(t--){
		re2(n,u);
		for(ll i=0;i<n;i+=1){
			arr[i]=0;
		}
		for(ll i=0;i<=n;i+=1){
			BIT_1[i]=0;
			BIT_2[i]=0;
		}
		for(ll i=0;i<u;i+=1){
			ll l,r,val;
			re3(l,r,val);
			update_r(l,r,val);
		}
		re1(q);
		for(ll i=0;i<q;i+=1){
			ll xx;
			re1(xx);
			//xx-=1;
			ll yy=range_sum(0,xx-1);
			ll xx1=range_sum(0,xx);
			ll ans=xx1-yy;
			pr(ans);
		}
	}
	return 0;
}
