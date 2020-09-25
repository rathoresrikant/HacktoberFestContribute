Code : Stack Using LL

Implement a Stack Data Structure specifically to store integer data using a Singly Linked List.
The data members should be private.
You need to implement the following public functions :
1. Constructor:
It initialises the data members as required.
2. push(data) :
This function should take one argument of type integer. It pushes the element into the stack and returns nothing.
3. pop() :
It pops the element from the top of the stack and in turn, returns the element being popped or deleted. In case the stack is empty, it returns -1.
4. top :
It returns the element being kept at the top of the stack. In case the stack is empty, it returns -1.
5. size() :
It returns the size of the stack at any given instance of time.
6. isEmpty() :
It returns a boolean value indicating whether the stack is empty or not.
*************************************************************************************************************************************************************************
template <typename T>
class Stack {
    Node<T> *head;
    int size;		// number of elements prsent in stack
    
    public :
    
    Stack() {
        size=0;
        head = new Node<T>(0);
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        if(size==0)
            return true;
        return false;
    }
    
    void push(T element) {
        Node<T>* newHead=new Node<T>(element);
        newHead->next=head;
        head=newHead;
        size++;

    }
    
    
    //vvi function
    T pop() {
        // Return 0 if stack is empty. Don't display any other message
        if(size==0)
            return 0;
        else{
            T ans=head->data;
            Node<T>* temp=head->next;
            head->next=NULL;
            head=temp;
            size--;
            return ans;
        }
    }
    
    T top() {
        // Return 0 if stack is empty. Don't display any other message
        if(size==0)
            return 0;
        else{
            T ans=head->data;
            return ans;
        }
    }
    
  
    
};




#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};


int main() {
    Stack st;

    int q;
    cin >> q;

    while (q--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                st.push(input);
                break;
            case 2:
                cout << st.pop() << "\n";
                break;
            case 3:
                cout << st.top() << "\n";
                break;
            case 4:
                cout << st.getSize() << "\n";
                break;
            default:
                cout << ((st.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}
