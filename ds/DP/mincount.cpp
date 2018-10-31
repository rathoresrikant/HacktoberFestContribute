#include<math.h>
#include<climits>
//DP METHOD. MOST EFFICIENT
int minCountDP(int n){

  if(n==0)
    return 0;
  if(n==1)
    return 1;
  int * ans=new int[n+1];
  ans[0]=0;
  ans[1]=1;
  for(int i=2;i<=n;i++)
  {
    int min=INT_MAX;
    for(int j=1;j<=sqrt(i);j++)
    {
      int k=1+ans[i-j*j];
      if(k<min)
        min=k;
    }
    ans[i]=min;
  }

  return ans[n];
  
}


//MEMOIZATION
int minCountMemoization(int n,int* ans){
  if(n==0)
    return 0;
  if(n==1)
    return 1;
  int k=sqrt(n);
  int m,min=INT_MAX;
  for(int i=1;i<=k;i++)
  {
    if(ans[n-i*i]!=-1)
      m=1+ans[n-i*i];
    else
    {
      m=1+minCountMemoization(n-i*i,ans);
    }
    //cout<<m<<endl;
    if(min>m)
    {
      min=m;
      ans[n]=min;//VERY IMPORTANT STEP. DON'T SAVE EVERY VALUE OF RECURSION AS IT WILL DO THAT ALREADY. JUST SAVE END VALUE.
    }
      
  }
  return min;
}
  
int minCountMEMOIZATION(int n){
  
  int * ans=new int[n+1];
  for(int i=0;i<n+1;i++)
    ans[i]=-1;
  
  int k= minCountMemoization(n,ans);
  //for(int i=0;i<n+1;i++)
    //cout<<ans[i]<<" ";
  return k;
}



//RECURSIVE WORST
int minCountRecursive(int n){
    
  if(n<=0)
    return 0;
  if(n==1)
    return 1;
  
  int k=sqrt(n);
  int min2=INT_MAX;
  int min1=1+minCountRecursive(n-k*k); //BTW IT IS WRONG. YOU HAVE TO FIND OUT MIN FROM 1 TO SQRT(N)
  if(k>1)
  min2=1+minCountRecursive(n-(k-1)*(k-1));
  
  return min(min1,min2);  
}


int main()
{
  cout<<minCountRecursive(18)<<endl;
  cout<<minCountMEMOIZATION(18)<<endl;
  cout<<minCountDP(18)<<endl;
}