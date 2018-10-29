#include <bits/stdc++.h>
using namespace std ;
int main()
{
	string a= "AEIOUaeiou" ;
	string s ;
	char b ;
	b = ' ' ;
	cin >> s ;
	for(int i = 0 ; i <s.length();++i)
	{
		for(int j = 0 ;j<a.length();j++)
		{
			
			if(s[i] == a[j])
			{
				s[i] = b ; 
			}
		}
	}
	s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
	cout << s ;
	return 0 ;
}
