#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node * buildTree(const vector <int> &arr)
{
    int n = arr.size();
    if(n == 0)
    {
        return nullptr;
    }
    int i = 0, left_data = 0, right_data = 0;
    queue <Node *> q;
    Node *root = new Node(arr[i++]);
    q.push(root);
    while (i < n)
    {
        Node *curr = q.front();
        q.pop();
        
        left_data = arr[i++];
        if (left_data != -1)
        {
            curr->left = new Node(left_data);
            q.push(curr->left);
        }
        right_data = arr[i++];
        if(right_data != -1)
        {
            curr->right = new Node(right_data);
            q.push(curr->right);
        }
    }

    return root;
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
        cout << curr->data;
        q.pop();
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

int main()
{
    vector <int> arr = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7, -1, -1, -1, -1, -1};
    Node *root = buildTree(arr);
    printTree(root);
    return 0;
}
