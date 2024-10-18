class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def print_middle(head):
    slow = head
    fast = head
    
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    
    print("The middle node value is:", slow.val)

# Example usage:
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)
head.next.next.next.next = ListNode(5)

print_middle(head)
