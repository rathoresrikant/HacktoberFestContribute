#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node1;

void insert(node1 *pointer, int data){
        while(pointer->next!=NULL)
        {
                pointer = pointer -> next;                  //Iterate through the list till the last node is found.
        }
        pointer->next = (node1 *)malloc(sizeof(node1));       //Allocate memory for the new node and put data in it.
        pointer = pointer->next;
        pointer->data = data;
        pointer->next = NULL;
}

void print(node1 *pointer){
    if(pointer == NULL){
        return;
        }
    printf("%d ",pointer->data);        //Printing the elements using recursion.
    print(pointer->next);
}

void deletenode(node1 *pointer, int data){
    node1 *temp;
    while(pointer->next != NULL && pointer->next->data != data){
        pointer = pointer->next;
    }
    if(pointer->next == NULL){
        printf("List is empty!!!");
    }
    else{
        temp = pointer->next;
        pointer->next = temp->next;
        free(temp);
    }
}

int find(node1 *pointer,int key){
    while(pointer->next != NULL){
        if(pointer->data == key){
            return 1;
        }
        pointer = pointer->next;
    }
    return 0;
}

void sort(node1 *pointer){
    node1 *i, *j;
    //temp = create(1);
    int temp;
    for(i = pointer->next;i->next != NULL;i = i->next){
        for(j = pointer->next;j->next != NULL;j = j->next){
            if(j->data > j->next->data){
                temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
    print(pointer->next);
}

void unionList(node1 *pointer, node1 *start3, node1 *start2){
    node1 *j;
    j = pointer;
    int temp,num;
    while(pointer->next != NULL){
        pointer = pointer->next;
    }
    pointer->next = start2;
    printf("\n");
    print(j->next);
}

void interList(node1 *pointer, node1 *start3, node1 *start2){
    node1 *i, *j;
    int temp,num;
    for(i = pointer->next;i != NULL;i = i->next){
        for(j = start2->next;j != NULL;j = j->next){
            if(j->data == i->data){
                num = j->data;
                insert(start3,num);
                deletenode(j,num);
            }
        }
    }
    print(start3->next);
}

void reverse(node *start){
    node1 *current = start;
    node1 *prev = NULL;
    node1 *next = NULL;
    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    start = prev;
}

int main(){
    int fin, choice, data;
    struct Node *start;
    struct Node *temp;
    start = (node1 *)malloc(sizeof(node1));
    temp = start;
    temp -> next = NULL;

    struct Node *start2;
    struct Node *temp2;
    start2 = (node1 *)malloc(sizeof(node1));
    temp2 = start2;
    temp2 -> next = NULL;

    struct Node *start3;
    struct Node *temp3;
    start3 = (node1 *)malloc(sizeof(node1));
    temp3 = start3;
    temp3 -> next = NULL;


    printf("\n 1.Insert     2.Print     3.Delete     4.Find     5.Sort      6.Exit      7.Insert     8.Print     9.Delete     10.Union and Intersection     11.Reverse \n");
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter: ");
                    scanf("%d",&data);
                    insert(start,data);
                    break;
            case 2: print(start->next);
                    //print(start2->next);
                    break;
            case 3: printf("Enter: ");
                    scanf("%d",&data);
                    deletenode(start,data);
                    break;
            case 4: printf("Enter: ");
                    scanf("%d",&data);
                    fin = find(start,data);
                    if(fin){
                        printf("Found!");
                    }
                    else{
                        printf("Not found!");
                    }
                    break;
            case 5: sort(start);
                    break;
            case 6: exit(0);
                    break;
            case 7: printf("Enter: ");
                    scanf("%d",&data);
                    insert(start2,data);
                    break;
            case 8: print(start2->next);
                    break;
            case 9: break;
            case 10: interList(start,start3,start2);
                     unionList(start,start3,start2);
                     break;
            case 11: reverse(start);
                break;
        }
    }
    return 0;
}
