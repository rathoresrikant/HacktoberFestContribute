#include <bits/stdc++.h>
using namespace std ;
int main()
{    
	stack <string> s;
	string a;
	cout <<"enter what you want :) : \n" ;
	cin>> a ;
	for(int i = 0 ; i < a.length() ; i++)
	{
		string b ; 
		b = a[i] ;
		s.push(b) ;
	}
	while(!s.empty())
	{
    	cout << s.top();
    	s.pop();
	}
	cout << endl;
	return 0;
}
