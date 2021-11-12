/* Equal Sum partiton

 Solution by : Supriya2301

 */



#include<bits/stdc++.h>
using namespace std;

// function for checking subset sum
bool subsetsum(int arr[], int n, int sum)
{

   bool dp[n+1][sum+1];

   for(int i=0;i<n+1;i++)
   {
       for(int j=0;j<sum+1;j++)
       {
           if(i==0) dp[i][j] = false;
           if(j==0) dp[i][j] = true;
       }
   }

   for(int i=1;i<n+1;i++)
   {
       for(int j=1;j<sum+1;j++)
       {
           if(arr[i-1]<=j)
           {
               dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
           }
           else{
               dp[i][j] = dp[i-1][j];
           }
       }
   }

  return dp[n][sum];
}

int main()
{    // taking array as user input
     int n;
     cout<<"Enter number of elements: "<<endl;
     cin>>n;

     int arr[n];
     cout<<"Enter array elements: "<<endl;
     for(int i=0;i<n;i++)
     {
         cin>>arr[i];
     }

     // finding sum of array
     int sum = 0;
  for(int i=0;i<n;i++)
  {
      sum += arr[i];
  }
  // if sum is odd , then we can not partition into equal sum
  if(sum%2 != 0 )  cout<<"Not possible";
  else{
      if(subsetsum(arr,n,sum/2)) // we will check for subset having sum = sum/2
      {
          cout<<"Possible";
      }
      else{
          cout<<"Not possible";
      }
  }

    return 0;
}
