/ C++ Program for the binary
// representation of a given number
#include <bits/stdc++.h>
using namespace std;
 
  void bin(long n)
  {
    long i;
    cout << "0";
    for (i = 1 << 30; i > 0; i = i / 2)
    {
      if((n & i) != 0)
      {
        cout << "1";
      }
      else
      {
        cout << "0";
      }
    }
  }
 
// Driver Code
int main(void)
{
    bin(7);
    cout << endl;
    bin(4);
}
 
