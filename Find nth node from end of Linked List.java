class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    Node head;

    public void append(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        Node current = head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = newNode;
    }

    public Node findNthFromEnd(int n) {
        Node first = head;
        Node second = head;

        for (int i = 0; i < n; i++) {
            if (first == null) {
                return null;
            }
            first = first.next;
        }

        while (first != null) {
            first = first.next;
            second = second.next;
        }

        return second;
    }

    public void printList() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.append(1);
        list.append(2);
        list.append(3);
        list.append(4);
        list.append(5);

        list.printList();
        int n = 2;
        Node nthNode = list.findNthFromEnd(n);
        if (nthNode != null) {
            System.out.println("The " + n + "th node from the end is: " + nthNode.data);
        } else {
            System.out.println("The linked list is shorter than " + n + " nodes.");
        }
    }
}
