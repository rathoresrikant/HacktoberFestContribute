#include <iostream>
using namespace std;

struct Node{
  int data;
  Node*next=NULL;
};
class list{
  Node* last=NULL;
public:
  void insert(int data){
    Node* node= new Node;
    node->data=data;
    if(last==NULL){
      last=node;
      last->next=last;
    }else{
      node->next=last->next;
      last->next=node;
      last=node;
    }
  }
  //inserton at the last of the list
  void insertAtlast(int data){
    Node* node= new Node;
    node->data=data;
    node->next=last->next;
    last->next=node;
    last=node;
  }
  //insertion at the front of the list
  void insertAtFront(int data){
    Node* node= new Node;
    node->data=data;
    node->next=last->next;
    last->next=node;
  }
  void show(){
    Node* n=last->next;
    if(last==NULL){
      cout<<"list is empty"<<endl;
      return;
    }
    do {
      cout<<n->data<<" ";
      n=n->next;
    } while(n!=last->next);
    cout<<endl;
  }

};

int main(){
  list x;
  for(int i=0;i<5;i++){
    x.insert(i+1);
  }
  x.insertAtlast(6);
  x.insertAtFront(7);
  x.show();
}
