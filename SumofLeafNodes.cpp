// CPP program to find sum of 
// all leaf nodes of binary tree 
#include<bits/stdc++.h> 
using namespace std; 

// struct binary tree node 
struct Node{ 
	int data; 
	Node *left, *right; 
}; 

// return new node 
Node *newNode(int data){ 
	Node *temp = new Node(); 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// utility function which calculates 
// sum of all leaf nodes 
void leafSum(Node *root, int *sum){ 
	if (!root) 
		return; 

	// add root data to sum if 
	// root is a leaf node 
	if (!root->left && !root->right) 
		*sum += root->data; 

	// propagate recursively in left 
	// and right subtree 
	leafSum(root->left, sum); 
	leafSum(root->right, sum); 
} 

// driver program 
int main(){ 
	
	//contruct binary tree 
	Node *root = newNode(1); 
	root->left = newNode(2); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right = newNode(3); 
	root->right->right = newNode(7); 
	root->right->left = newNode(6); 
	root->right->left->right = newNode(8); 
	
	// variable to store sum of leaf nodes 
	int sum = 0; 
	leafSum(root, &sum); 
	cout << sum << endl; 
	return 0; 
} 
