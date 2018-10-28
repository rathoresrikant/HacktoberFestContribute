"""
 Print the nodes at the odd levels of a binary tree.
"""

from collections import defaultdict
import random

def l(index):
	return 2*index + 1

def r(index):
	return 2*index + 2

def p(index):
	if index - 1 < 0:
		return None
	else:
		return ( index - 1 ) // 2

def build_random_tree(tree,value_range,num_keys):
	counter = 0
	position = 0
	while counter < num_keys:
		key = random.randint(0,value_range)
		if tree[position] == None:
			tree[position] = key
			counter += 1
		else:
			if counter % 2: #choose left
				position = l(position)
			else: #choose right
				position = r(position)
	return tree
	
	
if __name__ == '__main__':
	tree = defaultdict(lambda: None)
	print("\n Random implicit binary tree represented as (array position, value) tuples. \n")
	tree = build_random_tree(tree,100,10)
	print(list(tree.items()))
	for item in list(tree.items()):
		parent = None
		level = 0
		node = item[0]
		parent_list = []
		while 1:
			parent = p(node)
			parent_list.append(tree[parent])
			node = p(node)
			if parent == None: break
			level += 1
		if level % 2:
			msg = '\n \n Node: {0} \n Path: {1} \n Level: {2} \n \n'
			path = str(item[1]) + ' --> ' + ' --> '.join([str(x) for x in parent_list])
			print(msg.format(str(item[1]), path, level))
