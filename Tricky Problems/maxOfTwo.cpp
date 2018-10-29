//Max of two num with overflow condition
//Refrence  : Cracking Coding Interview by Gayle Lakmann Mcdowell

#include <bits/stdc++.h>
using namespace std;

//XOR of bit to convert 1 into 0 and 0 into 1
int flip(int m){
	return (1 ^ m);
}

//Return 1 if positive, 0 if a is negative.
int sign(int m){
	return ((m >> 31) & 0x1);
}

void max(int a,int b){
	int c = a - b;
	int sa = sign(a);
	int sb = sign(b);
	int sc = sign(c);

	int sign_a = sa ^ sb;

	int sign_c = flip(sa ^ sb);

	int k = sign_a * sa + sign_c * sc;

	int q =  flip(k);

	int res = a * q + b * k;
	
	cout<<"Max Of "<<a<<" and "<<b<<"is: ";
	cout<<res;
}


// C++ program for above implementation 
#include <iostream> 
using namespace std; 
  
// simplest Function to find the largest of 2 numbers 
int LargestNum(int a, int b) 
{ 
    return a * (bool)(a / b) + b * (bool)(b / a); 
}

// simplest Function to find the min of 2 numbers 
int SmallestNum(int a, int b)
{
	return a * (bool)(b / a) + b * (bool)(a / b);
}

int main(){
	int a,b;
	cin>>a>>b;
	max(a,b);
	return 0;
}
