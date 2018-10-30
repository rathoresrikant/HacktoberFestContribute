#include<iostream>
#include <queue>
#include<stack>
#include<math.h>
#include <algorithm>
#include<vector>


using namespace std;

/*

Functions Performed:
1. To input the tree
2. To print the tree in a levelwise order
3. To count number of nodes
4. To remove leaf nodes
5. To check if a node is present in the tree
6. To check the height of the tree
7. To form the mirror image of the binary tree
8. To build a tree from the Preorder and Inorder
9. To build a tree from the Postorder and Inorder
10. To find the diameter of the tree
11. To check if the tree is height balanced or not
12. To check the depth of a node from the root of the tree
13. To print each level on a new line
14. To print the tree in a zigzag fashion
15. To construct a tree from an array
15. To find the path of a node from node to root
16. To find Least Common Ancestor of two nodes in the binary tree 

*/
template<typename T>
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

class pairs
{
public:
  int height;
  int diameter;
};


//To take input in a levelwise order
//Enter 0 to stop
BinaryTreeNode<int>* takeinput()
{
  int rootdata;
  cout<<"Enter root data:"<<endl;
  cin>>rootdata;
  BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata);
  int ch;
  queue<BinaryTreeNode<int>*> q;
  q.push(root);
  while(!q.empty())
  {
    BinaryTreeNode<int>* k=q.front();
    q.pop();
    cout<<"Enter the number of childrenren of node:"<<k->data<<endl;
    int l;
    cin>>l;
    if(l!=0)
    {
    BinaryTreeNode<int>* leftnode=new BinaryTreeNode<int>(l);
    k->left=leftnode;
    q.push(leftnode);
  }


    int r;
    cin>>r;
    if(r!=0)
    {
    BinaryTreeNode<int>* rightnode=new BinaryTreeNode<int>(r);
    k->right=rightnode;
    q.push(rightnode);
  }
  }

  return root;
}

//To print in a levelwise order
void printLevelWise(BinaryTreeNode<int>* root) {
  queue<BinaryTreeNode<int>*> q;
  
  if(root!=NULL)
  {
  q.push(root);
  }
  while(!q.empty())
  {
    BinaryTreeNode<int>* k=q.front();
    q.pop();

    cout<<k->data<<":";
    cout<<"L:";

    if(k->left!=NULL)
    {
    q.push(k->left);
    cout<<k->left->data<<" ";
  }
  else cout<<"-1";
  cout<<", R:";
  if(k->right!=NULL)
  {
    q.push(k->right);

    cout<<k->right->data<<" ";
  }
  else cout<<"-1";

cout<<endl;
  }

}

//Count number of nodes in the Binary tree
int countNodes(BinaryTreeNode<int> *root)
{
  if(root==NULL)
    return 0;
  return 1+countNodes(root->left)+countNodes(root->right);

}

//To remove leaf nodes from the binary tree
BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root,BinaryTreeNode<int> * parent=NULL) {
    
  if(root->left==NULL&&root->right==NULL)
  {
    if(parent!=NULL)
    {
      if(parent->left==root)
        parent->left=NULL;
      if(parent->right==root)
        parent->right=NULL;
    }
    return parent;
  }
  if(parent!=NULL)
  cout<<parent->data<<" ";
  cout<<root->data<<endl;
  if(root->left!=NULL)
  root=removeLeafNodes(root->left,root);
  if(root->right!=NULL)
  root=removeLeafNodes(root->right,root);
  
  if(parent!=NULL)
  return parent;
else
  return root;
    

}

//To check if an integer is present as a node in the tree
bool isNodePresent(BinaryTreeNode<int>* root, int x) {
   
  if(root==NULL)
    return false;
  
  if(root->data==x)
    return true;
  bool ch1=isNodePresent(root->left,x);
  bool ch2=isNodePresent(root->right,x);
  return ch1||ch2;
  
}

int height(BinaryTreeNode<int> *root) {
    
  if(root==NULL)
    return 0;
  int k1=height(root->left);
  int k2=height(root->right);
  
  return 1+std::max(k1,k2);
  
}

//To form a mirror image of a binary tree
void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    
  if(root==NULL)
    return;
  
  BinaryTreeNode<int>* temp=root->right;
  root->right=root->left;
  root->left=temp;
  
  mirrorBinaryTree(root->left);
  mirrorBinaryTree(root->right);

}

//To form a binary tree from preorder and inorder
BinaryTreeNode<int>* getTreeFromPreorderAndInorder(int *preorder, int ps, int pe, int *inorder, int is, int ie) {


  int l=ie;
  int rootdata=preorder[ps];
  BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata);
  //LEFT SUBTREE
  ps=ps+1;
  int count=-1;
  for(int i=is;i<ie;i++)
  {
    if(inorder[i]!=rootdata)
      count++;
    else
      break;
  }
  ie=is+count;
  pe=ie-is+ps;
  if(ie<is)
    root->left=NULL;
  else if(ie==is)
  {
    BinaryTreeNode<int>* lchild=new BinaryTreeNode<int>(inorder[ie]);
    root->left=lchild;
  }
  else
  {
    root->left=getTreeFromPreorderAndInorder(preorder,ps,pe,inorder,is,ie);
  }

  //RIGHT SUBTREE
  is=ie+2;
  ps=pe+1;
  ie=l;
  pe=ie-is+ps;
  if(ie<is)
    root->right=NULL;
  else if(ie==is)
  {
    BinaryTreeNode<int>* rchild=new BinaryTreeNode<int>(inorder[ie]);
    root->right=rchild;
  }
  else
  {
    root->right=getTreeFromPreorderAndInorder(preorder,ps,pe,inorder,is,ie);
  }

  return root;

}

//To form a binary tree from postorder and inorder
BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int ps, int pe, int *inorder, int is, int ie) 
{
  
  int iel=ie;
  int pel=pe;
  int rootdata=postorder[pe];
  BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata);
  //LEFT SUBTREE
  int count=-1;
  for(int i=is;i<ie;i++)
  {
    if(inorder[i]!=rootdata)
      count++;
    else
      break;
  }
  ie=is+count;
  pe=ie-is+ps;
  if(ie<is)
    root->left=NULL;
  else if(ie==is)
  {
    BinaryTreeNode<int>* lchild=new BinaryTreeNode<int>(inorder[ie]);
    root->left=lchild;
  }
  else
  {
    root->left=getTreeFromPostorderAndInorder(postorder,ps,pe,inorder,is,ie);
  }

  //RIGHT SUBTREE
  is=ie+2;
  ps=pe+1;
  ie=iel;
  pe=pel-1;
  if(ie<is)
    root->right=NULL;
  else if(ie==is)
  {
    BinaryTreeNode<int>* rchild=new BinaryTreeNode<int>(inorder[ie]);
    root->right=rchild;
  }
  else
  {
    root->right=getTreeFromPostorderAndInorder(postorder,ps,pe,inorder,is,ie);
  }

  return root;


}

//To find the diameter of a binary tree
//order of n complexity. better that o(n^2) for normal method
pairs diameter(BinaryTreeNode<int>* root)
{
  if(root==NULL)
  {
    pairs p;
    p.height=0;
    p.diameter=0;
    return p;
  }

  pairs h2=diameter(root->left);
  pairs h3=diameter(root->right);
  pairs h1;
  h1.height= max(h2.height,h3.height)+1;
  int h = h2.height + h3.height;
  h1.diameter= max(h,max(h2.diameter,h3.diameter));

  return h1;
}

//Helper function to check if a binary tree isheight balanced or not
//order of n complexity. better that o(n^2) for normal method
pair<bool,int> balanced(BinaryTreeNode<int> *root)
{
  if(root==NULL)
  {
    pair<bool,int> p;
    p.first=true;
    p.second=0;
    return p;
  }
  
  pair<bool,int> p1;
  pair<bool,int> p2=balanced(root->left);
  pair<bool,int> p3=balanced(root->right);
  
  p1.second = 1+max(p2.second,p3.second);
  if(p3.first&&p2.first)
  {
    if(abs(p2.second-p3.second)>1)
      p1.first=false;
    else
      p1.first=true;
  } 
  else
    p1.first=false;
  return p1;
}

bool isBalanced(BinaryTreeNode<int> *root) 
{
    return balanced(root).first;
  
}

//To find depth of a node from the root of the tree
int depth(BinaryTreeNode<int> *root,BinaryTreeNode<int> *node,int i=0) {
    if(root==NULL)
      return -1;
  if(root->data==node->data)
    return i;
  int ans=depth(root->left,node,i+1);
  if(ans==-1)
  {
    depth(root->right,node,i+1);
  }
}

//To print a tree such that each level is at new line.
void printLevelATNewLine1(BinaryTreeNode<int> *root) {
    
  queue<BinaryTreeNode<int>*> q;
  if(root!=NULL)
  {
    q.push(root);
    q.push(NULL);
  }
  while(!q.empty())
  {
    BinaryTreeNode<int> * k=q.front();
    q.pop();
    if(k==NULL)
    {
      cout<<endl;
      if(q.empty())
        break;
      q.push(NULL);
    }      
    else
    {
    cout<<k->data<<" ";
    if(k->left!=NULL)
      q.push(k->left);
    
  if(k->right!=NULL)
      q.push(k->right);
    }
  }
}

//To print a tree in a zigzag order
//using 2 stacks
void zigZagOrder1(BinaryTreeNode<int> *root) {
    
  stack<BinaryTreeNode<int>*> s1,s2;
  s1.push(root);
  BinaryTreeNode<int>* k=s1.top();
  while(!s1.empty()||!s2.empty())
  {
  while(!s1.empty())
  {
    BinaryTreeNode<int>* k=s1.top();
    s1.pop();
    cout<<k->data<<" ";
    if(k->left!=NULL)
      s2.push(k->left);
    if(k->right!=NULL)
      s2.push(k->right);
    if(s1.empty())
      cout<<endl;
  }
  while(!s2.empty())
  {
    BinaryTreeNode<int>* k=s2.top();
    s2.pop();
    cout<<k->data<<" ";
    if(k->right!=NULL)
      s1.push(k->right);
    if(k->left!=NULL)
      s1.push(k->left);
    if(s2.empty())
      cout<<endl;
  }
  }
  
}


//To construct a tree from an array
BinaryTreeNode<int>* constructTree(int *input, int n) {
    if(n==0)
      return NULL;
  int mid=(n-1)/2;
  BinaryTreeNode<int>* root=new BinaryTreeNode<int>(input[mid]);
  root->left=constructTree(input,mid);
  root->right=constructTree(input+mid+1,n-mid-1);
  return root;
  
}


//To find the path of a node in the tree from the node to the root
//Returns a vector containing the nodes in the path
vector<int> path(BinaryTreeNode<int>* root,int k)
{
  if(root==NULL)
  {
    vector<int> v;
    return v;
  }
  if(root->data==k)
  {
    vector<int> v;
    v.push_back(root->data);
    return v;
  }
  vector<int> v1=path(root->left,k);
  if(v1.size()!=0)
  {
    v1.push_back(root->data);
    return v1;
  }
  else
  {
    vector<int> v2=path(root->right,k);
    if(v2.size()!=0)
    {
      v2.push_back(root->data);
      return v2;
    }
    else
      return v2;
  }
}

//To find Least Common Ancestor of two nodes in the binary tree
int lcaBinaryTree(BinaryTreeNode <int>* root , int val1, int val2)
{
  if(root==NULL)
    return -1;
  if(root->data==val1)
    return val1;
  if(root->data==val2)
    return val2;
  int l=lcaBinaryTree(root->left,val1,val2);
  int r=lcaBinaryTree(root->right,val1,val2);
  
  if(l==-1)
    return r;
  else if(r==-1)
    return l;
  else 
  {
    return root->data;
  }
  
}