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

void generate_all(vector <int> a, int idx, vector <int> subarray){
	if(idx == a.size()){
		int l = subarray.size();
		if(l!=0){
			rep0(i,l) cout << subarray[i] << " ";
			cout << "\n";
		}
	}else{
		generate_all(a, idx+1, subarray);
		subarray.pb(a[idx]);
		generate_all(a, idx+1, subarray);
	}
}
 
void solve(){

	int n;
	cin >> n;
	vector <int> a(n);
	rep0(i,n) cin >> a[i];
	vector <int> b;
	generate_all(a,0,b);
 
	return;
}
 
int main(){
 
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
// 	#ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif
 
	int TC = 1,t = 0;
	// cin >> TC;
	while(t++ < TC){
		solve();
		// cout << "\n";
	}
 
	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
 
	return 0; 
}
