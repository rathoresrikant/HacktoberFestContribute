// Recursive C++ program to print odd level nodes 
#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
	int data; 
	Node* left, *right; 
}; 

void printOddNodes(Node *root, bool isOdd = true) 
{ 
	// If empty tree 
	if (root == NULL) 
	return; 

	// If current node is of odd level 
	if (isOdd) 
	cout << root->data << " " ; 

	// Recur for children with isOdd 
	// switched. 
	printOddNodes(root->left, !isOdd); 
	printOddNodes(root->right, !isOdd); 
} 

// Utility method to create a node 
struct Node* newNode(int data) 
{ 
	struct Node* node = new Node; 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

// Driver code 
int main() 
{ 
	struct Node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	printOddNodes(root); 

	return 0; 
} 

