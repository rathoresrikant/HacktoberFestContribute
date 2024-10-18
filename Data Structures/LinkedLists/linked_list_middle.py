class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        """Add a new node with the given data at the end of the list."""
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = new_node

    def print_middle(self):
        """Print the middle node of the linked list."""
        slow = self.head
        fast = self.head
        
        # Move fast by 2 and slow by 1
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        if slow:
            print("The middle element is:", slow.data)
        else:
            print("The list is empty.")

if __name__ == "__main__":
    linked_list = LinkedList()
    n = int(input("Enter the number of elements in the linked list: "))
    
    print("Enter the elements:")
    for _ in range(n):
        number = int(input())
        linked_list.append(number)
    
    linked_list.print_middle()
