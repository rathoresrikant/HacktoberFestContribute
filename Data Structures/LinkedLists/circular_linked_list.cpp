#include<bits/stdc++.h>
using namespace std;

struct Node 
{ 
    int data; 
    struct Node *next; 
}; 
  
/* Function to insert a node at the begining of a Circular 
   linked list */
void push(struct Node **head_ref, int data) 
{ 
    struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node)); 
    struct Node *temp = *head_ref; 
    ptr1->data = data; 
    ptr1->next = *head_ref; 
  
    /* If linked list is not NULL then set the next of last node */
    if (*head_ref != NULL) 
    { 
        while (temp->next != *head_ref) 
            temp = temp->next; 
        temp->next = ptr1; 
    } 
    else
        ptr1->next = ptr1; /*For the first node */
  
    *head_ref = ptr1; 
} 
  
/* Function to print nodes in a given Circular linked list */
void printList(struct Node *head) 
{ 
    struct Node *temp = head; 
    if (head != NULL) 
    { 
        do
        { 
            printf("%d ", temp->data); 
            temp = temp->next; 
        } 
        while (temp != head); 
    } 
} 
  
int main() 
{ 
    
    struct Node *head = NULL; 
  
    int n;
    cout<<"enter no. of elements to enter\n";
    cin>>n;
    cout<<"enter elements\n";
    for(int i=0;i<n;i++)
    {
    	int t;
    	cin>>t;
    	push(&head, t);
	}
    
    printf("Contents of Circular Linked List\n "); 
    printList(head); 
  
    return 0; 
} 
