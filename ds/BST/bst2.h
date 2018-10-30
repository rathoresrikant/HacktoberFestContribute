#include<iostream>
#include<queue>
#include<climits>
#include<vector>

using namespace std;
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

class trio
{
  public:
  int min;
  int max;
  bool boolval;
};

//To search for a node in a BST
BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int> *root , int k){
    
  if(root==NULL)
    return NULL;
  if(root->data==k)
    return root;
  else if(root->data>k)
    return searchInBST(root->left,k);
  else
    return searchInBST(root->right,k);
}

//To find the elements in range from K1 to K2
void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
    
  if(root==NULL)
    return;
  if(root->data>k2)
  {
    elementsInRangeK1K2(root->left,k1,k2);
    return;
  }
  if(root->data<k1)
  {
    elementsInRangeK1K2(root->right,k1,k2);
    return;
  }
  
  elementsInRangeK1K2(root->left,k1,k2);
  cout<<root->data<<" ";
  elementsInRangeK1K2(root->right,k1,k2);
  

}

//To check if a binary tree in BST or not
trio isBSTutil(BinaryTreeNode<int> *root)
{
  if(root==NULL)
  {
    trio t;
    t.min=INT_MAX;
    t.max=INT_MIN;
    t.boolval=true;
    return t;
  }
  
  trio t;
  trio t1=isBSTutil(root->left);
  trio t2=isBSTutil(root->right);
  
  if(t1.boolval&&t2.boolval)
  {
    if(t1.max<root->data&&t2.min>root->data)
      t.boolval=true;
    else t.boolval=false;
  }
  else t.boolval=false;
  t.min=min(root->data,min(t1.min,t2.min));
  t.max=max(root->data,max(t1.max,t2.max));
  return t;
}

//To construct a BSt from a given array 
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

  else if(root->data>k)
	{
    vector<int> v1=path(root->left,k);
	  v1.push_back(root->data);
	  return v1;
  }
	
	else if(root->data<k)
	{
		vector<int> v2=path(root->right,k);
	  v2.push_back(root->data);
		return v2;
	}
}

//To print the tree in levelwise order
void printLevelWise(BinaryTreeNode<int>* root) {
  queue<BinaryTreeNode<int>*> q;
  
  if(root!=NULL)
  {
  //cout<<root->data<<endl;
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

//To Save the inorder of the BST in an array
int k1=0;
void inorder2(BinaryTreeNode<int> *root, int*a)
{
  if(root==NULL)
    return;//-1;
  inorder(root->left,a);

  a[k1++]=root->data;

  inorder(root->right,a);
  

}

//TO FIND THE NODES WHICH SUM UP TO K IN A BST
#include<map>
void nodesSumToS(BinaryTreeNode<int> *root, int sum)
{
  int* a=new int[1000];
  inorder2(root,a);
  
  int i=0,j=k1-1;
  while(i<j)
  {
    int sum2=a[i]+a[j];
    if(sum2<sum)
      i++;
    if(sum2>sum)
      j--;
    if(sum2==sum)
    {
      cout<<a[i]<<" "<<a[j]<<endl;
      i++;
      j--;
    }
  }
}

//To find Lowest Common Ancestor in a BST
int lcaInBST(BinaryTreeNode<int>* root , int val1 , int val2){

  if(root==NULL)
    return -1;
  if(root->data==val1)
    return val1;
  if(root->data==val2)
    return val2;
  int l=lcaInBST(root->left,val1,val2);
  int r=lcaInBST(root->right,val1,val2);
  
  if(l==-1)
    return r;
  else if(r==-1)
    return l;
  else 
  {
    return root->data;
  }
  
}

//To find the sum of nodes from root to leaf
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k, string s="") 
{
  
  if(root==NULL)
    return;
  if(root->left==NULL&&root->right==NULL)
  {
    if(k==root->data)
    {
      
    cout<<s+to_string(root->data);
    cout<<endl;
    }
    return;
  }

  rootToLeafPathsSumToK(root->left,k-root->data,s+to_string(root->data)+" ");
  
  rootToLeafPathsSumToK(root->right,k-root->data,s+to_string(root->data)+" ");

}

//To make a BSt into sorted linked list
pair<Node<int>*, Node<int>*> BSTll(BinaryTreeNode<int>* root)
{
  if(root==NULL)
  {
    pair<Node<int>*,Node<int>*> p;
    p.first=NULL;
    p.second=NULL;
    return p;
  }
  pair<Node<int>*,Node<int>*> p1=BSTll(root->left);
  pair<Node<int>*,Node<int>*> p2=BSTll(root->right);
  pair<Node<int>*,Node<int>*> p;
  
  Node<int>* newnode= new Node<int>(root->data);
  if(p1.first==NULL)
    p.first=newnode;
  else
    p.first=p1.first;
    
  if(p1.second!=NULL)
    p1.second->next=newnode;
  newnode->next=p2.first;
  
  if(p2.second==NULL)
    p.second=newnode;
  else
    p.second=p2.second;
  
  return p;
}

Node<int>* constructBSTLL(BinaryTreeNode<int>* root) {
    
  return BSTll(root).first;
    
}