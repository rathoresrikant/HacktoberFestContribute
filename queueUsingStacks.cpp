#include <iostream>
#include<stack>
using namespace std;
class Q{
    stack<int> st1, st2;
    public:
    void NQ(int data){
        st1.push(data);
    }
    void DQ(){
        if(st1.empty() && st2.empty()){
            cout<<"Q underflow\n";
        }
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            cout<<" Dequed "<<st2.top()<<endl;
            st2.pop();
        }
        if(st1.empty()){
            while(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
            
        }
    }
    
};
int main()
{
 Q st;
 st.NQ(1);
 st.NQ(2);
 st.NQ(3);
 
 st.DQ();
 st.DQ();

    return 0;
}