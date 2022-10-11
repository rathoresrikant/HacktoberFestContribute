#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct BstNode {
	int data;
	struct BstNode* left;
	struct BstNode* right;
};


struct BstNode* GetNewNode(int data)
{
	struct BstNode *newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}


struct BstNode* Insert(struct BstNode* root,int data) {
	if(root == NULL) {
		root = GetNewNode(data);
	}

	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}

	else {
		root->right = Insert(root->right,data);
	}
	return root;
}

bool Search(struct BstNode* root,int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}

 void preorder(struct BstNode* root)
{
 if(root==NULL)
    return;
     printf("%d \n", root->data);
     preorder(root->left);
     preorder(root->right);

}

void inorder(struct BstNode* root)
{
 if(root == NULL)
    return;
 inorder(root->left);
 printf("%d \n", root->data);
 inorder(root->right);


}

void postorder(struct BstNode* root)
{
 if(root!=NULL)
 {
     postorder(root->left);
     postorder(root->right);
     printf("%d \n", root->data);
 }
}
int main() {
    int ch;
    int number;
	struct BstNode* root = NULL;
	int n, i, data;
    char ele[10];
FILE *filePointer;


    filePointer = fopen("bst.txt", "r");

    if(filePointer == NULL)
        printf("file empty");
    else
        while(fscanf(ele , 10, filePointer) !=NULL)
    {
        root = Insert(root, ele);
    }

    while(ch!=6){
    printf("\n\n1.Search.");
    printf("\n\n2.Inorder\n\n3.Postorder\n\n4.Preorder");
    printf("\n\nEnter the Choice: ");
    scanf("%d", &ch);
    switch(ch)
    {

    case 1:
	printf("enter the number to be searched");
	scanf("%d",&number);

	if(Search(root,number) == true) printf("\n found \n");
	else printf("\n not found \n");
	break;

	case 2:
	    printf("Inorder traversal");
        inorder(root);
    break;

    case 3:
        printf("Postorder traversal");
        postorder(root);
    break;

    case 4:
        printf("Preorder traversal");
        preorder(root);
    break;
    default:
        printf("wrong");
    break;
    }
    }
	return 0;
}

#SHORT CODE
// Binary Search Tree operations in C

#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    printf("%d -> ", root->key);

    // Traverse right
    inorder(root->right);
  }
}

// Insert a node
struct node *insert(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);

  printf("Inorder traversal: ");
  inorder(root);

  printf("\nAfter deleting 10\n");
  root = deleteNode(root, 10);
  printf("Inorder traversal: ");
  inorder(root);
}
