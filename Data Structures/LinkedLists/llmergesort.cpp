#include <iostream>
#include "node.cpp"
using namespace std;

node* merge(node *head1, node *head2) 
{
   
  node* head=NULL;
  node* tail=NULL;
  node* temp;
  while(head1!=NULL&&head2!=NULL)
    {
      if(head1->data<=head2->data)
      {
        temp=head1;
        head1=head1->next;
      }
      else
      {
        temp=head2;
        head2=head2->next;
      }
    	if(head==NULL)
    	{
    	  head=temp;
    	  tail=temp;
    	}
    	else
    	{
    	  tail->next=temp;
    	  tail=temp;
    	}
    }
  if(head1!=NULL)
    tail->next=head1;
  if(head2!=NULL)
    tail->next=head2;
  return head;
}

node* mergeSort(node *head) 
{
    
  int n=length(head);
  if(n==0||n==1)
    return head;
  node* head1=head;
  node* head2=NULL;
  node* temp=head;
  int i=0;
  while(temp!=NULL)
  {
  	if(i<(n/2)-1)
  	{
  		temp=temp->next;
  		i++;
  	}
  	else
  	{
  		head2=temp->next;
  		temp->next=NULL;
  		break;
  	}
  }
  print(head1);
  print(head2);
  head1=mergeSort(head1);
  head2=mergeSort(head2);
  return merge(head1,head2);
}

int main()
{
	node* head;
	head=insertend();
	print(head);
	head=mergeSort(head);
	print(head);

}