#include <bits/stdc++.h>

using namespace std;
const int MAX = 100005;
int n;
vector<bool> is_prime(MAX+1, true);

void sieve(){
    for (int i = 2; i<= MAX; i++) {
        if (is_prime[i]) {
            for (int j = 2 * i; j <= MAX; j += i)
                is_prime[j] = false;
        }
    }
}

int main(){

    is_prime[0] = is_prime[1] = false;
    sieve();

    cin>>n;
    
    for(int i=0;i<=n;i++){
        if(is_prime[i]){
            cout<<i<<" ";
        }
    }
    cout<<'\n';
}
