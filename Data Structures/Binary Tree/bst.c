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
