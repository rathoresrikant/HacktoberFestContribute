class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def print_odd_level_nodes(root):
    if not root:
        return
    
    queue = [(root, 1)]
    
    while queue:
        node, level = queue.pop(0)
        
        if level % 2 == 1:
            print(node.val, end=" ")
        
        if node.left:
            queue.append((node.left, level + 1))
        if node.right:
            queue.append((node.right, level + 1))

# Example usage:
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)
root.right.left = TreeNode(6)
root.right.right = TreeNode(7)

print_odd_level_nodes(root)