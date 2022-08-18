//C++ program to compute XOR of numbers from 1 to n 
//Compile using "g++ XOR1ton.cpp"

#include<iostream>
using namespace std;

int computeXOR(int n) 
{ 
    if (n % 4 == 0) 
        return n; 
    if (n % 4 == 1) 
        return 1; 
    if (n % 4 == 2) 
        return n + 1; 
    else
        return 0; 
} 

int main(void){
	int n;
	cout<<"Enter value of n"<<endl;
	cin>>n;
	cout<<"XOR of numbers from 1 to n is:"<<computeXOR(n)<<endl;
	
}
