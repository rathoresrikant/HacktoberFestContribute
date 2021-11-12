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

void newman_convey(int n){
	ll f[n+1];
	f[0] = 0;
	f[1] = 1;
	f[2] = 1;
	rep(i,3,n) f[i] = f[f[i-1]] + f[i - f[i-1]];
	rep1(i,n) cout << f[i] << " ";
}
 
void solve(){

	int n;
	cin >> n;
	newman_convey(n);
 
	return;
}
 
int main(){
 
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
 
	int TC = 1,t = 0;
	// cin >> TC;
	while(t++ < TC){
		solve();
		// cout << "\n";
	}
 
	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
 
	return 0; 
}