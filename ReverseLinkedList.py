class Node:
    def __init__(self,data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def print_llist(self):
        if self.head == None:
            print("Linked list is empty")
        else:
            temp = self.head
            while temp != None:
                print(temp.data,end="->")
                temp = temp.next

    def insert_start(self,data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def insert_end(self,data):
        new_node = Node(data)
        temp = self.head
        while temp.next != None:
            temp = temp.next
        temp.next = new_node
        temp.next.next = None

    def insert_pos(self,data,prevnode):
        head = self.head
        while head:
            if head.data == prevnode:
                break
            head = head.next
        new_node = Node(data)
        temp = head.next
        head.next = new_node
        new_node.next = temp

    def reverse_ll(self):
        prev = None
        current = self.head
        while current != None:
            next = current.next
            current.next = prev
            prev = current
            current = next
        self.head = prev


# Driver's Code
LL = LinkedList()
LL.insert_start(10)
LL.insert_start(20)
LL.insert_start(30)
LL.insert_end("A")
LL.insert_end("B")
LL.insert_end("C")
LL.insert_start(40)
LL.insert_pos("a", "A")
LL.insert_pos("b","B")
print("Linked List:")
LL.print_llist()
print("\n")
print("Reversed Linked List:")
LL.reverse_ll()
LL.print_llist()