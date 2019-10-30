#include<iostream>
using namespace std;

long long calculate(int a,int b)
{
	long long ans = 1;
	while(b>0)
	{
	  if(b&1){
	     ans = (ans * a);
	  }
	  
	  a = a*a;
	  
	  b = b>>1;
	}
	
	return ans;
}

int main()
{
	int a,b;
	long long ans;
	cin>>a>>b;
	
	cout<<calculate(a,b);
	return 0;
}
