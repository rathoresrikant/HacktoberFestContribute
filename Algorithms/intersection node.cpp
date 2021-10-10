#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    
    node(int val)
    {
        data=val;
        next=NULL;
    }
    };
void insertAtTail(node* &head,int val)
    {
        if(head==NULL)
        {
            insertAtHead(head,val);
            return;
        }
        node* n=new node(val);
        node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
    }
    void insertAtHead(node* &head,int val)
    {
        node* n=new node(val);
        n->next=head;
        if(head!=NULL)
        {
            head=n;
        }
    }
    void intersect(node* &head1,node* &head2,int pos)
    {
        node* temp1=head1;
        while(pos)
        {
            if(temp1==NULL)
            pos--;
        }
    }
    void display(node* &head)
    {
        node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"-> ";
            temp=temp->next;
        }
        cout<<endl;
    }
    int length(node* head)
{
    int l=0;
    node* temp=head;
    while(temp!=NULL)
    {
        l++;
        temp=temp->next;
    }
    return l;
}



int main()
{
    node* head1=NULL;
    node* head2=NULL;
    insertAtTail(head1,1); 
    insertAtTail(head1,2);
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    insertAtTail(head1,5);
    insertAtTail(head1,6);
    insertAtTail(head2,9);
    insertAtTail(head2,10);
    intersect(head1,head2,5);
    
    
    
}
