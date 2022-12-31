#include <iostream>
#include <stdlib.h>

struct node {
    int num;
    struct node * nextptr;
}*startnode;
 

void creation(int n);
void display();

int main() //main method
{
    int n;
    startnode = NULL;

    printf("Enter the number of nodes : ");
    scanf("%d", &n);
 
    creation(n); 
    display();
    return 0;
}

void creation(int n)//function to create list
{
    int i, num;
    struct node *preptr, *newnode;

    if(n >= 1)
    {
        startnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data for node 1 : ");
        scanf("%d", &num);
        startnode->num = num;
        startnode->nextptr = NULL;
        preptr = startnode;
        for(i=2; i<=n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter data for node %d : ", i);
            scanf("%d", &num);
            newnode->num = num;
            newnode->nextptr = NULL;	
            preptr->nextptr = newnode;	
            preptr = newnode;   		
        }
        preptr->nextptr = startnode; 		
    }
}

void display() //function to display list 
{
    struct node *tmp;
    int n,i;

    if(startnode == NULL)
    {
        printf("List is empty");
    }
    else
    {
        tmp = startnode;
        printf("\nData entered in the list are :\n");

      do {
            printf("Node %d : %d\n", n, tmp->num);

            tmp = tmp->nextptr;
            n++;
        }while(tmp != startnode);
    }
}
