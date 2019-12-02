#include<iostream>
#include<queue>
using namespace std;
int main()
{
priority_queue<int,vector<int> ,greater<int> > p;
int n,k;
cin>>k;
cin>>n;
int arr[n];
int data;
for(int i=0;i<k;i++)
{
 for(int j=0;j<n;j++)
 {
     cin>>data;
      p.push(data);
 }

}
 while(!p.empty())
  {
      cout<<p.top()<<" ";
      p.pop();

  }
}
