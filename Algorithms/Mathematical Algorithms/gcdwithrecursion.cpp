#include<iostream>
using namespace std ;

int gcd(int a, int b){
	if(a == 0)
		return b ;
	else if(b == 0)
		return a ;
	else if(a == b)
		return a ;
	else if(a > b) 
		return gcd(a % b,b) ;
	else if(b > a)
		return gcd(a,b % a) ;
}

int main(){
	int a, b ;
	cout<<"Enter ther numbers for GCD: " ;
	cin>>a>>b ;
	cout<<"GCD = "<<gcd(a,b) ;
	getch() ;
	return 0 ;
}
