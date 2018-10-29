//
#include<iostream>
#include<thread>
using namespace std;
void function(int,int);

int main()
{
	thread t1(function,20,30);
	t1.join();
	
	return 0;
}

void function(int var, int x)
{
	cout<<"I am in function(), and  var, x ="<< var<<" , "<<x<<endl;
}

