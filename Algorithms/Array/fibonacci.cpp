#include<iostream>
#include<iomanip>
using namespace std;
int fibonacci(int n)            // Function that return nth term of fabonacci series using recurrsion
{
    if(n==1) return 0;
    else if(n==2) return 1;
    else return ( fibonacci(n-1)+fibonacci(n-2));
} 

void FibonacciSeries(int n)  // Function to print fabonacci series
{
    for(int i=1;i<=n;i++)   cout<<fibonacci(i)<<'\t';
}
int main(){
    
        int n;  //n=upto which term you want to print fabonacci series
        cin>>n;
        FibonacciSeries(n);
        return 0; 
}