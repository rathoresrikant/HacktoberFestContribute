#include<bits/stdc++.h>
using namespace std;

main()
 {
 	string s;
 	cin>>s;
    string p;
    cin>>p;
    sort(s.begin(),s.end());
    sort(p.begin(),p.end());

    if(s==p)
    	cout<<"The strings are anagrams"<<"\n";
    else
    	cout<<"The strings aren't anagrams"<<"\n";
 }