#include <stdio.h>
#include <stdlib.h>

// Data Structure to store a linked list node
struct Node
{
	int data;
	struct Node* next;
};

// Helper function to print given linked list
void printList(struct Node* head)
{
	struct Node* ptr = head;
	while (ptr)
	{
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}

	printf("null");
}

// Helper function to insert new Node in the beginning of the linked list
void push(struct Node** head, int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

// Remove duplicates from a sorted list
void RemoveDuplicates(struct Node* head)
{
	// do nothing if the list is empty
	if (head == NULL)
		return;

	struct Node* current = head;

	// Compare current node with next node
	while(current->next != NULL)
	{
		if (current->data == current->next->data)
		{
			struct Node* nextNext = current->next->next;
			free(current->next);
			current->next = nextNext;
		}
		else {
			current = current->next; // only advance if no deletion
		}
	}
}

// main method
int main(void)
{
	// input keys
	int j;
	printf("no. of input to be given?\n");
	scanf("%d",&j);
	int keys[j];
	for(int i=0;i<j;i++){
	    scanf("%d",&keys[i]);
	}
	int n = sizeof(keys)/sizeof(keys[0]);

	// points to the head node of the linked list
	struct Node* head = NULL;

	// construct linked list
	for (int i = n-1; i >= 0; i--)
		push(&head, keys[i]);

	RemoveDuplicates(head);

	// print linked list
	printList(head);

	return 0;
}
