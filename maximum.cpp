#include<bits/stdc++.h>


using namespace std;

int max(int x, int y)
{
  return x ^ ((x ^ y) & -(x < y));
}


int main()
{
  int x,y;
   cin>>x>>y;
   cout<<max(x,y)<<"\n";
}
