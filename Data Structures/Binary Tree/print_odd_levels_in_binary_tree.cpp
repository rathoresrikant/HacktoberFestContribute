#include <stdio.h>
#include <stdlib.h>

struct Tree {
    int data;
    struct Tree* left_child;
    struct Tree* right_child;
};

void insert_node(struct Tree** root, int value) {
    struct Tree* new_node = (struct Tree*)malloc(sizeof(struct Tree));

    if (new_node) {
        new_node->left_child = NULL;
        new_node->right_child = NULL;
        new_node->data = value;

        if (*root) {
            struct Tree* temp = *root;

            while (temp) {
                if (temp->data >= value) {
                    if (temp->left_child != NULL) {
                        temp = temp->left_child;
                    } else {
                        temp->left_child = new_node;
                        break;
                    }
                } else {
                    if (temp->right_child != NULL) {
                        temp = temp->right_child;
                    } else {
                        temp->right_child = new_node;
                        break;
                    }
                }
            }
        } else {
            *root = new_node;
        }
    } else {
        printf("\n Memory Overflow");
    }
}

void inorder_show(struct Tree* temp) {
    if (temp) {
        inorder_show(temp->left_child);
        printf(" %d", temp->data);
        inorder_show(temp->right_child);
    }
}

struct Tree* free_node(struct Tree* temp) {
    if (temp) {
        temp->left_child = free_node(temp->left_child);
        temp->right_child = free_node(temp->right_child);
        free(temp);
        temp = NULL;
    }
    return NULL;
}

void print_odd_level(struct Tree* temp, int show) {
    if (temp) {
        print_odd_level(temp->left_child, show + 1);
        print_odd_level(temp->right_child, show + 1);
        if (show % 2 != 0) {
            printf(" %d", temp->data);
        }
    }
}

int main() {
    struct Tree* root = NULL;

    insert_node(&root, 150);
    insert_node(&root, 70);
    insert_node(&root, 30);
    insert_node(&root, 90);
    insert_node(&root, 240);
    insert_node(&root, 110);
    insert_node(&root, 153);
    insert_node(&root, 650);
    insert_node(&root, 20);
    insert_node(&root, 10);
    insert_node(&root, 15);
    insert_node(&root, 660);
    insert_node(&root, 80);

    if (root) {
        printf("\n BST Inorder Data Is: ");
        inorder_show(root);

        printf("\n Odd Level Nodes Is: ");
        print_odd_level(root, 1);

        root = free_node(root);
    } else {
        printf("\n Empty Tree ");
    }

    return 0;
}
