#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};
struct Node *head=NULL;
/* Function to Insert a node in beginning */
void Insert(int dataToBeInserted)
{
    struct Node* curr = new Node;
    curr->data = dataToBeInserted;
    curr->next = NULL;
    if(head == NULL)
            head=curr; //If this is first node make this as head of list

    else
        {
            curr->next = head; //else make the curr (new) node's next point to head and make this new node a the head
            head=curr;
        }


}

//display linked list
void display()
{
    struct Node *temp= head;
    while(temp!=NULL)
        {
            if(temp->next!=NULL)
            cout<<temp->data<<"->";
            else
            cout<<temp->data;

            temp=temp->next; //move to next node
        }

    cout<<endl;
}

// function to get the length of linked list
int getLength()
{
    int length = 0;  // Initialize length
    struct Node* current = head;  // Initialize current
    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    return length;
}

//Main function
int main()
{
    //Initial list has no elements
    // Insert elements to the Linked List
    Insert( 9);
    Insert( 8);
    Insert(7);
    Insert(6);
    Insert(5);
    Insert(4);
    Insert(3);
    Insert(2);
    Insert(1);

    cout<<"Input linked list is: ";
    display();

    if(getLength()%2==0)
        cout<<"Length of the Linked List is even";
    else
        cout<<"Length of the Linked List is odd";
    return 0;
}
