
#include<stdio.h>
#include<stdlib.h>


struct Tree{
  int data;
  struct Tree*left_child,*right_child;
};


void insert_node(struct Tree**,int);
void inorder_show(struct Tree*);
void print_odd_level(struct Tree*,int);

/*  Create and insert newly BST Node.*/
void insert_node(struct Tree**root,int value){

  /* Create dynamic memory block and assign that address on new_node pointer */
  struct Tree*new_node=(struct Tree*)malloc(sizeof(struct Tree));
  
    /* Check newly memory block are created or not*/
  if(new_node)
  {
    new_node->left_child=NULL;
    new_node->right_child=NULL;
    new_node->data=value;
    if(*root)
    {
      struct Tree*temp=*root; 
      while(temp)
      {
        if(temp->data>=value)
        {
          if(temp->left_child!=NULL)
          {
            temp=temp->left_child;
          }
          else
          {
            temp->left_child=new_node;
            break;
          }
        }
        else
        {  

          if(temp->right_child!=NULL)
          {
            /*temp pointer Move to right_child memory block */

            temp=temp->right_child;
          }
          else
          {
            /*Assign newly created memory block address to temp->right_child pointer*/
            temp->right_child=new_node;
            break;
          }
        }
      }
      
    }
  else
  {
      *root=new_node;
    }
    
  }
  else {

    /*Not created memory by malloc function*/
   printf("\n memory Overflow");  

 }

}

/* Show BST node data using this function */
void inorder_show(struct Tree*temp){

  if(temp){
    inorder_show(temp->left_child);
    printf("  %d",temp->data);
    inorder_show(temp->right_child);
  }
  else
    return;

}

/* Help of this function show BST Odd level data*/
void print_odd_level(struct Tree*temp,int show){
  /* If temp Not NULL */
  if(temp)
  {
    print_odd_level(temp->left_child,show+1);
    print_odd_level(temp->right_child,show+1);
    if(show%2!=0){
      /* Print odd level BST node */
      printf(" %d",temp->data); 
    } 
  }
}



/*Main function*/
int main(){ 
   int n=0;
   printf("Enter -1 to stop insertion into the tree");
  struct Tree*root=NULL;
  while(1)
  {
    printf("enter node");
    scanf("%d",&n);
    if(n==-1)
      break;
     insert_node(&root,150);
  }
  if(root){
    printf("\n BST Inorder Data Is :"); 
    inorder_show(root);
    
    printf("\n Odd Level Nodes Is :");
    print_odd_level(root,1);
  }
  else{
    printf("\n Empty Tree ");
  }
  return 0; 

}

  
