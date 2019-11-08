/*Given a binary tree, print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
Input format :

Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Output Format :

Elements are printed level wise, each level in new line (separated by space).*/
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
void zigZagOrder(BinaryTreeNode<int> *root) {

  if(root == NULL)
    return ;

  stack<BinaryTreeNode<int>*> nodes2,nodes1;

  nodes1.push(root);
  int n1 = 0,n2 = 0;
  n1 = nodes1.size();
  BinaryTreeNode<int>*currNode;
  while(n1>0 || n2>0)
  {
    for(int i =0;i<n1;i++)
    {
      currNode = nodes1.top();
      nodes1.pop();
      cout<<currNode->data<<" ";
      if(currNode->left != NULL)
        nodes2.push(currNode->left);
      if(currNode->right != NULL)
        nodes2.push(currNode->right);
    }
    n2 = nodes2.size();
    cout<<endl;
    for(int i = 0;i<n2;i++)
    {
      currNode = nodes2.top();
      nodes2.pop();
      cout<<currNode->data<<" ";
      if(currNode->right != NULL)
        nodes1.push(currNode->right);
      if(currNode->left != NULL)
        nodes1.push(currNode->left);
    }
    n1 = nodes1.size();
    cout<<endl;
  }

}


BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}

