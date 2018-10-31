#include <iostream>
#include <stack>
using namespace std;

void reverseStack2(stack<int> &s1, stack<int> &s2) 
{
        
        if(s1.empty())
            return;
        int a=s1.top();
        s1.pop();
        reverseStack2(s1,s2);    //assume it comes back with reverse stack 
        while(!s1.empty())
        {
            int x=s1.top();
            s1.pop();
            s2.push(x);
        }
        s1.push(a);
        while(!s2.empty())
        {
            int x=s2.top();
            s2.pop();
            s1.push(x);
        }
}


void reverseStack(stack<int> &s1, stack<int> &s2,int c=0) {
        
        //reverse(s1,s2);
        if(c==0)
        {
            c=s1.size();
            cout<<c<<" "<<s1.size();
        }
        if(s1.empty())
            return;
        int a=s1.top();
        s1.pop();
        //cout<<count<<" "<<a<<endl;
        reverseStack(s1,s2,c);//assume it comes back with reverse stack 
        s2.push(a);
        cout<<c<<" "<<s2.size()<<endl;
        if(c==s2.size())
        {
            
            while(!s2.empty())
            {   
                int k=s2.top();
                s2.pop();
                //cout<<k<<endl;
                s1.push(k);
            }
        }
        

}

    int main() 
    {
        
        stack<int> s1,s2;
        int n,x,i=1;
        cin>>n;
        while(i<=n)
        {
            cin>>x;
            s1.push(x);
            i++;
        }
        reverseStack(s1,s2);
        while(!s1.empty())
        {
            cout<<s1.top()<<" ";
            s1.pop();
        }
    }