#include <iostream>
#include <stdlib.h>
using namespace std;
struct node {
int data;
node* link ;
};
node *head;
void input(int x,int n)
{
node * temp = new node();
temp->data = x;
temp->link = NULL;
if (n==1){
    temp->link =head;
    head = temp;
    return;
}
node *temp1= head;
for (int i=0;i<n-2;i++ ){
    temp1 = temp1->link;
}
temp->link = temp1->link;
temp1->link = temp;

}
void rev(){
node* prev = NULL;
node * current = head;
node * Next ;
while (current != NULL){
        Next = current->link;
        current->link= prev;
        prev = current;
        current = Next;
        if (current->link == NULL){
        current ->link = prev;
        head = current;
        return ;
        }



}
} // ENDing of the void function

void Print (){
node* temp = head;
while (temp != NULL){
        cout<<temp->data;
    temp = temp->link;
 }
}
int main () {
    head = NULL;
    input (2,1);
    input (4,2);
    input (6,3);
    input (8,4);
    Print ();
    rev();
    Print();

return 0;
}
