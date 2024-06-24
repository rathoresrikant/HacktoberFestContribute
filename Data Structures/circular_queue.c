#include<stdio.h>
int circular_queue[10],n,e,ch,front=-1,rear=-1;
int isfull()
{
	if((front==rear+1)||(front==0 && rear==n-1))
	return 1;
	else 
	return 0;
}
int isempty()
{
	if(front==-1)
	return 1;
	else return 0;
}
void enqueue()
{
	if(isfull())
	printf("\n The queue is full: Overflow");
	else
	{
		if(front==-1)
		front=0;
		printf("\n Enter the element to be inserted: ");
		scanf("%d",&e);
		rear=(rear+1)%n;
		circular_queue[rear]=e;
	}
}
void dequeue()
{
	if(isempty())
	printf("\n The queue is Empty: Underflow");
	else
	{ 
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
		printf("\n The deleted value is: %d",circular_queue[front]);
		front=(front+1)%n;
		}
	}
}
void display()
{
	int i;
    if(isempty()) 
    printf(" \n Empty Queue\n");
    else
    {
        printf("\n Items are: ");
        for( i = front; i!=rear; i=(i+1)%n) 
       
            printf("%d ",circular_queue[i]);
            printf("%d ",circular_queue[rear]);
    }
      
}
int main()
{
	printf("\n Enter the size of the queue: ");
	scanf("%d",&n);
	do
	{
		printf("\n Your choices are: ");
		printf("\n\t1.Insert \n\t2.Delete\n\t3.Display\n\t4.Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:enqueue();
			break;
			case 2:dequeue();
			break;
			case 3:display();
			break;
			case 4:printf("\n Program has stopped!");
			break;
		}
	}while(ch!=4);
	return 0;
}
			
