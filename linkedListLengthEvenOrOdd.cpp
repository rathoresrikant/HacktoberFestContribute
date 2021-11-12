#include<iostream>
using namespace std;
class node
{
   public:
    int data;
    node*next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
};

void insertionatend(node*&head,node*&tail,int d)
{
    if(head==NULL)
    {
        node* n=new node(d);
        head=n;
        tail=n;
        return;
    }

    node* n=new node(d);
    tail->next=n;
    tail=n;
}

int length(node*head)
{
    int count=0;
    while(head)
    {
        count++;
        head=head->next;

    }
    return count;
}

int main()
{
    node*head=NULL;
    node*tail=NULL;

    insertionatend(head,tail,5);
    insertionatend(head,tail,4);
    insertionatend(head,tail,3);
    insertionatend(head,tail,2);
    insertionatend(head,tail,1);
    insertionatend(head,tail,0);
    int l = length(head);
    if(l%2 == 0){
        cout<<"YES, length is even"<<endl;
    }
    else{
        cout<<"NO, length is odd"<<endl;
    }
    return 0;
}

