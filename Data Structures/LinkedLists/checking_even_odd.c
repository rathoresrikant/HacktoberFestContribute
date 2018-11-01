#include<stdio.h> 
#include<stdlib.h> 

// Defining structure 
struct Node 
{ 
	int data; 
	struct Node* next; 
}; 

// Function to check the length of linklist 
int LinkedListLength(struct Node* head) 
{ 
	while (head && head->next) 
	{ 
		head = head->next->next; 
	} 
	if (!head) 
		return 0; 
	return 1; 
} 
	
// Push function 
void push(struct Node** head, int info) 
{ 
	// Allocating node 
	struct Node* node = (struct Node*) malloc(sizeof(struct Node)); 
	
	// Info into node 
	node->data = info; 
	
	// Next of new node to head 
	node->next = (*head); 

	// head points to new node 
	(*head) = node; 
} 

// Driver function 
int main(void) 
{ 
	struct Node* head = NULL; 
	
	// Adding elements to Linked List 
	push(&head, 4); 
	push(&head, 5); 
	push(&head, 7); 
	push(&head, 2); 
	push(&head, 9); 
	push(&head, 6); 
	push(&head, 1); 
	push(&head, 2); 
	push(&head, 0); 
	push(&head, 5); 
	push(&head, 5); 
	int check = LinkedListLength(head); 
	
	// Checking for length of 
	// linklist 
	if(check == 0) 
	{ 
		printf("Even\n"); 
	} 
	else
	{ 
		printf("Odd\n"); 
	} 
	return 0; 
} 
