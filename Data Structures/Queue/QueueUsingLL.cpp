#include<iostream>
using namespace std;
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};
void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=new queue *[q->size];
}
void enqueue(struct Queue *q,struct Node *x)
{
    if((q->rear+1)%q->size==q->front)
        printf("Queue is Full");
   else
        {
            q->rear=(q->rear+1)%q->size;
            q->Q[q->rear]=x;
        }
}
struct Node * dequeue(struct Queue *q)
{
    struct Node* x=NULL;
    if(q->front==q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
int isEmpty(struct Queue q)
{
return q.front==q.rear;
}

struct node *root;
void treecreate()
{
    struct node *p,*t;
    int x,x1,x2;
    struct queue q;
    create(&q,100);
    cout<<"enter root value";
    cin>>x;
    root=new node;
    root->data=x;
    root->lchild=root->rchild=0;
    enqueue(&q,root);
    while(!isempty)
    {
        p=dequeue(&q);
        cout<<"enter left child of"<<p->data;
        cin>>x1;
        if(x1!=-1)
        {
            t=new node;
            t->data=x1;
            p->lchild=t;
            t->lchild=t->rchild=0;
            enqueue(&q,t);
        }
        cout<<"enter right child of"<<p->data;
        cin>>x2;
        if(x2!=-1)
        {
            t=new node;
            t->data=x2;
            p->rchild=t;
            t->lchild=t->rchild=0;
            enqueue(&q,t);
        }
    }
}
void preorder(struct node *p)
{
    if(p)
    {
        cout<<p->data;
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
int main()
{
    treecreate();
    preorder(root);
}































