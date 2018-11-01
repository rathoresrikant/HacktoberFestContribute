#include <bits/stdc++.h>
using namespace std ;
int main()
{
	string s1 , s2 ;
	int d;
	cin >> s1 >> s2 ;
	d= s1.find(s2);
	s1.erase(d,s2.length());
	cout << s1 ;
	return 0 ;
}
