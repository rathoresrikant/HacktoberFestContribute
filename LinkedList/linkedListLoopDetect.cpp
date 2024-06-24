/*
Finding a loop in a linked list
*/

#include <bits/stdc++.h>
using namespace std;

class LinkedList;

class Node
{
private:
    int data;
    Node *next = NULL;
    friend class LinkedList;
};

class LinkedList
{
public:
    Node *head = NULL;
    void createLinkedList();
    void checkLoopInLinkedList();
};
void LinkedList ::createLinkedList()
{
    // create nodes
    Node *node1 = new Node;
    node1->data = 1;
    Node *node2 = new Node;
    node2->data = 2;
    Node *node3 = new Node;
    node3->data = 3;
    Node *node4 = new Node;
    node4->data = 4;

    // create a loop
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;

    head = node1;
}

void LinkedList ::checkLoopInLinkedList()
{
    Node *ptr1 = head;
    Node *ptr2 = head;
    ptr2 = (ptr2->next)->next;

    /*
        ptr1 moves 1 node at a time
        ptr2 moves 2 node at a time
        if there is loop in the linked list, then at some time ptr1 gets equal to ptr2
    */
    while (1)
    {
        if (ptr1 == NULL || ptr2 == NULL)
        {
            cout << "Loop not found";
            break;
        }
        else if (ptr1 == ptr2)
        {
            cout << "Loop detected" << endl;
            break;
        }
        ptr1 = ptr1->next;
        ptr2 = (ptr2->next)->next;
    }
}

int main()
{
    LinkedList ll;
    ll.createLinkedList();
    ll.checkLoopInLinkedList();
    return 0;
}