#include <iostream>
#include <vector>
#include<math.h>
#include<unordered_map>
using namespace std;
//EFFICIENT BUT WRONG.
//WE HAVE TO TAKE CARE OF THE SEQUENCE OF THE ELEMENTS IN THE STRING TOO. 
//LIKE: ABC AND DCB WILL NOT HAVE  1 STEP BUT MINIMUM 3 STEPS TO BECOME EQUAL.
/*
int editDistance(string s1, string s2){

  unordered_map<char,int>m;
  for(int i=0;i<s1.size();i++)
  {
    m[s1[i]]++;
  }
  
  int count1=0;
  int count2=0;
  
  for(int i=0;i<s2.size();i++)
  {
    if(m.find(s2[i])!=m.end())
    {
      if(m[s2[i]]>0)
        m[s2[i]]--;
      else
        count2++;
    }
    else
      count2++;
  }
  
  unordered_map<char,int>::iterator it;
  for(it=m.begin();it!=m.end();it++)
  {
    if(it->second!=0)
      count1=count1+it->second;
  }
  
  int res= min(count1,count2) + abs(count1-count2);
  cout<<count1<<" "<<count2<<" "<<res<<endl;
  return res;
}
*/
int editDistance(string s1, string s2){
 if (s1.size() == 0) 
      return s2.size();
  	if (s2.size() == 0)
      return s1.size();
  	if(s1[0] == s2[0])
    return editDistance(s1.substr(1) , s2.substr(1));
  else
  {
    int x = editDistance(s1 , s2.substr(1));
    int y = editDistance(s1.substr(1) , s2);
    int z = editDistance(s1.substr(1) , s2.substr(1));
    return min(x+1,min(y+1,z+1));
  }
}

int editDistancememoisation(string s1, string s2, int**dp)
{
  if(s1.size()==0||s2.size()==0)
  {
    if(s1.size()>s2.size())
    {
      dp[s1.size()][s2.size()]=s1.size()-s2.size();
      return s1.size()-s2.size();
    }

    dp[s1.size()][s2.size()]=s2.size()-s1.size();
    return s2.size()-s1.size();
  }
  int i=s1.size();
  int j=s2.size();

  if(dp[i][j]!=-1)
    return dp[i][j];

  if(s1[0]==s2[0])
  {
    dp[i][j]=editDistancememoisation(s1.substr(1),s2.substr(1),dp);
    return dp[i][j];
  }

  int x=editDistancememoisation(s1.substr(1),s2,dp);
  int y=editDistancememoisation(s1,s2.substr(1),dp);
  int z=editDistancememoisation(s1.substr(1),s2.substr(1),dp);

  dp[i][j]=1+min(x,min(y,z));
  return dp[i][j];
}

int editDistanceMEMOISATION(string s1, string s2)
{
  int**dp=new int*[s1.size()+1];

  for(int i=0;i<s1.size()+1;i++)
  {
    dp[i]=new int[s2.size()+1];
    for(int j=0;j<s2.size()+1;j++)
      dp[i][j]=-1;
  }

  int x=editDistancememoisation(s1,s2,dp);
  for(int i=0;i<s1.size()+1;i++)
  {
    for(int j=0;j<s2.size()+1;j++)
    {
      if(dp[i][j]==-1)
        cout<<"X ";
      else
        cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }
  return x;



}

int editDistanceDP(string s1, string s2)
{
  int m=s1.size()+1;
  int n=s2.size()+1;
  int**dp=new int*[m];
  for(int i=0;i<m;i++)
    dp[i]=new int[n];

  for(int i=0;i<m;i++)
    dp[i][0]=i;

  for(int j=0;j<n;j++)
    dp[0][j]=j;

  for(int i=1;i<m;i++)
  {
    for(int j=1;j<n;j++)
    {
      if(s1[m-1-i]==s2[n-1-j])//OR WE CAN DO if(s1[i-1]==s2[j-1])
      {
        cout<<s1[i]<<" "<<s2[j]<<endl;
        dp[i][j]=dp[i-1][j-1];
      }
      else
        dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
    }
  }

   for(int i=0;i<s1.size()+1;i++)
  {
    for(int j=0;j<s2.size()+1;j++)
    {
        cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }

  return dp[m-1][n-1];

}

int main()
{
  string s1,s2;
  cin>>s1>>s2;
  cout<<editDistance(s1,s2)<<endl;
  cout<<editDistanceMEMOISATION(s1,s2)<<endl;
  cout<<editDistanceDP(s1,s2)<<endl;
}


