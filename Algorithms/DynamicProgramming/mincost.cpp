#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int mincost(int** input,int i,int j,int m,int n)
{
  if(i==m-1&&j==n-1)
    return input[m-1][n-1];
  
  if(i>=m||j>=n)
    return INT_MAX;
  
  int a=mincost(input,i+1,j,m,n);
  int b=mincost(input,i,j+1,m,n);
  int c=mincost(input,i+1,j+1,m,n);
  
  return input[i][j] + min(a,min(b,c));
  
}

int minCostPath(int **input, int m, int n) {
    
  return mincost(input,0,0,m,n);
    
}


int mincostmemoisation___lower(int** input,int** dp,int i,int j,int m,int n)
{
 
	if(i==m-1&&j==n-1)
	{
		dp[i][j]=input[m-1][n-1];
		return input[m-1][n-1];
	}

	if(i>=m||j>=n)
		return INT_MAX;

	int x,y,z;
	if(i+1<m&&j<n&&dp[i+1][j]!=-1)
		x=dp[i+1][j];
	else
		x=mincostmemoisation___lower(input,dp,i+1,j,m,n);

	if(i+1<m&&j+1<n&&dp[i+1][j+1]!=-1)
		y=dp[i+1][j+1];
	else
		y=mincostmemoisation___lower(input,dp,i+1,j+1,m,n);


	if(i<m&&j+1<n&&dp[i][j+1]!=-1)
		z=dp[i][j+1];
	else
		z=mincostmemoisation___lower(input,dp,i,j+1,m,n);

	int res=input[i][j]+min(x,min(y,z));
	if(i<m&&j<n)
		dp[i][j]=res;
	return res;

}

int mincostmemoisation(int** input,int** dp,int i,int j,int m,int n)
{
  
  
	if(i==m-1&&j==n-1)
    {
        dp[i][j]=input[i][j];
		return input[i][j];
    }
  
	if(i>=m||j>=n)
		return INT_MAX;
    
    if(dp[i][j]!=-1)
      return dp[i][j];
  
  
	int x,y,z;
		x=mincostmemoisation(input,dp,i+1,j,m,n);
		y=mincostmemoisation(input,dp,i+1,j+1,m,n);
		z=mincostmemoisation(input,dp,i,j+1,m,n);

	int res= input[i][j] + min(x,min(y,z));
  	if(i<m&&j<n)
		dp[i][j]=res;
	return res;

}


int minCostPathMEMOISATION(int **A, int m, int n) {
    
   int** in= new int*[m];
    for(int i=0;i<m;i++)
    {
    	in[i]=new int[n];
    }

    for(int i=0;i<m;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		in[i][j]=-1;
    	}

    }
  int x= mincostmemoisation(A,in,0,0,m,n);
  
  for(int i=0;i<m;i++)
    delete []in[i];
  
  return x;
}

int minCostPathDP(int **A, int m, int n)
{
	int** dp= new int*[m];
    for(int i=0;i<m;i++)
    	dp[i]=new int[n];
    dp[0][0]=A[0][0];
    for(int i=1;i<n;i++)
    {
    	dp[0][i]=A[0][i]+dp[0][i-1];
    }

    for(int i=1;i<m;i++)
    {
    	dp[i][0]=A[i][0]+dp[i-1][0];

    }


    for(int i=1;i<m;i++)
    {
    	for(int j=1;j<n;j++)
    	{
    		dp[i][j]=A[i][j]+ min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
    	}
    }

    return dp[m-1][n-1];



}


int main()
{
	int m,n;
	cin>>m>>n;

	int ** input= new int*[m];
    for(int i=0;i<m;i++)
    {
    	input[i]=new int[n];
    }
    

    for(int i=0;i<m;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		cin>>input[i][j];
    	}
    }
	cout<<minCostPathDP(input,m,n)<<endl;

	for(int i=0;i<m;i++)
		delete []input[i];

}