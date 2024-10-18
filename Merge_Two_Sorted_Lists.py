class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def merge_two_sorted_lists(list1, list2):
    dummy = ListNode()
    tail = dummy
    
    while list1 and list2:
        if list1.val < list2.val:
            tail.next = list1
            list1 = list1.next
        else:
            tail.next = list2
            list2 = list2.next
        tail = tail.next
    
    tail.next = list1 if list1 else list2
    
    return dummy.next

def print_list(node):
    while node:
        print(node.val, end=" -> ")
        node = node.next
    print("None")

l1 = ListNode(1, ListNode(3, ListNode(5)))
l2 = ListNode(2, ListNode(4, ListNode(6)))

merged_head = merge_two_sorted_lists(l1, l2)

print_list(merged_head)
