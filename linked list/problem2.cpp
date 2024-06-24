#include<iostream>
using namespace std;
/* Link list node */
struct Node 
{ 
    int value; 
    struct Node* next; 
}; 
  
/* function to insert a node at the beginning of a linked list*/
void insert(struct Node** head, int data)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->value=data;
    node->next=*head;
    *head=node; 
} 
/*function to check if given data is present in a list */
bool check(struct Node *head, int data)
{
    struct Node* node=head;
    while (node!= NULL) 
    { 
        if (node->value == data) 
            return 1; 
        node= node->next; 
    } 
    return 0;
} 
/* A function to print a linked list*/
int getlength(struct Node *node) 
{ 
    int len=0;
    while (node != NULL) 
    { 
        len++;
        node = node->next; 
    } 
    return len;
} 
int main() 
{ 
    /* Start with the empty list */
    struct Node* head1 = NULL; 
    insert(&head1,10);
    insert(&head1,55);
    insert(&head1,56);
    cout<<"Length of linked list ="<<getlength(head1)<<endl;;
}