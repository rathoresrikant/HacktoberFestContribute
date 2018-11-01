#include <vector>
#include "treenode.h"
using namespace std;

//INPUT FUNCTION
TreeNode<int>* takeinput()
{
	int rootdata;
	//cout<<"Enter root data:"<<endl;
	cin>>rootdata;
	TreeNode<int>* root=new TreeNode<int>(rootdata);
	int ch;
	queue<TreeNode<int>*> q;
	q.push(root);
	while(!q.empty())
	{
		TreeNode<int>* k=q.front();
		q.pop();
		//cout<<"Enter the number of childrenren of node:"<<k->data<<endl;
		cin>>ch;
		for(int i=0;i<ch;i++)
		{
			//cout<<"Enter "<<i<<" children of "<<k->data<<endl;
			int children;
			cin>>children;
			TreeNode<int>* ch1=new TreeNode<int>(children);
			k->children.push_back(ch1);
			q.push(ch1);
		}
	}
	return root;
}

//PRINT FUNCTION WHICH IS BASIC AND SIMPLE BASICALLY, PREORDER TRAVERSAL
void print(TreeNode<int>* root)
{
	cout<<root->data<<":";
	for(int i=0;i<root->children.size();i++)
	{
		cout<<root->children[i]->data<<",";
	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++)
	{
		print(root->children[i]);
	}
}

//LEVEL ORDER TRAVERSAL
//USES QUEUE FOR LEVEL ORDER TRAVERSAL
void printLevelWise(TreeNode<int>* root) {
	queue<TreeNode<int>*> q;
	q.push(root);
	while(!q.empty())
	{
		TreeNode<int>* k=q.front();
		q.pop();
		cout<<k->data<<":";
		for(int i=0;i<k->children.size();i++)
		{
			cout<<k->children[i]->data;
			if(i!=k->children.size()-1)
				cout<<",";
			q.push(k->children[i]);
		}
		cout<<endl;
	}

}

//COUNTING THE NUMBER OF NODES
//MOSTLY, RECURSION IS USED BECAUSE OF SIMILAR SUBTREE STRUCTURE
int countnodes(TreeNode<int>* root)
{
	int k=1;
	for(int i=0;i<root->children.size();i++)
		k=k+countnodes(root->children[i]);
	return k;
}

int sumOfNodes(TreeNode<int>* root)
{
	int k=root->data;
	for(int i=0;i<root->children.size();i++)
		k=k+sumOfNodes(root->children[i]);
	return k;
}

//NODE WITH MAXIMUM DATA
TreeNode<int>* maxDataNode(TreeNode<int>* root) 
{
	if(root==NULL)
		return NULL;
	TreeNode<int>* k=root;
	for(int i=0;i<root->children.size();i++)
	{
		TreeNode<int>* m=maxDataNode(root->children[i]);
		if(m->data>k->data)
		k=m;
	}
	return k;
}

//HEIGHT CAN BE FROM 0 INDEXING OR 1 INDEXING
//FOR 1 INDEXING, NULL=0 INDEX
int height(TreeNode<int>* root)
{
	int m=0;
	for(int i=0;i<root->children.size();i++)
	{
		int k=height(root->children[i]);
		if(k>m)
			m=k;
	}
	return 1+m;
}

//DEPTH IS THE DISTANCE OF THE NODE FROM ROOT
//ROOT FROM ROOT HAS 0 DEPTH
void depth(TreeNode<int>* root,int k)
{
	if(k==0)
	{
		cout<<root->data<<" ";
		return;
	}

	for(int i=0;i<root->children.size();i++)
	{
		depth(root->children[i],k-1);
	}
}

//NUMBER OF LEAF NODES
int numLeafNodes(TreeNode<int>* root)
{
	if(root->children.size()==0)
		return 1;
	int k=0;
	for(int i=0;i<root->children.size();i++)
		k=k+numLeafNodes(root->children[i]);
	return k;
}

//TYPES OF TRAVERSALS
void preOrder(TreeNode<int>* root) {
   if(root==NULL)
     return;
  cout<<root->data<<" ";
  for(int i=0;i<root->children.size();i++)
    preOrder(root->children[i]);
  

}

//POST ORDER TRAVERSAL IS USED FOR DEALLOCATING THE TREE
void postOrder(TreeNode<int>* root) {
   if(root==NULL)
     return;
  for(int i=0;i<root->children.size();i++)
    postOrder(root->children[i]);
  cout<<root->data<<" ";

}

bool containsX(TreeNode<int>* root, int x) 
{
	if(x==root->data)
		return true;

	for(int i=0;i<root->children.size();i++)
	{
		bool ans=containsX(root->children[i],x);
		if(ans==true)
			return ans;
	}
	return false;

}

int nodesGreaterThanX(TreeNode<int> *root, int x) 
{
	int a;
	if(x<root->data) 
		a=1;
	else
		a=0;
	for(int i=0;i<root->children.size();i++)
	{
		a=a+nodesGreaterThanX(root->children[i],x);
	}
	return a;
}

#include<utility>
pair<TreeNode<int>*,int> maxSum(TreeNode<int> *root)
{
	int sum=root->data;
	for(int i=0;i<root->children.size();i++)
		sum=sum+root->children[i]->data;
    TreeNode<int>* k=root;
	for(int i=0;i<root->children.size();i++)
	{
		pair<TreeNode<int>*,int> m=maxSum(root->children[i]);
		int sum2=m.second;
		if(sum2>sum)
        {
			k=m.first;
          	sum=sum2;
        }
	}
    pair<TreeNode<int>*, int> p(k,sum);
	return p;

}

TreeNode<int>* maxSumNode(TreeNode<int> *root)
{
    pair<TreeNode<int>*,int> q=maxSum(root);
    return q.first;

}


bool isIdentical(TreeNode<int> *root1, TreeNode<int> * root2)
{
	if(root1->data!=root2->data)
		return false;
	else if(root1->children.size()!=root2->children.size())
		return false;
	else
	{
		for(int i=0;i<root1->children.size();i++)
		{
			bool k=isIdentical(root1->children[i],root2->children[i]);
			if(k==false)
				return false;
		}
		return true;
	}
}

#include<climits>
TreeNode<int>* nextLargerElement(TreeNode<int>* root, int n) 
{
	int k=INT_MAX;
	TreeNode<int>* ni;
	if(root->data>n)
	{
		k=root->data;
		ni=root;
	}
	else ni=NULL;
	
	for(int i=0;i<root->children.size();i++)
	{
		TreeNode<int>* t=nextLargerElement(root->children[i],n);
		if(t!=NULL)
			if(k>t->data)
			{
				ni=t;
				k=t->data;
			}
	}
	return ni;

}

TreeNode<int>* replace(TreeNode<int>* root, int x) 
{
	if(x==root->data)
		root->data=INT_MIN;

	for(int i=0;i<root->children.size();i++)
	{
		root->children[i]=replace(root->children[i],x);
	}
	return root;
}



TreeNode <int>* secondLargest(TreeNode<int> *root) 
{
    if(root->children.size()==0)
      return NULL;
	TreeNode<int>* l=maxDataNode(root);
	cout<<l->data<<endl;
  	int k=l->data;
    l->data=INT_MIN;
	TreeNode<int>* s=maxDataNode(root);
	cout<<s->data<<endl;

  	l->data=k;
  	if(s->data==l->data)
    {
    	//print(root);
      root=replace(root,s->data);
      //print(root);
      s=maxDataNode(root);
      if(s->data==INT_MIN)
        return NULL;
      else 
        return s;
    }
        
    else
        return s;
}

