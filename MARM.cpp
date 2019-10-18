    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define pb push_back
    const ll MAX =1e9+7;
    

    int main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);

    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll A[n];
        for(ll i=0;i<n;i++)
            cin>>A[i];
        ll a,b;
        for(ll i=0;i<=k-1;i++){
            a=A[i%n];
            b=A[n-(i%n)-1];
            A[i%n]=a^b;
            
        }
        for(ll i=0;i<n;i++)
            cout<<A[i]<<" ";
        cout<<"\n";



    }
    return 0;
    }