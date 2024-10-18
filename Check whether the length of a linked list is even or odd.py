class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = new_node

    def is_length_even_or_odd(self):
        current = self.head
        count = 0
        while current:
            count += 1
            current = current.next
        return "Even" if count % 2 == 0 else "Odd"

# Example usage
if __name__ == "__main__":
    ll = LinkedList()
    ll.append(1)
    ll.append(2)
    ll.append(3)
    ll.append(4)

    result = ll.is_length_even_or_odd()
    print("The length of the linked list is:", result)
