#include<iostream>
using namespace std;
 int main()
{
	cout<<"Enter Array len";
	int n;
	cout<<"Array ele";
	int c[n];
	int max=0,max2=0;
	
	for(int i=0;i,n;i++)
	{
		cin>>c[i];
		if (max<c[i])
		{
			max2=max;
			max=c[i];
		}

	}

	cout<<"Max prod="<<max*max2;
	return 0;
}
