// Implementation of Longest Common Subsequence problem in C++ using Dynamic Programming

#include<bits/stdc++.h> 
using namespace std; 
 
int main(){ 
    string a,b;
    cin>>a>>b;

    int m=a.size(),n=b.size();

    int dp[m+1][n+1]; 
    int i,j;

    for(i=0;i<=m;i++){ 
        for(j=0;j<=n;j++){ 
            if(i==0 || j==0) dp[i][j]=0; 
            else if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1; 
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]); 
        } 
    }

    cout<<"Length of LCS is "<<dp[m][n]; 
    
    return 0; 
} 
