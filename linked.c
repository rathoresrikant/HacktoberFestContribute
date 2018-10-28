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
		      
		        /*After this loop secLast contains address of second last 
			 *     node and last contains address of last node in Linked List */
		        while (last->next != NULL) 
				    { 
					            secLast = last; 
						            last = last->next; 
							        } 
			  
			    /* Set the next of second last as NULL */
			    secLast->next = NULL; 
			      
			        /* Set next of last as head node */
			        last->next = *head_ref; 
				  
				    /* Change the head pointer to point to last node now */
				    *head_ref = last; 
} 
  
/* UTILITY FUNCTIONS */
/* Function to add a node at the begining of Linked List */
void push(struct Node** head_ref, int new_data) 
{ 
	    /* allocate node */
	    struct Node* new_node = 
		            (struct Node*) malloc(sizeof(struct Node)); 
	      
	        /* put in the data  */
	        new_node->data  = new_data; 
		  
		    /* link the old list off the new node */
		    new_node->next = (*head_ref); 
		      
		        /* move the head to point to the new node */
		        (*head_ref)    = new_node; 
} 
  
  
/* Function to print nodes in a given linked list */
void printList(struct Node *node) 
{ 
	    while(node != NULL) 
		        { 
				        printf("%d ", node->data); 
					        node = node->next; 
						    } 
} 
  
/* Druver program to test above function */
int main() 
{ 
	    struct Node *start = NULL; 
	      
	        /* The constructed linked list is: 
		 *      1->2->3->4->5 */
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
