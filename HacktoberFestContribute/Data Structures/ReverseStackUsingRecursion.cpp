
#include <iostream>
#include <stack> 
using namespace std;

void addtoBottom(stack<int> *st,int z){
    if(st->empty()){
        st->push(z);
        return;
    }
    int x=st->top();
    st->pop();
    addtoBottom(st,z);
    st->push(x);
}

void reverseStack(stack<int> *st){
    if(st->empty()) return;
    int y=st->top();
    st->pop();
    reverseStack(st);
    addtoBottom(st,y);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
   reverseStack(&st);
   while(!st.empty()){
       cout<<st.top();
       st.pop();
   }

    return 0;
}
