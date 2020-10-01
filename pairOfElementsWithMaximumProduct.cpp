#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
void pairofMaxproduct(int a[],int n){
   int min1 = INT_MAX, min2 = INT_MAX;
   int max1 = INT_MIN, max2 = INT_MIN;
   for(int i = 0 ; i < n ; i++){
    if(a[i] < min1){
        min2 = min1;
        min1 = a[i];
    }
    else if(a[i] < min2){
        min2 = a[i];
    }
    if(a[i] > max1){
        max2= max1;
        max1 = a[i];
    }
    else if(a[i] > max2){
        max2= a[i];
    }
   }
   if(max1*max2 > min1*min2){
    cout<<"the elements are "<<max1<<" and "<<max2<<endl;
   }
   else{
    cout<<"the elements are "<<min1<<" and "<<min2<<endl;
   }
}
int main(){
int n;
cin>>n;
int a[10000];
for(int i = 0 ; i  < n ; i ++){
    cin>>a[i];
}
pairofMaxproduct(a,n);
}
