#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    for(int i = 0;i <= 10000;++i)
    {
        int r = i;
        int dig = 0;
        while(r != 0)
        {
            dig++;
            r /= 10;
        }
        int n = i, sum = 0;
        while(n != 0)
        {
            int d = n % 10;
            sum += pow(d, dig);
            n /= 10;
        }
        if(sum == i)
            cout << i << ' ';
    }
    cout << "\n\n\n";
    return 0;
}
