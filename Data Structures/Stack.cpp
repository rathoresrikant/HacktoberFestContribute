#include<iostream>
using namespace std;
template <typename k, typename v>
struct TNode
{
k key;
v value;
TNode<k, v> *leftChild;
TNode<k, v> *rightChild;
};
template<class T>
class Node
{
public:
	Node()
	{
		next=nullptr;
	}
    TNode<int,int> *data;
	Node<T> * next;
	
};
template<class T>
class stack
{
  Node<T> * top;
public:
	stack()
	{
		top=nullptr;
	}
	template<typename k,typename v>
	bool push(TNode<k,v> * val)
	{
		if(this==nullptr)
		{
			Node<T> * temp=new Node<T>();
			temp->data=val;
			temp->next=nullptr;
			top=temp;
			return true;
		}
		else
		{
		Node<T>* temp=new Node<T>();
		temp->data=val;
		temp->next=top;
		top=temp;
		return true;
		}
		return false;
	}
	template<typename k,typename v>
	bool pop(TNode<k,v> *& val)
	{
		if(top!=nullptr && top->next!=nullptr)
		{
			Node<T> * temp=nullptr;
		   temp=top;
		   top=top->next;
		   temp->next=nullptr;
		   val=temp->data;
		   delete temp;
		}
		else if(top->next==nullptr)
		{
			val=top->data;
			delete top;
			top=nullptr;
			return true;
		}
		else
		{
			return false;
		}
	}

	T _top()
	{
		return top->data;
	}
	bool isempty()
	{
		if(top==nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	~stack()
	{
		if(top!=nullptr)
		{
			delete top;
		}
	}
};
template<typename k,typename v>
class BST
{
	TNode<k,v> * root;
public:
	BST()
	{
		root=nullptr;
	}
	TNode<k,v> * helper(TNode<k,v> * fromCopy)
	{
		if(fromCopy==nullptr)
			return nullptr;
		TNode<k,v> * temp=new TNode<k,v>();
		temp->key=fromCopy->key;
		temp->value=fromCopy->value;
		temp->leftChild=helper(fromCopy->leftChild);
		temp->rightChild=helper(fromCopy->rightChild);
		return temp;
	}
	BST(BST & obj)
	{
		this->root=helper(obj.root);
	}
	TNode<k,v> * NewNode(k key,v value)
	{
		TNode<k,v> * n=new TNode<k,v>();
		n->key=key;
		n->value=value;
		n->rightChild=n->leftChild=nullptr;
		return n;
	}
	TNode<k,v> * HelperInsert(TNode<k,v>*R,k key,v value)
	{
		if(R==nullptr)
			return NewNode(key,value);
		if(R->key>key)
			R->leftChild=HelperInsert(R->leftChild,key,value);
		else if(R->key<key)
		{
			R->rightChild=HelperInsert(R->rightChild,key,value);
		}
		else if(R->key==key)
		{
			return R;
		}
		return R;
	}
	void insert(k const key, v const value)
	{
		root=HelperInsert(this->root,key,value);
	}
	v * helpsearch(TNode<k,v>* R,k key)
	{
		int * ret;
		if(R==nullptr)
			return nullptr;
		if(R->key>key)
			ret=helpsearch(R->leftChild,key);
		else if(R->key<key)
		{
			ret=helpsearch(R->rightChild,key);
		}
		else if(R->key==key)
		{
			ret=&R->value;
			return ret;
		}
		return ret;
	}
	v* search(k key)
	{
		return helpsearch(this->root, key);
	}
	void helpInorder(TNode<k,v> * R)
	{
		if(R!=nullptr)
		{
			helpInorder(R->leftChild);
			cout<<R->key<<'\t';
			helpInorder(R->rightChild);
		}
	}
	void inorderPrintKeys()
	{
		cout<<"Inorder Keys of Tree\n";
		helpInorder(this->root);
	}
	void helplength(TNode<k,v> * R,int &count)
	{
		
		if(R!=nullptr)
		{
			helplength(R->leftChild,count);
			count++;
			helplength(R->rightChild,count);
		}
	}
	int length()
	{
		int count=0;
		helplength(this->root,count);
		return count;
	}
	TNode<k,v>* min(TNode<k,v>* node)
     {
        TNode<k,v>* current = node;
        while (current && current->leftChild != NULL)
			current = current->leftChild;
 
        return current;
	 }
	TNode<k,v> * helpdelete(TNode<k,v>* R,k key)
	{
		if(R==nullptr)
			return R;
		if(key<R->key)
			R->leftChild=helpdelete(R->leftChild,key);
		else if(key>R->key)
			R->rightChild=helpdelete(R->rightChild,key);
		else
		{
			if(R->leftChild==nullptr)
			{
				TNode<k,v> * n=R->rightChild;
				delete R;
				return n;
			}
			else if(R->rightChild==nullptr)
			{
				TNode<k,v> * n=R->leftChild;
				delete R;
				return n;
			}
			TNode<k,v>* temp = min(R->rightChild);
            R->key = temp->key;
			R->rightChild = helpdelete(R->rightChild, temp->key);
    }
    return R;
	}
	void deleteKey(k key)
	{
		helpdelete(this->root,key);
	}
	void  Covertintomirror(BST & obj)
	{
		this->root=new TNode<k,v>();
		TNode<k,v> * mirror=this->root; 
		stack<k> s;
		stack<k> s2;
		int forbool=0;
		TNode<k,v> *current=obj.root;
		while (current!=nullptr || s.isempty()==false)
		{
		while(current!=nullptr)
		{
			s.push(current);
			s2.push(mirror);
			current=current->leftChild;
			if(current!=nullptr)
			{
				mirror->rightChild=new TNode<k,v>();
				mirror=mirror->rightChild;
			}
			else
			{
				mirror->rightChild=current;
			}
		}
		s.pop(current);
		s2.pop(mirror);
		mirror->key=current->key;
		mirror->value=current->value;
		current=current->rightChild;
		if(current!=nullptr)
			{
				mirror->leftChild=new TNode<k,v>();
				mirror=mirror->leftChild;
			}
		else
		{
			mirror->leftChild=current;
		}
		}
	}
	int height(TNode<k,v> * N)
	{
		if(N==nullptr)
		{
			return 0;
		}
		int lh=height(N->leftChild);
		int rh=height(N->rightChild);
		if(lh>rh)
			return lh+1;
		else
		{
			return rh+1;
		}
	}
	~BST()
	{
		if(root!=nullptr)
		{
			delete [] root;
		}
	}
};
void main()
{
	//Binary tree created on the bases of key smaller element then root on left and greater on right
	BST<int,int> p;
	p.insert(5,1);
	p.insert(3,3);
	p.insert(7,4);
	p.insert(2,5);
	p.insert(4,2);
	p.insert(6,7);
	p.insert(8,4);
	p.inorderPrintKeys();
	BST<int,int> p1;
	p1.Covertintomirror(p);
	cout<<"\nMirror of Above Tree\n";
	p1.inorderPrintKeys();
	cout<<endl;
	system("pause");
}