#include <iostream>
using namespace std;

int countWaysToMakeChange_recursive(int den[], int n, int value){

  if(n==0)
    return 0;
  if(value<0)
    return 0;
  if(value==0)
    return 1;
  
  int count=0;
  count=countWaysToMakeChange_recursive(den+1,n-1,value);
  count+=countWaysToMakeChange_recursive(den,n,value-den[0]);
  return count;

}

int countWaysToMakeChange_DP(int den[], int n, int value){
  int** dp = new int*[n+1];
  for(int i=0;i<n+1;i++)
    dp[i]=new int[value+1];

  for(int i=0;i<=value;i++)
    dp[0][i]=0;
  for(int j=0;j<n+1;j++)
    dp[j][0]=1;         //OUR ASSUMPTION THAT THE WAYS IN WHICH WE CAN PAY WHEN VALUE=0 IS 1
                        //ALSO, THE DIFFERENCE BETWEEN VALUE AND COIN WHEN REDUCES TO 0, IT GIVES 1 WAY TO EXCHANGE USING THAT COIN.

  for(int j=1;j<=value;j++)
  {
    for(int i=1;i<=n;i++)
    {
      dp[i][j]=dp[i-1][j];
      if(j-den[i-1]>=0)
        dp[i][j]+=dp[i][j-den[i-1]];
    }
  }
return dp[n][value];


}


int main()
{
  int d;
  cin>>d;
  int * a=new int[d];
  for(int i=0;i<d;i++)
    cin>>a[i];
  int v;
  cin>>v;
  cout<<countWaysToMakeChange_DP(a,d,v)<<endl;

}

/*
int countWaysToMakeChange_DP(int den[], int n, int value){
  int* dp=new int[value+1];//WRONG AS IN THIS QUESTION, THE DEPENDENCY IS UPON 2 THINGS: THE NUMBER AND THE COIN ARRAY. SO A 2D MATRIX IS NEEDED.

  for(int i=0;i<n;i++)
    dp[den[i]]=1;
  
  for(int i=0;i<=value;i++)
  {

    int count=0,count2;
    if(dp[i]==1)
      count=dp[i];
    for(int j=0;j<n;j++)
    {
      count2=0;
      if(i-den[j]>=0)
        count2+=dp[i-den[j]];
      int rem=i-den[j];
      for(int k=0;k<n;k++)
      {
        if(k==j)
          continue;
        if(rem-den[k]>=0)
        count2+=dp[rem-den[k]];
      }
      //cout<<count2<<endl;
      if(count<count2)
        count=count2;
    }

    dp[i]=count;
  }

  for(int i=0;i<value+1;i++)
    cout<<dp[i]<<" ";
  return dp[value];

}

*/

/*
//INSHAHALLAH THE BOYS PLAYED WELL.
//TRY BETTER NEXT TIME
int countWaysToMakeChange(int den[], int numD, int value){

  int* dp=new int[value+1];
  sort(den,den+numD);
  
  if(den[0]>value)
    return 0;
  int flag=0;
  for(int i=0;i<den[0];i++)
    dp[i]=0;
  
  for(int i=den[0];i<=value;i++)
  {
    dp[i]=0;
    flag=0;
    for(int j=0;j<numD&&i>=den[j];j++)
    {
      
      int rem=i-den[j];
      dp[i]+=dp[rem];
      if(i==den[j])
        dp[i]++;
      cout<<i<<" "<<dp[i]<<endl;

      for(int k=0;k<numD&&i>=den[k];k++)
      {
        if(i-den[j]==den[k]&&den[j]!=den[k])
          {
            if(flag==0)
            {
              flag=1;
              dp[i]-=min(dp[den[j]],dp[den[k]]);
            }

          }
        if(den[k]!=den[j]&&den[k]%den[j]==0)
          dp[i]-=min(dp[i-den[j]],dp[i-den[k]]);
      }
      
    }
    
  }
   for(int i=0;i<value+1;i++)
    cout<<dp[i]<<" ";
  return dp[value];
}

*/