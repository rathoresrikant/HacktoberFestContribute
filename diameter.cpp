#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    explicit Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

int height(Node *root, int &ret)
{
    if(!root)
    {
        return 0;
    }

    int lh = height(root->left, ret);
    int rh = height(root->right, ret);
    ret = max(ret, lh + rh);
    return max(lh, rh) + 1;
}
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->right->right = new Node(6);
    int ret = 0;
    cout << height(root, ret) << endl;
    cout << ret;
    return 0;
}
