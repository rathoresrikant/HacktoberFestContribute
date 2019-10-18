#include <iostream>
using namespace std;

unsigned long int catalan(unsigned int n)
{

    if (n <= 1)
        return 1;

    unsigned long int res = 0;
    for (int i = 0; i < n; i++)
        res += catalan(i) * catalan(n - i - 1);

    return res;
}

int main()
{
    long long n;
    cout << "Enter the Value of N for which you need the nth catalan number:\n";
    cin >> n;

    catalan(n);
    return 0;
}