#include<bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int x)
    {
        return (x && !(x & (x - 1)));//if x is power of 2,its binary form will have only one 1 in fullstring.x-1 will have 1's in all the positions 
	                             //before the 1 in the power of 2.so,x&(x-1)=0.Now,x&(x-1) will also be 0 for the case when x=0,so if you do 
	                             //(x&(x-1))&&x,then,this will nowbe 1 onlyfor our required case.
    }
int main()
{
	int n;
	cout<<"enter the number to test ";
	cin>>n;
	int ans = isPowerOfTwo(n);
	if(ans == 1)
		cout<<"yes";
	else
		cout<<"no";
}    
