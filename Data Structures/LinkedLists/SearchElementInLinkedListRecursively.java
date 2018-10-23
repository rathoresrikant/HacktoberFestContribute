// Recursive implementation to search an element 

class Node 
{ 
    int data; 
    Node next; 
    Node(int d) 
    { 
        data = d; 
        next = null; 
    } 
} 

class LinkedList 
{ 
    Node head;  

    public void push(int new_data) 
    { 
        Node new_node = new Node(new_data); 
        new_node.next = head; 
 
        head = new_node; 
    } 
  
    
    /**Method to search an element **/ 
    public boolean search(Node head, int x) 
    { 
        if (head == null) 
            return false; 
  
        if (head.data == x) 
            return true; 
 
        return search(head.next, x); 
    } 

    /**Main mehtod **/ 
    public static void main(String args[]) 
    {  
        LinkedList llist = new LinkedList(); 

        llist.push(11); 
        llist.push(31); 
        llist.push(12); 
        llist.push(22); 
        llist.push(15); 
  
        if (llist.search(llist.head, 22)) 
            System.out.println("Yes"); 
        else
            System.out.println("No"); 
    } 
} 
