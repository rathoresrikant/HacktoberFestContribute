#include <iostream>
using namespace std;
#define ll unsigned long int
ll catalan(ll n)
{
    if (n <= 1)
        return 1;
 
    ll res = 0;
    for (int i = 0; i < n; i++)
        res += catalan(i)
            * catalan(n - i - 1);
    return res;
} 
int main()
{
    int n;
    cin>>n;
    cout<<catalan(n)<<endl;
    return 0;
}