#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int fibo(int n){
    int ans=1,tp1=1,tp2=1;
    while( (n-2)>0){
        tp2=ans;
        ans+=tp1;
        tp1=tp2;
        n--;
    }
    return ans;
}

int prime(int n){
    int flag=0,count=0,ans=2;
    for(int i=2;i<9999;i++){
        flag=0;
        if(count==n)    return ans;
        for(int j=2;j<i;j++){
            if(i%j==0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            ans=i;
            count++;
        }
    }
}

void digit(int n){
    int d[20];
    int tp1,i=0;
    while(n>0){
        tp1=n%10;
        n=n/10;
        d[i]=tp1;
        cout<<d[i]<<" ";
        i++;
    }
    
}

int main()
{
    digit(1043110);
    return 0;
}
