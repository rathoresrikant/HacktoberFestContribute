// Program to implement a stack using two queue 
#include<bits/stdc++.h> 
using namespace std; 
  
class Stack 
{  
    // Two inbuilt queues 
    queue<int> q1, q2; //by default,private
      
    // To maintain current number of 
    // elements 
    int curr_size; 
  
    public: 
    Stack() 
    { 
        curr_size = 0; 
    } 
  
    void push(int x) 
    { 
        curr_size++; 
  
        // Push x first in empty q2 
        
  
        if(q1.empty()==true)
        {
          q1.push(x);
          while(q2.empty()==false)
          {
            int m=q2.front();
            q1.push(m);
            q2.pop();
          }
        }
      else if(q2.empty()==true)
      {
        q2.push(x);
        while(q1.empty()==false)
        {
          int m=q1.front();
          q2.push(m);
          q1.pop();
        }
      }
        
    } 
  
    void pop(){ 
  
        // if no elements are there in q1  
        if(q1.empty()==false&&q2.empty()!=false)
        {
          q1.pop();
        }
      else if(q2.empty()==false&&q1.empty()!=false)
      {
        q2.pop();
      }
      else
      {
        cout<<"stack is empty"<<endl;
      }
    } 
  
    int top() 
    { 
        if(q1.empty()==false)
          cout<<q1.top()<<endl;
        else if(q2.empty()==false)
          cout<<q2.top()<<endl;
      
    } 
  
    int size() 
    { 
        return curr_size; 
    } 
}; 
  
// driver code 
int main() 
{ 
    Stack s; 
    s.push(1); 
    s.push(2); 
    s.push(3); 
  
    cout << "current size: " << s.size()  
         << endl; 
    cout << s.top() << endl; 
    s.pop(); 
    cout << s.top() << endl; 
    s.pop(); 
    cout << s.top() << endl; 
  
    cout << "current size: " << s.size()  
         << endl; 
    return 0; 
} 
