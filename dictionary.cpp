#include<iostream>
#include<cstring>
using namespace std;

bool myCompare(string a,string b)
{
    if(a<b)
    {
        return true;
    }
    return false;
}
void dictionarySmaller(string ans,string input,int i){
    if(ans[i]=='\0')
    {
        //int res=strcmp(input,ans);
        if(myCompare(ans,input))
        {
        cout<<ans<<endl;
        }
        return;
    }
    for(int j=i;input[j]!='\0';j++)
    {
    
        swap(ans[i],ans[j]);
        dictionarySmaller(ans,input,i+1);
        //swap(ans[l],ans[i]);
    }
}
int main() {
    string ans;
    string input;
    cin>>ans;
    input=ans;
    dictionarySmaller(ans,input,0);
	return 0;
}
