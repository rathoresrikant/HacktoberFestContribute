#include<iostream>
#include<string>
using namespace std;
int main()
{
string s;
cin>>s;
for(int i=0;i<=s.length();i++) { 
 if(s[i]>=65 && s[i]<=92)
      {
	  s[i]=s[i]+32;
      }
   }
   cout<<"The entered string in lowercase: "<<s;

return 0;
}
