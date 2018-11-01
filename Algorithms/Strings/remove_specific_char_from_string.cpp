#include<bits/stdc++.h>
using namespace std ;
int main()
{
	string s ; 
	char a ;
	cin >> s >> a ;
	s.erase(std::remove(s.begin(), s.end(), a), s.end());
	cout <<s ;
	return 0  ;
}
