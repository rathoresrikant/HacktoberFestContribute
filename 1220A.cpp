#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX =1e9+7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    char a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int zero=0,one=0;
    for(int i=0;i<n;i++){
        if(a[i]=='z')
            zero++;
        if(a[i]=='n')
            one++;
    }
    for(int i=0;i<one;i++)
        cout<<"1 ";
    for(int i=0;i<zero;i++)
        cout<<"0 ";

    return 0;
}