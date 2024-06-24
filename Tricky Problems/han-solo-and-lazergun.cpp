#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,x0,y0;
	cin>>n>>x0>>y0;
	set<double>Set;

	while(n--)
	{
		double x, y, slope;
		cin>>x>>y;
		if(x==x0)
		{
			slope=pow(10,8);
		}
		else slope=(y-y0)/(x-x0);Set.insert(slope);
	}
	cout<<Set.size();
	cout<<endl;
	return 0;

}
