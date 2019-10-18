#include <iostream>  
using namespace std; 

int gcd(int a, int b)
{ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
 } 

int main()  
{  
	int num1, num2;
	cout << "Enter 2 numbers: ";
	cin >> num1 >> num2;
    cout << "LCM of " << num1 << " and " << num2 <<" is " << (num1*num2)/gcd(num1, num2) << endl;  
    return 0;  
}  