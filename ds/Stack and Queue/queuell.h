//using namespace std;
template <typename T>
class node {
    public :
    T data;
    node<T> *next;
    
    node(T data) {
        this -> data = data;
        next = NULL;
    }
};

template<typename T>
class Queue {
    node<T>* front;
    node<T>* rear;
    int size;    
    public :
    Queue() {
      front=rear=NULL;
      size=0;
    }
    
    void enqueue(T data) {
       
       node<T>* newnode= new node<T>(data);
       if(rear==NULL)
       {
       	front=rear=newnode;
       } 
       else
       {
       	rear->next=newnode;
       	rear=newnode;
       }
       size++;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    T dequeue() {
        // Return 0 if queue is empty
        if(front==NULL)
        	return 0;
        T data=front->data;
        node<T>* temp=front;
        if(front->next==NULL)
        {
        	front=rear=NULL;
        }
        else
        	front=front->next;
        delete temp;
        size--;
        return data;
    }
    
    T getfront()  {
        // Return 0 if queue is empty
        if(front==NULL)
        	return 0;
        return front->data;
    }
};
