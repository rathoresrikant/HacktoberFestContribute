#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void InsertNode(Node *&tail, int element, int d)
{
    if (tail == NULL)
    { // empty list
        Node *NN = new Node(d);
        tail = NN;
        NN->next = NN;
    }
    else
    {
        Node *temp = tail;
        while (temp->data != element)
        {
            temp = temp->next;
        }
        Node *NN = new Node(d);
        NN->next = temp->next;
        temp->next = NN;
    }
}

void display(Node *&tail)
{
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
}

void deleteNode(Node *&tail, int value)
{
    Node *p = tail;
    Node *q = NULL;
    do
    {
        q = p;
        p = p->next;
    }

    while (p != tail && (p->data) != value);
   
    q->next = p->next;
    p->next = NULL;
}

int main()
{
    Node *tail = NULL;
    InsertNode(tail, 5, 3);
    InsertNode(tail, 3, 6);
    InsertNode(tail, 6, 9);
    InsertNode(tail, 9, 17);
    InsertNode(tail, 17, 14);
    cout<<"The linked list before deletion is :"<<endl;
    display(tail);
    cout<<endl;
    deleteNode(tail, 6);
    cout<<"The linked list after deletion is :"<<endl;
    display(tail);

    return 0;
}