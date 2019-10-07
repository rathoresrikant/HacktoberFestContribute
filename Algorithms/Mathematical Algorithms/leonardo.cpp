#include <iostream> 
using namespace std; 
  
int main() 
{ 
	cout << "Enter length of leonardo sequence: ";
	int n;
	cin >> n;
	if(n == 1)
	{
		cout << "1" << endl;
	}
	else if(n == 2)
		cout << "1, 1" << endl;
	else
		cout << "1, 1, ";
	int num1=1, num2=1, num3;
    for(int i=0;i<n-2;i++)
    {
    	num3 = num1 + num2 + 1;
    	if(i == n-3)
    		cout << num3 << endl;
    	else
    		cout << num3 << ", ";
    	num1 = num2;
    	num2 = num3;
    }
    return 0; 
} 