
/* Include header file*/
#include<stdio.h>
#include<stdlib.h>

/* Define struct of BST */
struct Tree{
  int data;/*Data field*/
  struct Tree*left_child,*right_child;/*Pointer field*/
};

/*Function declaration section*/
void insert_node(struct Tree**,int);
struct Tree* free_node(struct Tree*);
void inorder_show(struct Tree*);
void print_odd_level(struct Tree*,int);

/*  Create and insert newly BST Node.*/
void insert_node(struct Tree**root,int value){

  /* Create dynamic memory block and assign that address on new_node pointer */
  struct Tree*new_node=(struct Tree*)malloc(sizeof(struct Tree));
  
    /* Check newly memory block are created or not*/
  if(new_node)
  {
    /* Memory block are created successful */

    /* Assign left_child and right_child pointer value to NULL */

    new_node->left_child=NULL;

    new_node->right_child=NULL;

    /* Assign data value */
    new_node->data=value;

    /*Check BST root Pointer NULL or Not NULL*/ 
    if(*root)
    {

      struct Tree*temp=*root;

            /* find position to insert new_node.  */ 
      while(temp)
      {
        if(temp->data>=value)
        {
          if(temp->left_child!=NULL)
          {
            /*temp pointer Move to left_child memory block */
            temp=temp->left_child;
          }
          else
          {
            /*Assign newly created memory block address to temp->left_child pointer*/

            temp->left_child=new_node;
            /*Break loop*/
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
    else{

      /*When root pointer is NULL that means no element of BST tree then Assign this newly created memory block to root pointer*/
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


/* Help of this function Free BST Nodes */
struct Tree* free_node(struct Tree*temp){

  if(temp){
    temp->left_child=free_node((temp->left_child));
    temp->right_child=free_node(temp->right_child);
    free(temp);
    temp=NULL;
  }
  return NULL;
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
    /*Start execution*/ 

    /* BST structure pointer*/ 
  struct Tree*root=NULL;

    /*Suppose following data are inserted BST */ 
    /* 150, 70, 30, 90, 240, 110, 153, 650, 20, 10, 15, 660, 80*/
  insert_node(&root,150);
  insert_node(&root,70);
  insert_node(&root,30);
  insert_node(&root,90);
  insert_node(&root,240);
  insert_node(&root,110);
  insert_node(&root,153);
  insert_node(&root,650);  
  insert_node(&root,20);
  insert_node(&root,10);
  insert_node(&root,15);
  insert_node(&root,660);
  insert_node(&root,80);

  if(root){
    printf("\n BST Inorder Data Is :"); 
    inorder_show(root);
    
    printf("\n Odd Level Nodes Is :");
    print_odd_level(root,1);
    /*Free BST Node*/
    root=free_node(root);
  }
  else{
    printf("\n Empty Tree ");
  }
  return 0; 

}

  
