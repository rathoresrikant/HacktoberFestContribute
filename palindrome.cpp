#include<iostream>
using namespace std;
int main()
{
int n,t,rev=0,r;
cout<<"enterthe no";
cin>>n;
t=n;
	while(n!=0)
	{
	r=n%10;
	rev=rev*10+r;
	n=n/10;

	}
	 if(rev==t)
	 {
 	   cout<<"the number is palindrome";
 	}
	else
	{

	cout<<"the number is not palindrome";
	}
return 0;

}
