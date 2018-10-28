

#include<stdio.h> 
#include<stdlib.h> 
  

struct Node 
{ 
    int data; 
    struct Node *next; 
}; 
  

void moveToFront(struct Node **head_ref) 
{ 
    if (*head_ref == NULL || (*head_ref)->next == NULL) 
        return; 
  
    struct Node *secLast = NULL; 
    struct Node *last = *head_ref; 
  

    while (last->next != NULL) 
    { 
        secLast = last; 
        last = last->next; 
    } 
  

    secLast->next = NULL; 
  
    last->next = *head_ref; 
  

    *head_ref = last; 
} 
  

void push(struct Node** head_ref, int new_data) 
{ 
  
    struct Node* new_node = 
        (struct Node*) malloc(sizeof(struct Node)); 
  
   
    new_node->data  = new_data; 
  
   
    new_node->next = (*head_ref); 
  

    (*head_ref)    = new_node; 
} 
  
  

void printList(struct Node *node) 
{ 
    while(node != NULL) 
    { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
} 
  

int main() 
{ 
    struct Node *start = NULL; 
  
  
     1->2->3->4->5 */
    push(&start, 5); 
    push(&start, 4); 
    push(&start, 3); 
    push(&start, 2); 
    push(&start, 1); 
  
    printf("\n Linked list before moving last to front\n"); 
    printList(start); 
  
    moveToFront(&start); 
  
    printf("\n Linked list after removing last to front\n"); 
    printList(start); 
  
    return 0; 
} 
