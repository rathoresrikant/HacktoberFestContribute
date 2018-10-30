#include <iostream>
using namespace std;

//SEEMS WRONG BUT ONE TEST CASE WORKS OTHERS, TLE
string solve(int n, int x, int y, string s="Beerus")
{
	// Write your code here .
  if(n<=0)
    return s;
  
  if(s.compare("Beerus")==0)
    s="Whis";
  else
    s="Beerus";
  
  int b=0,w=0;
  string s1=solve(n-1,x,y,s);
  if(s1.compare("Beerus")==0)
    b++;
  else
    w++;
  
  string s2=solve(n-x,x,y,s);
  if(s2.compare("Beerus")==0)
    b++;
  else
    w++;
  
  string s3=solve(n-y,x,y,s);
  if(s3.compare("Beerus")==0)
    b++;
  else
    w++;
  //cout<<b<<" "<<w<<endl;
  if(b>w)
    return "Whis";
  else
    return "Beerus";
  
}

