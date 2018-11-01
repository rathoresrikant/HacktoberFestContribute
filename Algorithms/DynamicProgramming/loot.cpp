#include <iostream>
#include<climits>
using namespace std;

int getMaxMoneyDP(int arr[], int n)
{
  int * dp= new int[n+1];
  dp[0]=0;
  dp[1]=arr[0];
  
  for(int i=2;i<=n;i++)
  {
    dp[i] = max(arr[i-1]+dp[i-2], dp[i-1]);
  }
  return dp[n];
}

int getMaxMoneymemoisation(int arr[], int n, int* dp)
{
	if(n==0)
		return 0;
	if(dp[n]!=-1)
		return dp[n];

	int x=getMaxMoneymemoisation(arr+1,n-1,dp);
	int y=arr[0] + getMaxMoneymemoisation(arr+2,n-2,dp);

	dp[n]=max(x,y);
	return dp[n];
}

int getMaxMoneyMEMOISATION(int arr[], int n)
{
	int* dp= new int[n+1];
	for(int i=0;i<=n;i++)
		dp[i]=-1;
	return getMaxMoneymemoisation(arr,n,dp);
}
