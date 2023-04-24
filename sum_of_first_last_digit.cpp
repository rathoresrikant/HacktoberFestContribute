#include<iostream>
using namespace std;

typedef long long ll;
 
 ll i,j;
 
  
   int main()
{
     Fast;
     
   ll t,s;// declaring data type of test case t and sum s//
    cin>>t;
       
      while(t--)
      {
          ll n;  // declaring data type of n as long long//
          cin>>n;
          ll s,f,l;
          l=n%10; // This is to get the last number l//
          f=n; //f is the first number//
          while(n>=10)
          {
              n=n/10; // dividing the number n by 10 till we do not get the first term//
          }
          f=n;
          s = (l+f); // Here, it's the sum of first digit f and last digit l;
          
          cout<<s<<endl; // it is the required output sum s//
      }
      return 0;
 }
