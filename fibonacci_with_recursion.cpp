#include<iostream>
using namespace std;
int fact(int num){
  if (num>1)
    return num*fact(num-1);
  else
    return num;
}
int main(){
  int num;
  cin>>num;
  cout<<fact(num);
  return 0;
}
