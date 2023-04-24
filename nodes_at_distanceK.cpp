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

void printLevelK(Node *root, int k)
{
    if(!root)
    {
        return;
    }

    if(k == 0)
    {
        cout << root->data << " ";
        return;
    }
    printLevelK(root->left, k - 1);
    printLevelK(root->right, k - 1);
}

int findDistance(Node *root, Node *target)
{
    int distance = -1;
    if(!root)
    {
        return -1;
    }
    queue <Node *> q;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        size_t m = q.size();
        while (m--)
        {
            Node *curr = q.front();
            q.pop();
            if (curr == target)
            {
                return level;
            }
            if(curr->left)
            {
                q.push(curr->left);
            }

            if(curr->right)
            {
                q.push(curr->right);
            }
        }
        level++;
    }
    return distance;
}

void printNodesAtDistanceK(Node *root, Node *target, int k)
{
    if(!root)
    {
        return;
    }

    Node *curr = root;
    if(findDistance(root, target) == k)
    {
        cout << root->data << " ";
    }

    while (curr && curr != target)
    {
        int ld = findDistance(curr->left, target);
        int rd = findDistance(curr->right, target);
        if(ld != -1)
        {
            printLevelK(curr->right, k - ld - 2);
            curr = curr->left;
        }
        else
        {
            printLevelK(curr->left, k - rd - 2);
            curr = curr->right;
        }
    }

    printLevelK(target, k);
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    root->left->right->right->left = new Node(9);
    root->left->right->right->right = new Node(10);
    printNodesAtDistanceK(root, root->left, 3);
    return 0;
}
