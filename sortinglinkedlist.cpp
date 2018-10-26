#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
struct ListNode
{
	string name;
	int roll;
	ListNode * next;
};
ListNode * head = NULL;
void append (string, int);
void insertname (string, int);
void insertroll (string, int);
void deletenode (int);
void deletenode (string);
void deleteall ();
void printing ();
void sorting ();
void exitprog ();
void main ()
{
	int select, roll, num;
	string name;
	while (1)
	{
		cout<<"Press 1 for appending the node"<<endl;
		cout<<"Press 2 for inserting the node"<<endl;
		cout<<"Press 3 for deleting the node"<<endl;
		cout<<"Press 4 for deleting the list"<<endl;
		cout<<"Press 5 for printing the list"<<endl;
		cout<<"Press 6 for sorting the list"<<endl;
		cout<<"Press 7 to exit the program"<<endl;
		cin>>select;
		switch (select)
		{
		case 1:
			cout<<"Please enter the name of the student: ";
			cin.ignore (10000,'\n');
			getline (cin, name);
			cout<<"Please enter the roll number of the student: ";
			cin>>roll;
			append (name, roll);
			break;
		case 2:
			cout<<"Press 1 to sort on the basis of name or 2 to sort on the basis of roll number: ";
			cin>>num;
			cout<<"Please enter the name of the student: ";
			cin.ignore (10000,'\n');
			getline (cin, name);
			cout<<"Please enter the roll number of the student: ";
			cin>>roll;
			if (num == 1)
			{
				insertname (name, roll);
			}
			else if (num == 2)
			{
				insertroll (name, roll);
			}
			break;
		case 3:
			cout<<"Press 1 to delete the node on the basis of name or 2 to delete on the basis of roll number: ";
			cin>>num;
			if (num == 1)
			{
				string value;
				cout<<"Please enter the name: ";
				cin.ignore (10000,'\n');
				getline (cin, value);
				deletenode (value);
			}
			else if (num == 2)
			{
				int value;
				cout<<"Please enter the roll number: ";
				cin>>value;
				deletenode (value);
			}
			else
			{
				cout<<"You have entered an invalid input...!"<<endl;
			}
			break;
		case 4:
			deleteall ();
			break;
		case 5:
			printing ();
			break;
		case 6:
			sorting ();
			break;
		case 7:
			exitprog ();
		default:
			cout<<"You have entered an invalid input...!"<<endl;
			break;
		}
	}
}
void append (string name, int roll)
{
	ListNode * temphead = head;
	ListNode * temp = new ListNode;
	temp->name = name;
	temp->roll = roll;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;	
	}
	else
	{
		while (temphead->next)
		{
			temphead = temphead->next;
		}
		temphead->next = temp;
	}
}
void insertname (string name, int roll)
{
	ListNode * temp = new ListNode;
	temp->next = NULL;
	temp->name = name;
	temp->roll = roll;
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		ListNode * temphead = head;
		ListNode * previous = NULL;
		while (temphead != NULL && name > temphead->name)
		{
			previous = temphead;
			temphead = temphead->next;
		}
		if (previous == NULL)
		{
			head = temp;
			temp->next = temphead;
		}
		else if (temphead == NULL)
		{
			previous->next = temp;
		}
		else
		{
			previous->next = temp;
			temp->next = temphead;
		}
	}
}
void insertroll (string name, int roll)
{
	ListNode * temp = new ListNode;
	temp->next = NULL;
	temp->name = name;
	temp->roll = roll;
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		ListNode * temphead = head;
		ListNode * previous = NULL;
		while (temphead != NULL && roll > temphead->roll)
		{
			previous = temphead;
			temphead = temphead->next;
		}
		if (previous == NULL)
		{
			head = temp;
			temp->next = temphead;
		}
		else if (temphead == NULL)
		{
			previous->next = temp;
		}
		else
		{
			previous->next = temp;
			temp->next = temphead;
		}
	}
}
void deletenode (int roll)
{
	ListNode * temphead = head;
	ListNode * previous = NULL;
	ListNode * tempnext = NULL;
	while (temphead->roll != roll && temphead != NULL)
	{
		previous = temphead;
		temphead = temphead->next;
	}
	if (temphead == NULL)
	{
		cout<<"Sorry no data found!!!"<<endl;
	}
	else if (previous == NULL)
	{
		tempnext = temphead->next;
		head = tempnext;
		delete temphead;
	}
	else
	{
		tempnext = temphead->next;
		previous->next = tempnext;
		delete temphead;
	}
}
void deletenode (string name)
{
	ListNode * temphead = head;
	ListNode * previous = NULL;
	ListNode * tempnext = NULL;
	while (temphead->name != name && temphead != NULL)
	{
		previous = temphead;
		temphead = temphead->next;
	}
	if (temphead == NULL)
	{
		cout<<"Sorry no data found!!!"<<endl;
	}
	else if (previous == NULL)
	{
		tempnext = temphead->next;
		head = tempnext;
		delete temphead;
	}
	else
	{
		tempnext = temphead->next;
		previous->next = tempnext;
		delete temphead;
	}
}
void deleteall()
{
	ListNode * temphead = head, * temp;
	while (temphead)
	{
		temp = temphead->next;
		delete temphead;
		temphead = temp;
	}
	head = NULL;
}
void printing ()
{
	if (head == NULL)
	{
		cout<<"There is nothing to print."<<endl;
		return;
	}
	ListNode * temphead = head;
	while (temphead)
	{
		cout<<temphead->name<<' '<<temphead->roll<<endl;
		temphead = temphead->next;
	}
}
void sorting ()
{
	ListNode * temphead = head;
//	ListNode * tempnode = NULL;
	int temproll;
	string tempname;
	int counter = 0;
	while (temphead)
	{
		temphead = temphead->next;
		counter++;
	}
	for (int i=0; i<counter; i++)
	{
		for (int j=0; j<counter-i; j++)
		{
			if (temphead->roll > temphead->next->roll)
			{
//				tempnode = temphead;
//				temphead = temphead->next;
//				temphead->next = tempnode;
				temproll = temphead->roll;
				temphead->roll = temphead->next->roll;
				temphead->next->roll = temproll;

				tempname = temphead->name;
				temphead->name = temphead->next->name;
				temphead->next->name = tempname;
			}
		}
	}
}
void exitprog ()
{
	exit (0);
}
