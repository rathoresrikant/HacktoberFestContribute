/* let a n digit number abc....k, then if a^n+b^n+...k^n==abc....k then the output is yes, else no*/
#include<cmath>
#include<iostream>
using namespace std;

int main()
{
	int num,len,sum=0;
	cout<<"Enter the number to be verified /n";
	cin>>num;
	int n=num;
	while(n!=0)
	{
		n/=10;
		len++;
	}
	n=num;
	for(int i=0;i<len;i++)
	{
		sum=sum+pow(n%10,len);
		n=n/10;
	}
	if(num==sum)
	cout<<"yes";
	else
	cout<<"no";
}
