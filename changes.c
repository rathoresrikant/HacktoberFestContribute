#include<stdio.h>
#include<stdlib.h>

// Defining structure
struct Node
{
	int data;
	struct Node* next;
};
typedef struct LinkedList
{
    struct Node *head;
    int length;
}list;
void list_initialize(list *sll)
{
    sll->head=NULL;
    sll->length=0;
}


// Push function
void push(list *sll, int info)
{
    struct Node *p=sll->head;
	// Allocating node
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));

	// Info into node
	node->data = info;

	// Next of new node to head
	node->next = p;

	// head points to new node
	(sll->head) = node;
	sll->length++;
}
void display(list *sll)
{
    struct Node *p=sll->head;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}
// Driver function
int main(void)
{
    list sll;
    list_initialize(&sll);
	// Adding elements to Linked List
	push(&sll, 4);
	push(&sll, 5);
	push(&sll, 7);
	push(&sll, 2);
	push(&sll, 9);
	push(&sll, 6);
	push(&sll, 1);
	push(&sll, 2);
	push(&sll, 0);
	push(&sll, 5);
	push(&sll, 5);
	display(&sll);
	if(!(sll.length %2))
	{
		printf("Even\n");
	}
	else
	{
		printf("Odd\n");
	}
	return 0;
}
