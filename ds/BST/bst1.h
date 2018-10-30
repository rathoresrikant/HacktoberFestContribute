using namespace std;
template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    BinaryTreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST
{
	BinaryTreeNode<int>* root;
	bool searchutil(int k, BinaryTreeNode<int>* node)
	{
		if(node==NULL)
			return false;
		if(node->data==k)
			return true;
		else if(node->data>k)
			return searchutil(k,node->left);
		else
			return searchutil(k,node->right);

	}

	BinaryTreeNode<int>* insertUtil(int k,BinaryTreeNode<int>* node)
	{
		if(node==NULL)
		{
			BinaryTreeNode<int>* newnode=new BinaryTreeNode<int>(k);
			return newnode;
		}
		if(node->data>k)
			node->left=insertUtil(k,node->left);
		else 
			node->right=insertUtil(k,node->right);
		return node;

	}

	BinaryTreeNode<int>* deleteitemUtil(int k,BinaryTreeNode<int>* node)
	{
		if(node==NULL)
		{
			return NULL;
		}
		if(node->data>k)
			node->left=deleteitemUtil(k,node->left);
		else if(node->data<k)
			node->right=deleteitemUtil(k,node->right);


		else
		{
			
			if(node->left!=NULL&&node->right!=NULL)
			{
				BinaryTreeNode<int>* current;
				current=node->right;
				while(current->left!=NULL)
				{
					current=current->left;
				}
				node->data=current->data;
              	node->right=deleteitemUtil(current->data,node->right);
				return node;
			}
			else if(node->left!=NULL)
			{
				return node->left;

			}

			else if(node->right!=NULL)
			{
				return node->right;
			}

			else
				return NULL;
		}

	}

	void print(BinaryTreeNode<int>* root1) {
      if(root1==NULL)
        return;
      
      cout<<root1->data<<":";
      if(root1->left!=NULL)
        cout<<"L:"<<root1->left->data<<",";
      if(root1->right!=NULL)
        cout<<"R:"<<root1->right->data;
      cout<<endl;
      print(root1->left);
      print(root1->right);

      
 	}



public:
	BST()
	{
		root=NULL;
	}
	~BST()
	{
		delete root;
	}

	void insert(int k)
	{
		
		root= insertUtil(k,root);
	}

	void deleteData(int k)
	{
		root= deleteitemUtil(k,root);
	}

	void printTree()
	{
		print(root);
	}

	bool hasData(int k)
	{
		return searchutil(k,root);
	}
};
    

