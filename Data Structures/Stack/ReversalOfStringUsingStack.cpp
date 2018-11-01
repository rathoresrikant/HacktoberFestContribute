#include<iostream>
#include<stack>//including stack library
using namespace std;
int main()
{
	string a;//initialize a string a
	cin>>a;
	stack<char>b;//initialize a stack named b
	for(long long int i=0;i<a.length();i++){//every element of string from front is pushed into stack
		b.push(a[i]);
	}
	for(long long int i=0;i<a.length();i++)
	{
		cout<<b.top();
		b.pop();//the top element if stack is shown then popped from stack:)
	}
}
