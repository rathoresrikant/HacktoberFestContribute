// Iterative C++ program to print odd level nodes 
#include <bits/stdc++.h> 
using namespace std; 
  
struct Node { 
    int data; 
    Node* left, *right; 
}; 
  
// Iterative method to do level order traversal line by line 
void printOddNodes(Node *root) 
{ 
    // Base Case 
    if (root == NULL)  return; 
  
    // Create an empty queue for level 
    // order tarversal 
    queue<Node *> q; 
  
    // Enqueue root and initialize level as odd 
    q.push(root); 
    bool isOdd = true;   
  
    while (1) 
    { 
        // nodeCount (queue size) indicates 
        // number of nodes at current level. 
        int nodeCount = q.size(); 
        if (nodeCount == 0) 
            break; 
  
        // Dequeue all nodes of current level 
        // and Enqueue all nodes of next level 
        while (nodeCount > 0) 
        { 
            Node *node = q.front(); 
            if (isOdd) 
               cout << node->data << " "; 
            q.pop(); 
            if (node->left != NULL) 
                q.push(node->left); 
            if (node->right != NULL) 
                q.push(node->right); 
            nodeCount--; 
        } 
  
        isOdd = !isOdd; 
    } 
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
