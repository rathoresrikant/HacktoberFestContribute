#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> seq;

int Seq(int n){
    
    if(seq.size() >= n) return seq[n-1];
    int ans = Seq(Seq(n-1)) + Seq(n-Seq(n-1));
    seq.push_back(ans);
    return ans;
}

int main(){
    seq.push_back(1);
    seq.push_back(1);
    cout << "Enter n: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << Seq(i) << " ";
    }
    
}