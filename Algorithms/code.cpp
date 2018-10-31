#include<bits/stdc++.h> 
using namespace std; 
#define MAX 10000 
class Stack 
{ 
    int top; 
public: 
    char a[MAX];    
    Stack()  { top = -1; } 
    bool push(char x); 
    char pop(); 
    bool isEmpty(); 
}; 
  
bool Stack::push(char x) 
{ 
    if (top >= (MAX-1)) 
    { 
        return false; 
    } 
    else
    { 
        a[++top] = x;  
        return true; 
    } 
} 
  
char Stack::pop() 
{ 
    if (top < 0) 
    { 
        return 0; 
    } 
    else
    { 
        char x = a[top--]; 
        return x; 
    } 
} 
  
bool Stack::isEmpty() 
{ 
    return (top < 0); 
}

void reverse(Stack k) 
{ 
    while(!k.isEmpty()) 
    { 
        k.pop(); 
    } 
}  
int main() 
{ 
    struct Stack s; 
    string str;
    cin>>str;
    for(int i=0;i<str.length();i++)
    s.push(str[i]);
    for(int i=0;i<str.length();i++)
    cout<<s.pop();
    cout<<endl;
    return 0; 
} 