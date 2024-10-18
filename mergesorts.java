class ListNode {
    int val;
    ListNode next;
    
    ListNode(int val) {
        this.val = val;
    }
}

public class MergeSortedLists {
    public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        // Create a dummy node to help with merging
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;

        // Traverse both lists and compare the nodes
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                current.next = l1; // Append l1 node
                l1 = l1.next; // Move to the next node in l1
            } else {
                current.next = l2; // Append l2 node
                l2 = l2.next; // Move to the next node in l2
            }
            current = current.next; // Move the current pointer
        }

        // Append the remaining nodes (if any)
        if (l1 != null) {
            current.next = l1;
        } else {
            current.next = l2;
        }

        return dummy.next; // Return the merged list, which is next to the dummy
    }

    // Helper function to print the list
    public static void printList(ListNode head) {
        ListNode current = head;
        while (current != null) {
            System.out.print(current.val + " ");
            current = current.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Create first sorted list: 1 -> 2 -> 4
        ListNode l1 = new ListNode(1);
        l1.next = new ListNode(2);
        l1.next.next = new ListNode(4);

        // Create second sorted list: 1 -> 3 -> 4
        ListNode l2 = new ListNode(1);
        l2.next = new ListNode(3);
        l2.next.next = new ListNode(4);

        // Merge the two lists
        ListNode mergedList = mergeTwoLists(l1, l2);
        
        // Print the merged list
        printList(mergedList);
    }
}
