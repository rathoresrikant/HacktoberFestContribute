import java.util.HashSet;
public class removeDuplicatesLinkedList{


    public static class Node{
        int value;
        Node next;
        
        public Node(int value){
               
            this.value = value;
                
        }
    }

    // This method removes duplicate elements 
    // from an unsorted LinkedList
    public static void removeDupsFromLinkedList(Node head){
        
        // Set stores unique nodes in linkedlist
         HashSet<Integer> nodeValueSet = new HashSet<Integer>();
        
        Node currentNode = head;
        Node previousNode = null;

        while(currentNode != null){
            
            int currentNodeValue = currentNode.value;
            
            // if the value of the current node is with the set
            // change previous node next to current node next 
             
            if(nodeValueSet.contains(currentNodeValue)){
               previousNode.next = currentNode.next; 
            }
            else{
                nodeValueSet.add(currentNodeValue);
                previousNode = currentNode;
            }
            currentNode = currentNode.next;
        }
        
        System.out.println("LinkedList after removing duplicates. ");
        displayLinkedList(head);
    
    }
    
    // this method prints the linkedlist
    public static void displayLinkedList(Node head){
       
        Node currentNode = head;
       
        while(currentNode != null){
            System.out.println(currentNode.value);
            currentNode = currentNode.next;
        }
    }

    public static void main(String[] args){
    			
    			Node head = new Node(3);
    			Node node1 = new Node(1);
    			Node node2 = new Node(8);
    			Node node3 = new Node(5);
    			Node node4 = new Node(2);
    			Node node5 = new Node(4);
    			Node node6 = new Node(1);
    			Node node7 = new Node(9);
    			Node node8 = new Node(8);
    			Node node9 = new Node(7);
    			Node node10 = new Node(6); 
    			
    			
    			head.next = node1;
    			node1.next = node2;
    			node2.next = node3;
    			node3.next = node4;
    			node4.next = node5;
    			node5.next = node6;
    			node6.next = node7;
    			node7.next = node8;
    			node8.next = node9;
    			node9.next = node10;
    			node10.next = null;
    			
    			System.out.println("LinkedList before removing duplicates. ");
    			displayLinkedList(head);
    			removeDupsFromLinkedList(head);

    }
}
