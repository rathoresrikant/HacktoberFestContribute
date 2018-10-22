
// A simple C++ code to remove all the vowels from given string and printing the remaining string after this operation.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin>>S;                                                             //input of String.
    int l=S.size();
    for(int i=0;i<l;i++)
    {
        char vow = tolower(S[i]);
        
        if(vow=='a' ||vow=='e' || vow=='i' || vow=='o' || vow=='u')
        {
            S.erase(S.begin()+i);                                        //erasing vowel if present.
        }
    }
    cout<<S;                                                             //output of remaining String.    
    return 0;
}
