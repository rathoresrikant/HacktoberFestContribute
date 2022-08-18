#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};
struct node *root = NULL;

void display();
void insert(int data,int position);
void create(int n);

int main(){
	int n,data,position;
	cout<<"Enter the length of the list-";
	cin>>n;
	create(n);
	cout<<"Enter the node to be inserted-";
	cin>data;
	cout<<"Enter the position-";
	cin>>position;
	insert(data,position);
	cout<<"The final list becomes-\n";
	display();
	return(0);
}

void create(int n){
	struct node *temp, *newNode;
	int data,i;
	
	root = (struct node*)malloc(sizeof(struct node));
	if(root==NULL){
		cout<<"Unable to allocate memory";
	}
	else{
		cout<<"Enter data in node 1 -";
		cin>>data;
		root->data = data;
		root->link = NULL;
		
		temp = root;
		
		for(i=2;i<=n;i++){
			newNode = (struct node*)malloc(sizeof(struct node));
			
			if(newNode==NULL){
			cout<<"Unable to allocate memory";
			break;}
			
			else{
				cout<<"Enter the data in node -"<<i;
				cin>>data;
				
				newNode->data = data;
				newNode->link = NULL;
				
				temp->link = newNode;
				temp = temp->link;
			}
		}
		cout<<"List created successfully\n";
	}
}

void insert(int data, int position){
	int i;
	struct node *temp,*newNode;
	
	newNode = (struct node*)malloc(sizeof(struct node));
	
	if(newNode==NULL)
	cout<<"Unable to allocate";
	
	else{
		newNode->data = data;
		newNode->link = NULL;
		
		temp = root;
		
		for(i=2;i<position;i++){
			temp = temp->link;
			if(temp == NULL)
			break;
		}
		if(temp!=NULL){
			newNode->link = temp->link;
			temp->link = newNode;
			cout<<"Data inserted successfully\n";
		}
		else{
			cout<<"Unable to insert";
		}
	}
}

void display(){
	struct node *temp;
	if(root==NULL)
	cout<<"list empty";
	else{
		temp =root;
		while(temp!=NULL){
			cout<<"Data = "<<temp->data;
			temp = temp->link;
		}
	}
}