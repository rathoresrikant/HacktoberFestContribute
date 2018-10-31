#include <iostream>
#include<climits>
using namespace std;
int knapsack_RECURSIVE(int* weights, int* values, int n, int maxWeight){
	
	if(n==0)
		return 0;
	int item_present;
	//IF CURRENT ITEM IS PUT IN KNAPSACK
  	if(maxWeight-weights[0]>=0)
		item_present = values[0] + knapsack(weights+1,values+1,n-1,maxWeight-weights[0]);
  	else
      	item_present=INT_MIN;
  

	//IF CURRENT ITEM IS NOT PUT IN KNAPSACK
	int item_absent = knapsack(weights+1,values+1,n-1,maxWeight);
	cout<<weights[0]<<" "<<(item_absent , item_present)<<endl;
	return max(item_absent , item_present);
}

int knapsack_memoisation(int* weights, int* values, int n, int maxWeight, int** dp)
{
	if(n==0||maxWeight==0)
		return 0;
	int item_present,item_absent;

  	if(maxWeight-weights[0]<0)
    {
      	dp[maxWeight][n-1]=knapsack_memoisation(weights+1,values+1,n-1,maxWeight,dp);
  		return dp[maxWeight][n-1];
    }
  	
    if(dp[maxWeight][n]!=-1)
        return dp[maxWeight][n];
  	
  		dp[maxWeight-weights[0]][n-1]=knapsack_memoisation(weights+1,values+1,n-1,maxWeight-weights[0],dp);
		item_present = values[0] + dp[maxWeight-weights[0]][n-1];
  
  		dp[maxWeight][n-1]=knapsack_memoisation(weights+1,values+1,n-1,maxWeight,dp);
		item_absent = dp[maxWeight][n-1];
  
		dp[maxWeight][n]=max(item_absent , item_present);
	return dp[maxWeight][n];
}

int knapsack(int* weights, int* values, int n, int maxWeight)
{
 
	int i=maxWeight+1;
    int j=n+1;

	int**dp=new int*[i];
	for(int k=0;k<i;k++)
		dp[k]=new int[j];

	for(int m=0;m<i;m++)
		for(int n=0;n<j;n++)
			dp[m][n]=-1;

	int f=knapsack_memoisation(weights,values,n,maxWeight,dp);
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
  for(int n=0;n<i;n++)
		{
			delete[]dp[n];
		}

	return f;
}

int knapsack_DP(int* weights, int* values, int n1, int maxWeight){
  int m=n1+1;
  int n=maxWeight+1;
  
  int**dp=new int*[m];
  for(int i=0;i<m;i++)
    dp[i]=new int[n];
  
  for(int i=0;i<m;i++)
    dp[i][0]=0;
  for(int j=0;j<n;j++)
    dp[0][j]=0;
  
  for(int i=1;i<m;i++)
  {
    for(int j=1;j<n;j++)//j is remaining weight
    {
      if(j>=weights[i-1])
      {
      	int x=values[i-1]+dp[i-1][j-weights[i-1]];
      	int y=dp[i-1][j];
      	dp[i][j]=max(x,y);
      }
      else
        dp[i][j]=dp[i-1][j];
    }
  }
  return dp[m-1][n-1];



}
