#include<bits/stdc++.h>
using namespace std;

//RECURSIVE
int knapsack(int wt[],int profit[],int w,int n){
    if(n==0 || w==0)return 0;
    if(wt[n]>w)return knapsack(wt,profit,w,n-1);
    else return max(knapsack(wt,profit,w,n-1),profit[n]+knapsack(wt,profit,w-wt[n],n-1));
}


//MEMOIZATION
int t[102][1002]; //constraints
int knap(int wt[],int profit[],int w,int n){
    if(n==0 || w==0)return 0;
    if(t[n][w]!=-1){
        return t[n][w];
    }
    if(wt[n]>w)return t[n][w]= knap(wt,profit,w,n-1);
    else return t[n][w]=max(knap(wt,profit,w,n-1),profit[n]+knapsack(wt,profit,w-wt[n],n-1));
}


//TOP DOWN
int knapTopDown(int wt[],int profit[],int w,int n){
    int t[n+1][w+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=j){
                t[i][j]=max(profit[i]+t[i-1][j-wt[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][w];
}



int main(){
    int n;
    cin>>n;
    int vals[n];
    int wts[n];
    for(int i=0;i<n;i++){
        cin>>vals[i];
    }
    for(int i=0;i<n;i++){
        cin>>wts[i];
    }
    int cap;
    cin>>cap;
    //recursive
    int profit=knapsack(wts,vals,cap,n-1);
    cout<<profit<<endl;
    //memoization
    memset(t,-1,sizeof(t));
    int pro=knap(wts,vals,cap,n-1);
    cout<<pro<<endl;
    //top down
    int ni=knapTopDown(wts,vals,cap,n-1);
    cout<<ni<<endl;
    
}