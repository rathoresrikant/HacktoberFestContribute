class Tree:
    def __init_(self):
        self.root = None


class Node:
    def __init__(self, key):
        self.parent = None
        self.right = None
        self.left = None
        self.key = key


def is_leaf(node):
    return node.left == None and node.right == None


def insert(key, tree):
    new_node = Node(key)
    current_node = tree.root
    parent_node = None
    
    while current_node:
        parent_node = current_node
        if key < current_node.key:
            current_node = current_node.left
        else:
            current_node = current_node.right
    new_node.parent = parent_node

    if parent_node is None:
        tree.root = new_node
    elif key < parent_node.key:
        parent_node.left = new_node
    else:
        parent_node.right = new_node


def search(key, node):
    if node.key == key or node is None:
        return node
   
    if node.key < key:
        return search(key, node.right)
    else:
        return search(key, node.left)


def tree_search(key, tree):
    search(key, tree.root)



