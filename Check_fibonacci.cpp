/* Write a program to check whether a given number belongs to fibonacci series or not .*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a;
	cin>>n;
	while(n--){
		cin>>a;
		if( (ceil(sqrt(5*a*a -4)) == floor(sqrt(5*a*a -4))) || (ceil(sqrt(5*a*a +4)) == floor(sqrt(5*a*a +4))) ){
		    cout<<1<<endl;
		}
		cout<<0<<endl;
	}
	return 0;
}

