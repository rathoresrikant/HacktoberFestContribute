#include<bits/stdc++.h>
  using namespace std;

struct Node 
{ 
    int data; 
    struct Node* next; 
}; 

struct Node* SortedMerge(struct Node* a, struct Node* b); 
void FrontBackSplit(struct Node* source, 
        struct Node** frontRef, struct Node** backRef); 
  
/* sorts the linked list by changing next pointers (not data) */
void MergeSort(struct Node** headRef) 
{ 
struct Node* head = *headRef; 
struct Node* a; 
struct Node* b; 
  
/* Base case -- length 0 or 1 */
if ((head == NULL) || (head->next == NULL)) 
{ 
    return; 
} 
  
/* Split head into 'a' and 'b' sublists */
FrontBackSplit(head, &a, &b);  
  
/* Recursively sort the sublists */
MergeSort(&a); 
MergeSort(&b); 
  
/* answer = merge the two sorted lists together */
*headRef = SortedMerge(a, b); 
} 
  
/* See https://www.geeksforgeeks.org/?p=3622 for details of this  
function */
struct Node* SortedMerge(struct Node* a, struct Node* b) 
{ 
struct Node* result = NULL; 
  
/* Base cases */
if (a == NULL) 
    return(b); 
else if (b==NULL) 
    return(a); 
  
/* Pick either a or b, and recur */
if (a->data <= b->data) 
{ 
    result = a; 
    result->next = SortedMerge(a->next, b); 
} 
else
{ 
    result = b; 
    result->next = SortedMerge(a, b->next); 
} 
return(result); 
} 

void FrontBackSplit(struct Node* source, 
        struct Node** frontRef, struct Node** backRef) 
{ 
        struct Node* fast; 
        struct Node* slow; 
    slow = source; 
    fast = source->next; 
  
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) 
    { 
    fast = fast->next; 
    if (fast != NULL) 
    { 
        slow = slow->next; 
        fast = fast->next; 
    } 
    } 
  
    /* 'slow' is before the midpoint in the list, so split it in two 
    at that point. */
    *frontRef = source; 
    *backRef = slow->next; 
    slow->next = NULL; 
} 
  
/* Function to print nodes in a given linked list */
void printList(struct Node *node) 
{ 
while(node!=NULL) 
{ 
printf("%d ", node->data); 
node = node->next; 
} 
} 
  
/* Function to insert a node at the beginging of the linked list */
void push(struct Node** head_ref, int new_data) 
{ 
/* allocate node */
struct Node* new_node = 
            (struct Node*) malloc(sizeof(struct Node)); 
  
/* put in the data */
new_node->data = new_data; 
  
/* link the old list off the new node */
new_node->next = (*head_ref);  
  
/* move the head to point to the new node */
(*head_ref) = new_node; 
}  
  
/* Drier program to test above functions*/
int main() 
{ 
/* Start with the empty list */
struct Node* res = NULL; 
struct Node* a = NULL; 
  int n;
cout<<"enter number of items to insert in linked list\n";
cin>>n;
int t;
for(int i=0;i<n;i++)
{
	cin>>t;
	push(&a,t);
}

/* Sort the above created Linked List */
MergeSort(&a); 
  
printf("Sorted Linked List is: \n"); 
printList(a);          
  
return 0; 
} 
