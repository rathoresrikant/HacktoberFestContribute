#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*ptr=NULL,*head=NULL,*temp,*temp1;


initial()
{	int i;
	temp=(struct node *)malloc(sizeof(struct node));
	head=temp;
	puts("Enter numbers into linked list");
	for(i=0;i<4;i++)
	{	scanf("%d",&temp->data);
		temp1=(struct node *)malloc(sizeof(struct node));
		temp->link=temp1;
		temp=temp1;
	}
	temp->link=NULL;
	ptr=head;
	puts("The current linked list");
	while(ptr->link!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->link;
	}
	printf("\nFirst Item = %d\n",head->data);
}


insertion()
{	
	int c,key,item,m;
	struct node *ptr1=NULL,*prev=NULL;
	do{
	printf("\nInsert\n1:Begin\n2:End\n3:After a value\n");
	scanf("%d",&c);
	switch(c)
	{	case 1:	puts("Enter number to insert");
			scanf("%d",&item);
			temp1=(struct node *)malloc(sizeof(struct node));
			temp1->data=item;
			temp1->link=head;
			head=temp1;
			ptr=head;
			puts("The current linked list");
			while(ptr->link!=NULL)
			{
				printf("%d\t",ptr->data);
				ptr=ptr->link;
			}
			break;		
		case 2:	puts("Enter number to insert");
			scanf("%d",&item);
			temp1=(struct node *)malloc(sizeof(struct node));
			temp1->data=item;
			temp1->link=NULL;
			printf("\nNew Item = %d\n",temp1->data);
			ptr1=head;
			while(ptr1->link!=NULL)
			{
				printf("\n%d-->\n",ptr1->data);
				prev=ptr1;				
				ptr1=ptr1->link;
			}
			printf("\nLast Item = %d\n",ptr1->data);
			prev->link=temp1;
			ptr1=head;
			puts("The current linked list");
			while(ptr1!=NULL)
			{
				printf("%d\t",ptr1->data);
				ptr1=ptr1->link;
			}
			break;
		case 3:	puts("Enter number to insert after");
			scanf("%d",&key);
			puts("Enter number to insert");
			scanf("%d",&item);
			ptr=head;
			while(ptr->link!=NULL && ptr->data!=key)
				ptr=ptr->link;
			if(ptr->link==NULL)
				puts("Search fails");
			temp1=(struct node *)malloc(sizeof(struct node));
			temp1->link=ptr->link;
			ptr->link=temp1;
			temp1->data=item;
			ptr=head;
			puts("The current linked list");
			while(ptr->link!=NULL)
			{
				printf("%d\t",ptr->data);
				ptr=ptr->link;
			}
			break;			
		}
		puts("\nEnter 1 to continue");		
		scanf("%d",&m);
		}
		while(m==1);


}
					
main()
{	
	initial();
	insertion();
}
