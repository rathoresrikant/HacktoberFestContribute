#include <iostream>
#include "node.cpp"
using namespace std;

node* bubble_sort_LinkedList_itr(node* head)   
{
  int i=0,j=0;
  int l=length(head);
  node* prev,* curr,* next;
  prev=NULL;
  curr=head;
  next=curr->next;
  int count;
  while(i<l-1)
  {
  	count=0;
  	j=0;
    while(j<l-i-1)
    {
      if(curr->data > curr->next->data)
      {
        count++;
        if(prev==NULL)
        {
          curr->next=next->next;
          next->next=curr;
          head=next;
          prev=head;
          next=curr->next;
        }
        else
        {
          prev->next=next;
          curr->next=next->next;
          next->next=curr;
          prev=prev->next;
          next=curr->next;
        }
      }
      else
      {
      	prev=curr;
      	curr=curr->next;
        next=curr->next;
      }

      j++;
    }
    if(count==0)
    	break;
    
    i++;
    curr=head;
    prev=NULL;
    next=curr->next;
  }
  return head;
}


int main()
{
	node* head=insertend();
	print(head);
	head=bubble_sort_LinkedList_itr(head);
	print(head);
}