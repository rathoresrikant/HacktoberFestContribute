#include <iostream>
using namespace std;
int main()
{
  int n1,n2;
  cout<<"Enter two numbers\n";
  cin>>n1>>n2;
  cout<<"number1= "<<n1<<"\nnumber2= "<<n2<<"\n";
  n1=n1+n2;
  n2=n1-n2;
  n1=n1-n2;
  cout<<"After swapping: \n";
  cout<<"number1= "<<n1<<"\nnumber2= "<<n2<<"\n";
}
