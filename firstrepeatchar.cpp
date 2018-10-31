#include<bits/stdc++.h>
using namespace std;
int main()
 {
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    int i;
	    int coun[26]={0};
	    pair<int,int> x[26];
	    for(i=0;i<26;i++)
	    {
	       x[i].first=0;
	       x[i].second=-1;
	    }
	    for(i=0;i<s.length();i++)
	    {
	       x[s[i]-'a'].first++;
	       if(x[s[i]-'a'].second==-1)
	         x[s[i]-'a'].second=i;
	    }
	    int index=n+1;
	    for(i=0;i<26;i++)
	    {
	        if(x[i].first==1)
	         {
	             index=min(index,x[i].second);
	         }
	    }
	    if(index==n+1)
	    {
	        cout<<"-1"<<"\n";
	    }
	    else
	    cout<<s[index]<<"\n";
	}
	return 0;
}