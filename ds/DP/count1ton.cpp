#include<iostream>
#include<climits>
using namespace std;

//NAIVE RECURSIVE APPROACH O(2^N)
int countStepsTo1RECURSIVE(int n,int count=0){
  if(n==1)
    return 0;
  int k1=INT_MAX,k2=INT_MAX,k3=INT_MAX;
  k1=1+countStepsTo1RECURSIVE(n-1);
  
  if(n%2==0)
  	k2=1+countStepsTo1RECURSIVE(n/2);
  
  if(n%3==0)
    k3=1+countStepsTo1RECURSIVE(n/3);
  
  return min(k1,min(k2,k3));
  
}

//MEMOIZATION APPROACH O(N)
int countStepsTo1memoization(int n,int* ans){
  if(n==1)
    return 0;
  if(n==2)
    return 1;
  if(n==3)
    return 1;
  int k1=INT_MAX,k2=INT_MAX,k3=INT_MAX;
  
  if(ans[n-1]!=-1)
    k1=ans[n-1];
  else k1=countStepsTo1memoization(n-1,ans);
  
  if(n%2==0)
    if(ans[n/2]!=-1)
    	k2=ans[n/2];
    else k2=countStepsTo1memoization(n/2,ans);
  
  if(n%3==0)
    if(ans[n/3]!=-1)
    	k3=ans[n/3];
    else k3=countStepsTo1memoization(n/3,ans);
  
  return 1+min(k1,min(k2,k3));
  
}


int countStepsTo1MEMOIZATION(int n)
{
  int* ans= new int[n+1];
  
  for(int i=0;i<=n;i++)
    ans[i]=-1;
  
  return countStepsTo1memoization(n,ans);
}


//DYNAMIC PROGRAMMING APPROACH O(N)----BEST APPROACH
int countStepsTo1DP(int n)
{
  int* ans= new int[n+1];
  ans[0]=0;
  ans[1]=0;
  ans[2]=1;
  ans[3]=1;
  for(int i=4;i<=n;i++)
  {
    ans[i]=ans[i-1];
    if(i%2==0)
      ans[i]=min(ans[i],ans[i/2]);
    if(i%3==0)
      ans[i]=min(ans[i],ans[i/3]);
    ans[i]=ans[i]+1;
  }
  return ans[n];
}


int main()
{
	//cout<<countStepsTo1RECURSIVE(100);
	cout<<countStepsTo1MEMOIZATION(100);
	cout<<countStepsTo1DP(100);
}
