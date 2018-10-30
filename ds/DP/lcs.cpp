#include <iostream>
#include <string>
#include <climits>
using namespace std;

int lcsrecursive(string s,string t)
{
	if(s.size()==0||t.size()==0)
		return 0;

	if(s[0]==t[0])
	{
		return 1+lcsrecursive(s.substr(1),t.substr(1));
	}

	int x=lcsrecursive(s.substr(1),t);
	int y=lcsrecursive(s,t.substr(1));

	return max(x,y);
}

int lcsmemoisation(string s,string t,int**dp)
{
	if(s.size()==0||t.size()==0){
		dp[s.size()][t.size()]=0;
		return 0;
	}
	int i=s.size();
	int j=t.size();

	if(dp[i][j]!=-1)
		return dp[i][j];

	if(s[0]==t[0])
	{
		dp[i-1][j-1]=lcsmemoisation(s.substr(1),t.substr(1),dp);
		//cout<<s<<" "<<t<<endl;
			dp[i][j]=1+dp[i-1][j-1];
		return dp[i][j];
	}

	int x,y;
	//cout<<"hello"<<endl;

	dp[i-1][j]=lcsmemoisation(s.substr(1),t,dp);
	dp[i][j-1]=lcsmemoisation(s,t.substr(1),dp);


	dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

	return dp[i][j];

}

int lcsMEMOISATION(string s,string t)
{
	int i=s.size()+1;
	int j=t.size()+1;

	int**dp=new int*[i];
	for(int k=0;k<i;k++)
		dp[k]=new int[j];

	for(int m=0;m<i;m++)
		for(int n=0;n<j;n++)
			dp[m][n]=-1;

	int f=lcsmemoisation(s,t,dp);
	for(int m=0;m<i;m++)
	{
		for(int n=0;n<j;n++)
		{
			if(dp[m][n]==-1)
				cout<<"X"<<" ";
			else
				cout<<dp[m][n]<<" ";
		}
		cout<<endl;
	}

	return f;
}


int lcsDP(string s,string t)
{
	int m=s.size()+1;
	int n=t.size()+1;

	int**dp=new int*[m];
	for(int k=0;k<m;k++)
		dp[k]=new int[n];

	for(int i=0;i<m;i++)
		dp[i][0]=0;

	for(int i=0;i<n;i++)
		dp[0][i]=0;

	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(s[i]==t[j])//IDEALLY IT SHOULD BE  if(s[i-1]==t[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}

	return dp[m-1][n-1];
}

int main()
{
	string s,t;
	cin>>s>>t;
	cout<<lcsrecursive(s,t)<<endl;
	cout<<lcsMEMOISATION(s,t)<<endl;
	cout<<lcsDP(s,t)<<endl;
	

}