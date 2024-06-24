#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define popb pop_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair <int,int>
#define piii pair <pii,int>
#define rep0(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define reprev(i,n) for(ll i=n;i>=0;i--)
#define all(c) c.begin(),c.end()
#define print(a) rep0(i,a.size()) cout << a[i] << " "
#define hi() cout << "\nHello, I am error. Can you find me? :):):)\n"
 
using namespace std;
 
const int mod = 1e9+7;
const long double pi = acos(-1);

ll Catalan(ll n, ll k){
	ll res = 1;
	rep0(i,k){
		res *= (n - i);
		res /= (i + 1);
	}
	return res;
}
 
void solve(){

	ll n;
	cin >> n;
	cout << (Catalan(2*n,n))/(n+1);
 
	return;
}
 
int main(){
 
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin);
	// 	freopen("output.txt", "w", stdout);
	// #endif
 
	int TC = 1,t = 0;
	// cin >> TC;
	while(t++ < TC){
		solve();
		// cout << "\n";
	}
 
	// cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
 
	return 0; 
}
