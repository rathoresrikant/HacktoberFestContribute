
#include<bits/stdc++.h> 
using namespace std; 
  

struct Node 
{ 
    int data; 
    struct Node* next; 
}; 
  

struct Node* deleteMid(struct Node *head) 
{ 
    
    if (head == NULL) 
        return NULL; 
    if (head->next == NULL) 
    { 
        delete head; 
        return NULL; 
    } 
  

    struct Node *slow_ptr = head; 
    struct Node *fast_ptr = head; 
  
 
    struct Node *prev; // To store previous of slow_ptr 
    while (fast_ptr != NULL && fast_ptr->next != NULL) 
    { 
        fast_ptr = fast_ptr->next->next; 
        prev = slow_ptr; 
        slow_ptr = slow_ptr->next; 
    } 
  

    prev->next = slow_ptr->next; 
    delete slow_ptr; 
  
    return head; 
} 
  

void printList(struct Node *ptr) 
{ 
    while (ptr != NULL) 
    { 
        cout << ptr->data << "->"; 
        ptr = ptr->next; 
    } 
    cout << "NULL\n"; 
} 
  

Node *newNode(int data) 
{ 
    struct Node *temp = new Node; 
    temp->data = data; 
    temp->next = NULL; 
    return temp; 
} 
  

int main() 
{ 

    struct Node* head = newNode(1); 
    head->next = newNode(2); 
    head->next->next = newNode(3); 
    head->next->next->next = newNode(4); 
  
    cout << "Gven Linked List\n"; 
    printList(head); 
  
    head = deleteMid(head); 
  
    cout << "Linked List after deletion of middle\n"; 
    printList(head); 
  
    return 0; 
} 
