#include<iostream>
#include<string.h>
using namespace std;

int main(){
  string pat;
  cin>>pat;
  int n = pat.size();

  int i=1,j=0;
  int a[n];
  a[0]=0;

  while(i<n){
    if(pat[j]==pat[i]){
    //  cout<<1;
      a[i]=j+1;
      i++;
      j++;
    }
    else if(j>0)
        j=a[j-1];
    else{
        a[i]=0;
        i++;
    }
  }
  // for(int i=0 ; i<n ; i++)
  //         cout<<a[i]<<"\t";

string ms;
cin>>ms;
int h=0,l=0;
while(l < ms.size()){
  if(pat[h]==ms[l])
  {
    if(h==n-1)
      {
          cout<<"total number of shifts to find match "<<l-h<<endl;
          break;
      }
    else
        {
            h++;
            l++;
        }
  }
    else if(h>0)
            h=a[h-1];

    else
            l++;

}

}
