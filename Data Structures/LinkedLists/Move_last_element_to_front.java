class LinkedList 
{ 
	Node head; // head of list 

	/* Linked list Node*/
	class Node 
	{ 
		int data; 
		Node next; 
		Node(int d) {data = d; next = null; } 
	} 

	void moveToFront() 
	{ 
		/* If linked list is empty or it contains only 
		one node then simply return. */
		if(head == null || head.next == null) 
			return; 

		/* Initialize second last and last pointers */
		Node secLast = null; 
		Node last = head; 

		/* After this loop secLast contains address of 
		second last node and last contains address of 
		last node in Linked List */
		while (last.next != null) 
		{ 
		secLast = last; 
		last = last.next; 
		} 

		/* Set the next of second last as null */
		secLast.next = null; 

		/* Set the next of last as head */
		last.next = head; 

		/* Change head to point to last node. */
		head = last; 
	}				 

					
	/* Utility functions */

	/* Inserts a new Node at front of the list. */
	public void push(int new_data) 
	{ 
		/* 1 & 2: Allocate the Node & 
				Put in the data*/
		Node new_node = new Node(new_data); 

		/* 3. Make next of new Node as head */
		new_node.next = head; 

		/* 4. Move the head to point to new Node */
		head = new_node; 
	} 

	/* Function to print linked list */
	void printList() 
	{ 
		Node temp = head; 
		while(temp != null) 
		{ 
		System.out.print(temp.data+" "); 
		temp = temp.next; 
		} 
		System.out.println(); 
	} 

	public static void main(String args[]) 
	{ 
		LinkedList llist = new LinkedList(); 
		/* Constructed Linked List is 1->2->3->4->5->null */
		llist.push(5); 
		llist.push(4); 
		llist.push(3); 
		llist.push(2); 
		llist.push(1); 
		
		System.out.println("Linked List before moving last to front "); 
		llist.printList(); 
		
		llist.moveToFront(); 
		
		System.out.println("Linked List after moving last to front "); 
		llist.printList(); 
	} 
} 
