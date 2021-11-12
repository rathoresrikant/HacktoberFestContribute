#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    int count;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
        count = 1;
    }
};

int Height(node* root) {
    int max_h = 0;
    if (root != NULL) {
        int LH = Height(root->left);
        int RH = Height(root->right);
        max_h = max(LH, RH) + 1;
    }
    return max_h;
}

int diff(node* root) {
    int l = Height(root->left);
    int r = Height(root->right);
    int b = r - l;
    return b;
}
node* FindMin(node* root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left == NULL) {
        return root;
    }
    return (FindMin(root->left));
}

node* llRotation(node* parent) {
    node* temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
node* rrRotation(node* parent) {
    node* temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
node* lrRotation(node* parent) {
    node* temp;
    temp = parent->left;
    parent->left = rrRotation(temp);
    return llRotation(parent);
}

node* rlRotation(node* parent) {
    node* temp;
    temp = parent->right;
    parent->right = llRotation(temp);
    return rrRotation(parent);
}

node* balance(node* root) {
    int b_factor = diff(root);
    if (b_factor < -1) {
        if (diff(root->left) < 0)
            root = llRotation(root);
        else
            root = lrRotation(root);
    } else if (b_factor > 1) {
        if (diff(root->right) > 0)
            root = rrRotation(root);
        else
            root = rlRotation(root);
    }
    return root;
}

void Insert(node*& root, int key) {
    if (root == NULL) {
        root = new node(key);
        return;
    } else if (key < root->data) {
        Insert(root->left, key);
        root = balance(root);
    } else if (key > root->data) {
        Insert(root->right, key);
        root = balance(root);
    } else {
        (root->count)++;
    }
    return;
}

void Delete(node*& root, int d) {
    if (root == NULL) {
        return;
    } else if (d < root->data){
        Delete(root->left, d);
        root = balance(root);
    }
    else if (d > root->data){
        Delete(root->right, d);
        root = balance(root);
    }

    else{
        if(root->count > 1){
            (root->count)--;
        }
        else if(!root->left && !root->right){
            delete(root);
            root=NULL;
        }
        else if(!root->left){
            node* temp = root;
            root = root->right;
            delete(temp);
        }
        else if(!root->right){
            node* temp = root;
            root = root->left;
            delete(temp);
        }
        else{
            node* temp = FindMin(root->right);
            root->data = temp->data;
            Delete(root->right  , temp->data);
        }
    }
    return;
}

void levelorderTraversal(node* root) {
    if (root == NULL)
        return;
    queue<node*> Q;
    Q.push(root);
    while (!Q.empty()) {
        node* current = Q.front();
        cout << current->data << "(" << current->count << ")"
             << "-";
        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);
        Q.pop();
    }
}
void inorderTraversal(node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << "-";
        inorderTraversal(root->right);
        return;
    }
}

int main() {
    node* root = NULL;
    Insert(root, 3);
    Insert(root, 4);
    Insert(root, 9);
    Insert(root, 1);
    Insert(root, 7);
    Insert(root, 5);
    Insert(root, 3);
    Insert(root, 2);
    Insert(root, 8);
    Insert(root, 6);
    Insert(root, 7);

    Delete(root ,7);
    Delete(root ,8);
    Delete(root ,9);
    Delete(root ,7);

    cout << endl;
    levelorderTraversal(root);
    cout << endl;
    inorderTraversal(root);

    return 0;
}
