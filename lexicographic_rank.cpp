#include <bits/stdc++.h>
#define ll int
using namespace std; 
  

ll fact(ll n) 
{ 
    if (n == 0 || n == 1) 
        return 1; 
    return n * fact(n - 1); 
} 

ll lexRnk(string s) 
{ 
    ll n = s.size(); 
    
    ll t_count = 1; 
  
     
    for (ll i = 0; i < n; i++) { 
        ll less = 0; 
        for (int j = i + 1; j < n; j++) { 
            if (ll(s[i]) > ll(s[j])) { 
                less += 1; 
            } 
        } 
  
       
        vector<ll> d_count(52, 0); 
  
        for (ll j = i; j < n; j++) { 
            if ((ll(s[j]) >= 'A') && ll(s[j]) <= 'Z') 
                d_count[(s[j]) - 'A'] += 1; 
            else
                d_count[(s[j]) - 'a' + 26] += 1; 
        } 
        ll d_fact = 1; 
        for (ll ele : d_count) 
            d_fact *= fact(ele); 
  
        t_count += (fact(n - i - 1) * less) / d_fact; 
    } 
  
    return t_count; 
} 
  

int main() 
{ 
    ll tc;
    cin>>tc;
    while(tc--)
    {
    string s1;
    cin>>s1;
    cout << "Rank of " << s1 << " is: "
         << lexRnk(s1) << endl; 
  
    }
    return 0; 
} 
