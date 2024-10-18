class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def is_length_even_or_odd(head):
    current = head
    while current and current.next:
        current = current.next.next
    if current is None:
        return "Even"
    else:
        return "Odd"

# Example usage:
head = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))

result = is_length_even_or_odd(head)
print("The length of the linked list is:", result)
