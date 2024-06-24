#include<bits/stdc++.h>
using namespace std;



main()
 {
 	string s;
 	cin>>s;
    string x="";
    int i;
    for(i=0;i<s.length();i++)
    {
    	if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
    		continue;
    	x+=s[i];
    }
    cout<<x<<"\n";

 }