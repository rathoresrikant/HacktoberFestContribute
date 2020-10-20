#include<iostream.h>
#include<conio.h>
#include<process.h>
struct node
{
	node *next;
	int i;
};
class stack
{
	node *top;
	public:
	stack()
	{
		top=NULL;
	}
	void add();
	void show();
	void del();
}s;
void stack::add()
{
	node *temp;
	temp=new node;
	if(temp==NULL)
	{
		cout<<"\nMemory is full\n";
	}
	else
	{
		cout<<"\nThe element to be inserted is:\n";
		cin>>temp->i;
		temp->next=top;
		top=temp;
	}
}
void stack::show()
{
	node *temp;
	if(top==NULL)
	{
		cout<<"\nStack is empty\n";
	}
	else
	{
		temp=top;
		while(temp!=NULL)
		{
			cout<<temp->i<<'\t';
			temp=temp->next;
		}
	}
}
void stack::del()
{
	node*temp;
	if(top==NULL)
	{
		cout<<"\nStack is empty\n";
	}
	else
	{
		temp=top;
		top=top->next;
		temp->next=NULL;
		delete temp;
	}
}
void main()
{
	clrscr();
	int x;
	char ch;
	do
	{
		cout<<"\n1.Push\n2.Pop\n3.Show\n\n\nEnter your choice";
		cin>>x;
		switch(x)
		{
			case 1 :	s.add();
					break;
			case 2 :	s.del();
					break;
			case 3 :	s.show();
					break;
			default :	cout<<"Wrong Choice!!!!!!";
		}
		cout<<"\nDo you want to continue\n";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	getch();
}