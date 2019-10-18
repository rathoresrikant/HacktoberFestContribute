#include<iostream>
using namespace std;

struct node
{
int pos;
struct node *next;
node(int pos){
    this->pos=pos;
}
};

node* LastAdd(node* last, int pos){
node* temp=new node(pos);
if(last==NULL){
    temp->next=temp;
    last=temp;
    return last;
}
temp->next = last->next;
last->next=temp;
last=temp;
return last;
}


int main(){
int n;
int *arr;
arr=new int(n);
cin>>n;
node* last=NULL;
for(int i=0;i<n;i++){
    cin>>arr[i];
    last=LastAdd(last,arr[i]);
}
node* curr=last->next;
node* prev=last;
// check for circular linked list is created
int limit;
cin>>limit;//limit is number of elements to be printed
int i=0;
//

while(curr->next!=0 && i<limit){
    cout<<curr->pos<<" ";
    curr=curr->next;
    i++;
}

}
