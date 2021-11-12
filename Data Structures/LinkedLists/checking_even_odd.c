#include<stdio.h> 
#include<stdlib.h> 

// Defining structure 
typedef struct node 
{ 
	int data; 
	struct node* next; 
}Node; 

// doing this adds object orientedness in program 
typedef struct linklist
{
	Node* head;
}list;

// Function to check the length of linklist 
int LinkedListLength(list* sll) 
{ 
	int count=0;
	Node* p = sll->head;
	while (p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
} 

//initializing the head of list to NULL 
list* list_init()
{
	list *sll = (list*)malloc(sizeof(list));
	sll->head=NULL;
	return sll;
}

// creating the node for linked list
Node* create_node(int data)
{
	Node* temp=(Node*)malloc(sizeof(Node));
	temp->data=data;
	temp->next=NULL;
	return temp;
}
// Push function or adding the new node in the beginning of the linked list 
void push(list* sll, int info) 
{ 
	Node* temp=create_node(info);
	temp->next=sll->head;
	sll->head=temp;
} 

// Driver function 
int main() 
{ 
	list* sll = list_init(); 
	
	// Adding elements to Linked List 
	push(sll, 4); 
	push(sll, 5); 
	push(sll, 5); 
	push(sll, 5); 
	push(sll, 7); 
	push(sll, 2); 
	push(sll, 9); 
	push(sll, 6); 
	push(sll, 1); 
	push(sll, 2); 
	push(sll, 0); 
	push(sll, 5); 
	push(sll, 5); 
	push(sll, 6);
	push(sll, 8);
	push(sll, 9);
	int check = LinkedListLength(sll); 
	
	// Checking for length of 
	// linklist 
	if((check%2) == 0) 
	{ 
		printf("Even\n"); 
	} 
	else
	{ 
		printf("Odd\n"); 
	} 
	return 0; 
} 
