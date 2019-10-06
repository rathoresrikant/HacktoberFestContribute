#include <bits/stdc++.h>
using namespace std;

int Seq(int n){
    if(n==1 || n==2) return 1;
    else return Seq(Seq(n-1)) + Seq(n-Seq(n-1));
}

int n;

int main(){
    cout << "Enter n: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << Seq(i) <<" ";
    }
    
}