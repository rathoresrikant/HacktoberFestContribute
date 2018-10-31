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
	struct Node *prev; 
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
	int c;
	cin>>c;
	struct Node* head = newNode(c); 
	struct Node* head2=head;
	while(c!=-1)
	{
		cin>>c;
		head2->next = newNode(c); 
		head2=head2->next;
	}

	cout << "Given Linked List\n"; 
	printList(head); 

	head = deleteMid(head); 

	cout << "Linked List after deletion of middle\n"; 
	printList(head); 

	return 0; 
} 
