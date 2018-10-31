#include <iostream>
using namespace std;

class node{
	public:
	int data;
	node* next;
	node(int x)
	{
		data=x;
		next=NULL;
	}
};


	node* insertbeg()
	{
		node* head=NULL;
		int data;
		cin>>data;
		while(data!=-1)
		{
		node* newn=new node(data);
		if(head==NULL)
			head=newn;
		else
		{
			newn->next=head;
			head=newn;
		}
		}
		return head;
	}

	node* insertend()
	{
		node* head=NULL;
		node* tail=NULL;
		int data;
		cin>>data;
		while(data!=-1)
		{
		node* newn=new node(data);
		if(head==NULL)
		{
			head=newn;
			tail=newn;
		}
		else
		{
			tail->next=newn;
			tail=newn;
		}
		cin>>data;
		}
		return head;

	}

int length(node *head) 
{
  node*temp=head;
   if(temp==NULL)
     return 0;
  return 1+length(temp->next);
    
}


	void insertati(node* head, int i,int data)
	{
		node* newn=new node(data);
		node* temp=head;
  		int n=1;
  		while(n!=i-1&&temp->next!=NULL)
  		{
    		temp=temp->next;
    		n++;
    	}
  		if(n!=i-1)
  			return;
  		else
  		{
  			if(temp->next!=NULL)
  				newn->next=temp->next;
  			temp->next=newn;
  		}
	}

node* deleteati(node* head, int i)
{
  node* temp=head;
  int n=length(head);
  if(n<=i)
    return head;
  if(i==0)
  {
  	head=head->next;
  }
  else
  {
    int c=0;
  	while(c!=i-1)
    {
      temp=temp->next;
      c++;
    }
    temp->next=temp->next->next;
  	
  }
  return head;
  		
}

node* insertNodeRec(node *head, int i, int data) 
{
  if(i==0)
  {
    node* newnode=new node(data);
    newnode->next=head;
    head=newnode;
    return head;
  }
  else
  {
    int l=length(head);
    if(i>l)
      return head;
    else
    {
    	node* temp=head;
    	if(i-1>0)
          return insertNodeRec(temp->next,i-1,data);
      	else
        {
          node* newnode=new node(data);
          newnode->next=temp->next;
          temp->next=newnode;  
          return head;
        }
      
    }
  }
}

void print(node* head)
	{
		node* temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}

node* reverse(node* current, node* prev=NULL)
{
  node* head;
  if(current==NULL)
  {
    head=prev;
    return head;
  }
  head=reverse(current->next,current);
  current->next=prev;
  return head;
}

node *reverse_linked_list_rec(node *head)
{
  if(head->next==NULL)
    return head;
  node*  h=reverse_linked_list_rec(head->next);
  node* tail=head->next;
  tail->next=head;
  head->next= NULL;
  return h;
}

node* rev_linkedlist_itr(node* head)
{
  node* slow=NULL;
  node* fast=head;
  node* temp=head;
  while(temp!=NULL)
  {
    temp=fast->next;
    fast->next=slow;
    slow=fast;
    fast=temp;
  }
  return slow;
}

int indexOfNRecursive(node *head, int n) {
   if(head==NULL)
     return -1;
  if(head->data==n)
    return 0;
  int k=indexOfNRecursive(head->next,n);
  if(k!=-1)
    return 1+k;
  else return -1;
    
}


node* arrange_LinkedList(node* head)
{
  node* headev=NULL;
  node* tailev=NULL;
  
  node* headodd=NULL;
  node* tailodd=NULL;
  
  node* temp=head;
  while(temp!=NULL)
  {
    if((temp->data)%2==0)
    {
      if(headev==NULL)
        headev=tailev=temp;
      else
      {
        tailev->next=temp;
        tailev=temp;
      }
    }
    else
    {
      if(headodd==NULL)
        headodd=tailodd=temp;
      else
      {
        tailodd->next=temp;
        tailodd=temp;
      }
      
    }
    temp=temp->next;
  }
  if(headodd==NULL)
  {
    head=headev;
    tailev=NULL;
  }
  else if(headev==NULL)
  {
    head=headodd;
    tailodd=NULL;
  }
  else
  {
    tailodd->next=headev;
    tailev->next=NULL;
    head=headodd;
  }
   return head;
}


node* append_LinkedList(node* head,int n)
{
  int l=length(head);
  node* temp=head;
  while(l-n-1>0)
  {
    temp=temp->next;
    l--;
  }
  node* temp2=temp->next;
  temp->next=NULL;
  temp=temp2;
  while(temp->next!=NULL)
  {
    temp=temp->next;
  }
  temp->next=head;
  head=temp2;
  //delete temp;
  //delete temp2;
  return head;
  
}

node* eliminate_duplicate(node* head)
{
  node* t1=head;
  node* t2=t1->next;
  while(t2!=NULL)
  {
    if(t1->data==t2->data)
    {
      node* p=t2;
      t2=t2->next;
      delete p;
    }
    else
    {
      t1->next=t2;
      t1=t1->next;
      t2=t2->next;
    }
  }
  t1->next=t2;
 
  return head;
  
  
}

void print_linkedlist_spl(node*head)
{
  if(head==NULL)
    return;
  print_linkedlist_spl(head->next);
  cout<<head->data<<" ";
  
}

bool check_palindrome(node* head)
{
  
  int n=length(head);
  if(n-count==0||n-count==1)
    return true;
  node* temp=head;
  int i=1;
  while(i<n-count)
  {
    temp=temp->next;
    i++;
  }
  count++;
  if(head->data==temp->data)
    return check_palindrome(head->next);
  else
    return false;
  
}
node* midpoint_linkedlist(node *head)
{
  node* t1= head;
  node* t2= head;
  while(t2->next!=NULL&&t2->next->next!=NULL)
  {
    t2=t2->next->next;
    t1=t1->next;
  }
  return t1;

}
