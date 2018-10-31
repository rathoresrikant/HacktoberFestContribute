#include <iostream>
using namespace std;
#include "node.cpp"

node* swap_nodes(node *head,int i,int j)
{
	if(i==j)
		return head;
  node *t1, *t2,*temp1,*temp2,*temp;
  t1=t2=head;
  temp1=temp2=temp=NULL;
  int flag=0,a=i,b=j;
  while(i-1>0)
  {
    t1=t1->next;
    i--;
  }
  cout<<t1->data<<endl;

  while(j-1>0)
  {
    t2=t2->next;
    j--;
  }
  cout<<t2->data<<endl;
  if(a==0)
    temp=t2;
  else if(b==0)
    temp=t1;
  else flag=1;
  if(flag==0)
  {
    temp1=temp->next;
    temp2=temp->next->next;
    temp->next=head;
    temp1->next=head->next;
    head=temp1;
    temp->next->next=temp2;
  }
  else
  {
  	if(a-b==1||b-a==1)
  	{
  		if(t1->next==t2)
  		{
  		t1->next=t2->next;
  		t2->next=t1->next->next;
  		t1->next->next=t2;
  		}
  		else
  		{
  		t2->next=t1->next;
  		t1->next=t2->next->next;
  		t2->next->next=t1;
  		}

  	}
  	else
  	{
  	temp=t1->next;
    temp1=t1->next->next;
    temp2=t2->next->next;
    t1->next=t2->next;
    t2->next=temp;
    t1->next->next=temp1;
    t2->next->next=temp2;
	}
  }
  return head;
}

int main()
{
	node* head=insertend();
	print(head);
	head=swap_nodes(head,0,1);
	print(head);

}