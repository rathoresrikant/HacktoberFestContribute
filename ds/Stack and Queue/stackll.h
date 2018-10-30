
template <typename T>
class Node {
    public :
    T data;
    Node<T> *next;
    
    Node(T data) {
        this -> data = data;
        next = NULL;
    }
};

template <typename T>
class Stack {
    Node<T> *head;
    int size;		// number of elements prsent in stack
    
    public :
    
    Stack() {
      head=NULL;
      size=0;
    }
    
    int getSize() {
       return size; 
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    void push(T element) {
      Node<T>* newnode=new Node<T>(element);
      newnode->next=head;
      head=newnode;
      size++;
    }
    
    T pop() {
        // Return 0 if stack is empty. Don't display any other message
      if(head==NULL)
        return 0;
      else
      {
        T ans=head->data;
        Node<T>* temp=head;
        head=head->next;
        size--;
        delete temp;
        return ans;
      }
      
    }
    
    T top() {
        // Return 0 if stack is empty. Don't display any other message
      if(head==NULL)
        return 0;
      else
      {
        return head->data;
      }
    }
};
