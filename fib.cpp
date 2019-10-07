#include <iostream>
using namespace std;
int fib(int n) 
{
  
  if(n <= 1)
    return n;
return fib(n - 1) + fib(n - 2);
}

int main() 
{
  cout << fib(6) << endl;
  return 0;
}
