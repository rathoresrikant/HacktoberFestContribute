#include <iostream>
#include<climits>
using namespace std;

int mcm_DP(int* p,int n)
{
  int** dp=new int*[n];
  for(int i=0;i<n;i++)
    dp[i]=new int[n];

  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(i==j)
          dp[i][i]=0;
        else
          dp[i][j]=-1;
      }
    }

  for(int L=0;L<n;L++)
  {
    for(int i=1;i<n-L-1;i++)
    {
        int j=i+L+1;
        dp[i][j]=INT_MAX;
        cout<<i<<" "<<j<<endl;
        for(int k=i;k<j;k++)
        {
          int min=dp[i][k]+dp[k+1][j] + p[i-1]*p[k]*p[j];
        cout<<dp[i][j]<<" "<<min<<" "<<p[i-1]*p[k]*p[j]<<endl;

          if(min<dp[i][j])
            dp[i][j]=min;
        }

    }
  }

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
      cout<<dp[i][j]<<" ";
    cout<<endl;
  }


  return dp[1][n-1];
    
}
int main()
{
  int n;
  cin>>n;
  int* p= new int[n+1];
  for(int i=0;i<n+1;i++)
    cin>>p[i];
  cout<<mcm_DP(p,n+1)<<endl;
}