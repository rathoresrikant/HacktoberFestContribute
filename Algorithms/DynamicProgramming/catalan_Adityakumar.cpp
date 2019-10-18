// Cpp program to find Catalan Number

#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

ll binomialCoeff(ll n, ll k) 
{ 
    ll res = 1; 
  
    // Since C(n, k) = C(n, n-k) 
    if (k > n - k) 
        k = n - k; 
  
    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1] 
    for (ll i = 0; i < k; ++i) 
    { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
  
    return res; 
} 

ll catalan(ll n) 
{ 
    // Calculate value of 2nCn 
    ll c = binomialCoeff(2*n, n); 
  
    // return 2nCn/(n+1) 
    return c/(n+1); 
} 

int main() {
  ll no;
  cout<<"Enter Number : ";
  cin>>no;
  ll cat = catalan(no);
  cout<<"Catalan of "<<no<<" th number is "<<cat;
  return 0;
}