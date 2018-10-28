#include<iostream>
#include<process.h>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>

using namespace std;
class treenode
{
	treenode* leftchild;
	int data;
	treenode* rightchild;
	public:
	treenode(int element=0)
	{
		data=element;
		leftchild=NULL;
		rightchild=NULL;
	}
	treenode* insert(int,treenode*);
	void inorder(treenode*);
	void preorder(treenode*);
	void Iterpreorder(treenode*);
	treenode* parent(treenode *curr,int ele, treenode *prev);
	void level_order(treenode*);
	treenode *copy(treenode*);
	int depth(treenode *ptr);
	void ancestors(int ele);
};


treenode* root=NULL;

void treenode::ancestors(int ele)
{
	treenode *p;
	p=parent(root, ele, root);
	while(1)
	{
		p=parent(root, p->data, root);
		if(p==root)	break;
	}
}


treenode* treenode::parent(treenode *curr,int ele, treenode *prev)
{
	if(curr!=NULL)
	{
		parent(curr->leftchild, ele, curr);
		if(ele==curr->data)
		{
			cout<<"\n parent : "<<prev->data;
			return prev;
		}
		parent(curr->rightchild, ele , curr);
	}
}

int treenode::depth(treenode *ptr)
{
int ldepth,rdepth;
if(ptr==NULL)	return 0;
else
    {   ldepth=depth(ptr->leftchild);
	rdepth=depth(ptr->rightchild);
	if(ldepth>rdepth) 	return ldepth+1;
	else 		return rdepth+1;
    }
}

treenode *treenode::copy(treenode *ptr)
{
    treenode *temp;
    if(ptr)
    {
	temp=new treenode;
	if(ptr->leftchild) temp->leftchild=copy(ptr->leftchild);
	if(ptr->rightchild) temp->rightchild=copy(ptr->rightchild);
	temp->data=ptr->data;
	return(temp);
    }
    return(NULL);
}


treenode *treenode::insert(int item,treenode* root)
{
	treenode* temp=new treenode(item);
	if(root==NULL)
	{
		root=temp;
		return root;
	}
	else
	{
		char direction[20];
		cout<<"enter direction in uppercase: ";
		cin>>direction;
		treenode* current;
		treenode* prev;
		prev=NULL;
		current=root;
		int i;
		for(i=0;i<strlen(direction)&&current!=NULL;i++)
		{
			prev=current;
			if(direction[i]=='L')
				current=current->leftchild;
			else
				current=current->rightchild;
		}
		if(current!=NULL||i!=strlen(direction))
		{
			cout<<"insertion not possible";
			delete temp;
			return root;
		}
		if(direction[i-1]=='L')
			prev->leftchild=temp;
		else
			prev->rightchild=temp	;
	}
	return root;
}
void treenode::preorder(treenode* ptr)
{
int top=-1;
treenode *stack[10];

do{
    for(;ptr;ptr=ptr->leftchild)
    {
	cout<<ptr->data<<" ";
	stack[++top]=ptr;
    }


    if(top>=0)          ptr=stack[top--];
    else                break;

    ptr=ptr->rightchild;

}while(1);
}
void treenode::inorder(treenode* ptr)
{
int top=-1;
treenode *stack[10];

do{
    for(;ptr;ptr=ptr->leftchild)
	stack[++top]=ptr;

    if(top>=0)          ptr=stack[top--];
    else                break;

    cout<<ptr->data;
    ptr=ptr->rightchild;

}while(1);
}

void treenode::level_order(treenode* ptr)
{
    int front=-1;
    int rear=-1;
    treenode *Q[10];
    if(!ptr)   return;
    Q[++rear]=ptr;
    do
    {
	ptr=Q[++front];
       //	if(ptr)
//	{
	   cout<<ptr->data<<" ";
	    if(ptr->leftchild)      Q[++rear]=ptr->leftchild;
	    if(ptr->rightchild)     Q[++rear]=ptr->rightchild;
  //	}

    }while(front!=rear);
}

int main()
{
	int ch,f,ele;
	int a;
	treenode x,*p;
do
{
cout<<"\n1:create,2:pre.3:in,4:post,5:parent 6.depth 7.ancestors 8.exit\n";
cin>>ch;
switch(ch)
{
	case 1:	cout<<"enter element";
		cin>>a;
		root=x.insert(a,root);
		break;
	case 2:
		x.preorder(root);
		break;
	case 3:	x.inorder(root);
		break;
	case 4:	//x.postorder(root);
  		break;
	case 5:
		cout<<"Enter the ele: ";
		cin>>ele;
		x.parent(root,ele,root);
		break;
	case 5: 	//x.level_order(root);
  		break;
	case 6: 	cout<<"\nDepth of the tree: "<<x.depth(root)<<endl;
		break;

	case 7: cout<<"Enter the ele: ";
		cin>>ele;
		x.ancestors(ele);
		break;

	case 8: exit(0);
}
}while(1);
}
