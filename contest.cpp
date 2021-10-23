#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<stack>
#include<list>
#include<iterator>
#include<bitset>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;

#define fr(i,b,e) for(ll i=b; i<e; ++i)
#define f(i,e) fr(i,0,e)
#define rev(i,b,e) for(ll i=e-1; i>=b; --i)
#define RESET(a, b) memset(a, b, sizeof(a))
#define all(X) (X).begin(), (X).end()
#define allr(X) (X).rbegin(), (X).rend()
#define MP make_pair
#define pb push_back
#define setbits(X) __builtin_popcountll(X)
#define endl '\n'
#define NO "NO\n"
#define YES "YES\n"

const int N=3e5+5;
const int mod=1e9+7;

#define debug(x) cout<<#x<<" "<<x<<endl;
#define debugg(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

void setio(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    //cout<<fixed<<setprecision(2);
}
void solve(){
    
}
int main(){
    setio();
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
