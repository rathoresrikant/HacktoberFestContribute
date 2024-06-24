#include <iostream>
#include <string.h>
 
using namespace std;
 
struct Node{
    int stu_no;
    char stu_name[50];
    int p;
    Node *next;
};
Node *top;
 
class stack{
 
public:
    void push(int n,char name[],int perc);
    void pop();
    void display();
};
 
void stack :: push(int n,char name[],int perc)
{
    struct Node *newNode=new Node;
    //fill data part
    newNode->stu_no=n;
    newNode->p=perc;
    strcpy(newNode->stu_name,name);
    //link part
    newNode->next=top;
    //make newnode as top/head
    top=newNode;
}
void stack ::pop()
{
    if(top==NULL){
        cout<<"List is empty!"<<endl;
        return;
    }
    cout<<top->stu_name<<" is removed."<<endl;
    top=top->next;
}
void stack:: display()
{
if(top==NULL){
        cout<<"List is empty!"<<endl;
        return;
    }
    struct Node *temp=top;
    while(temp!=NULL){
        cout<<temp->stu_no<<" ";
        cout<<temp->stu_name<<" ";
        cout<<temp->p<<" ";
        cout<<endl;
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
 
    stack s;
    char ch;
    do{
    int n;
     
    cout<<"ENTER CHOICE\n"<<"1.Push\n"<<"2.Pop\n"<<"3.Display\n";
    cout<<"Make a choice: ";
    cin>>n;
     
    switch(n){
        case 1:  
            Node n;
            cout<<"Enter details of the element to be pushed : \n";
            cout<<"Roll Number : ";
            cin>>n.stu_no;
            cout<<"Enter Name: ";
            std::cin.ignore(1);
            cin.getline(n.stu_name,50);
            cout<<"Enter Percentage: ";
            cin>>n.p;
             
            //push data into the stack
            s.push(n.stu_no,n.stu_name,n.p);
            break;
         
        case 2 : 
            //pop data from stack
            s.pop();
            break;
         
        case 3 : 
            //display data
            s.display();
            break;
             
        default : 
            cout<<"Invalid Choice\n";
    }
     
    cout<<"Do you want to continue ? : ";
    cin>>ch;
 
    }while(ch=='Y'||ch=='y');
     
    return 0;
}
