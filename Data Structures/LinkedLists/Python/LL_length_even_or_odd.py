class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
def is_length_even_or_odd(head):
    count = 0
    current = head
    while current:
        count += 1
        current = current.next
    if count % 2 == 0:
        return "Even"
    else:
        return "Odd"

def create_linked_list(elements):
    head = None
    for element in elements:
        new_node = Node(element)
        if head is None:
            head = new_node
        else:
            current.next = new_node
        current = new_node
    return head

elements = [1, 2, 3, 4, 5]
head = create_linked_list(elements)
print(f"The length of the linked list is: {is_length_even_or_odd(head)}")
