#include<bits/stdc++.h>
using namespace std;

bool isVowel(char a)
{
	if(a=='A' || a=='a' || a=='E' || a=='e' || a=='I' || a=='i' || a=='O' || a=='o' || a=='U' || a=='u')
		return true;
	
	return false;
}

int main() {
	
	string s;
	cin>>s;
	
	string ans="";
	string temp="";
	for(int i=0;i<s.length();)
	{
		temp="";
		
		if(!isVowel(s[i]))
		{
			ans+=s[i];
			i++;
		}
		else
		{
			while(isVowel(s[i]))
			{
				temp+=s[i];
				i++;
			}
			
			if(temp.size()==1)
			{
				ans+=temp;
			}
		}
	}
	
	cout<<ans;
	return 0;
}