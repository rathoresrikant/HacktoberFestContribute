#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	node *link;
};

typedef struct list
{
	node *address;
	list *link;
};

void addafter(list**,int);
void display(list*);

void main()
{
	int n;
	printf ("\nEnter number of Lists(/list) : ");
	scanf ("%d",&n);
	list *root=(list*)malloc(sizeof(list));
	root->address=NULL;
	root->link=NULL;
	addafter(&root,n);
	display(root);
}

void addafter(list **pt,int n)
{
	static int c=1,f;
	if(c <= n)
	{
		printf ("\nDo you want to continue with List number %d (y/n): ",c);
		fflush (stdin);
		if(getchar()=='y')
		{
			printf("\nEnter Data : ");
			fflush(stdin);
			scanf("%d",&f);

			if(((*pt)->link==NULL) && ((*pt)->address==NULL))
			{
				(*pt)->address=(node*)malloc(sizeof(node));
				(*pt)->address->data=f;
				(*pt)->address->link=NULL;
				addafter(pt,n);
			}
			else
			{
				list *Q=(*pt);
				while(Q->link != NULL)
				{
					Q=Q->link;
				}

				node *q=Q->address;

				if(Q->address == NULL)
				{
					Q->address=(node*)malloc(sizeof(node));
					Q->address->data=f;
					Q->address->link=NULL;
					addafter(pt,n);
				}
				else
				{

					while(q->link != NULL)
					{
						q=q->link;
					}
					node *temp=(node *)malloc(sizeof(node));
					temp->data=f;
					temp->link=NULL;
					q->link=temp;
					addafter(pt,n);
				}
			}
		}
		else
		{
			c++;
			list *Q=(*pt);
			while(Q->link != NULL)
			{
				Q=Q->link;
			}

			list *temp=(list *)malloc(sizeof(list));
			temp->address=NULL;
			temp->link=NULL;
			Q->link=temp;

			addafter(pt,n);
		}
	}
	else
	{
		//An extra list has been created due to pressing of 'n'...so we need to delete it
		list *Q=(*pt);
		while(Q->link->link != NULL)
		{
			Q=Q->link;
		}
		free(Q->link);
      Q->link=NULL;

		printf ("\n...Entry Successfully registered...\n");
		return ;
	}
}

void display(list *Q)
{
	node *q;
	static int k=1;
	if((Q->link==NULL) && (Q->address==NULL))
	{
		printf ("\n...No node has been created yet...\n");
		return ;
	}
	else
	{
		while(Q != NULL)
		{
			printf ("\n\nList%d =",k);
			q=Q->address;
			while(q != NULL)
			{
				printf (" %d",q->data);
				q=q->link;
			}
			k++;
			Q=Q->link;
		}
	}
	return ;
}

