#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *left, *right;  
};

struct node* insert(struct node* root, int ele) {
    if (!root) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = ele;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (ele < root->data) 
        root->left = insert(root->left, ele);
    else if (ele > root->data) 
        root->right = insert(root->right, ele);
    return root; 
}

void traverse(struct node *root, void (*func)(struct node *)) {
    if (root) {
        func(root);
        traverse(root->left, func);
        traverse(root->right, func);
    }
}

void inorder(struct node *root) { printf("%d\n", root->data); }
void preorder(struct node *root) { printf("%d\n", root->data); }
void postorder(struct node *root) { printf("%d\n", root->data); }

bool search(struct node *root, int ele) {
    while (root) {
        if (ele == root->data) return true;
        root = (ele < root->data) ? root->left : root->right;
    }
    return false;
}

int main() {
    struct node *root = NULL;
    int opt, ele;

    do {
        printf("\nBST Menu: \n1. Insert \n2. Traversal \n3. Search \n");
        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter the data of the node: ");
                scanf("%d", &ele);
                root = insert(root, ele);
                break;
            case 2: {
                int traversalOpt;
                printf("Traversal Menu: \n1. In-order \n2. Pre-order \n3. Post-order \n");
                printf("Enter your choice: ");
                scanf("%d", &traversalOpt);
                switch (traversalOpt) {
                    case 1: printf("In-order traversal:\n"); traverse(root, inorder); break;
                    case 2: printf("Pre-order traversal:\n"); traverse(root, preorder); break;
                    case 3: printf("Post-order traversal:\n"); traverse(root, postorder); break;
                    default: printf("Enter valid choice.\n");
                }
                break;
            }
            case 3:
                printf("Enter the element to be searched: ");
                scanf("%d", &ele);
                printf("Element %sfound.\n", search(root, ele) ? "" : "not ");
                break;
            default:
                printf("Enter valid choice.\n");
        }
    } while (opt != 0);

    return 0;
}
