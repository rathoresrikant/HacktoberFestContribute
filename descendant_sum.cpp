#include <iostream>
#include <queue>
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

int descendantSum (Node *root)
{
    if(!root)
    {
        return 0;
    }
    if(!root->left && !root->right)
    {
        return root->data;
    }

    int left_sum = descendantSum(root->left);
    int right_sum = descendantSum(root->right);
    int temp = root->data;
    root->data = left_sum + right_sum;
    return root->data + temp;
}

void printTree(Node *root)
{
    if(!root)
    {
        return;
    }

    queue <Node *> q;
    q.push(root);

    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->data << " ";

        if(curr->left)
        {
            q.push(curr->left);
        }

        if(curr->right)
        {
            q.push(curr->right);
        }
    }
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
    cout << ret << endl;
    cout << descendantSum(root) << endl;
    printTree(root);
    return 0;
}
