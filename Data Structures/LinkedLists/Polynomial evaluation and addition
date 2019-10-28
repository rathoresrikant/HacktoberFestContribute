#include<stdio.h>
#include<stdlib.h>
#include<math.h>

 struct node
 {
  int coeff;
  int px;
  int py;
  struct node *next;
 };
  void insert_tail(int,int,int,struct node**);
  void display(struct node *);
  int polyevaluate(struct node *);
  struct node *poly_add(struct node *p1,struct node *p2);
 main()
 {
  struct node *first;
  struct node *second;
  struct node *poly3;
  struct node *third;
  first = second = NULL;
  int cf,px,py,result;
  int cf2,px2,py2,result2;
  printf("Enter details of first polynomial\n");
  while(1)
  {

      printf("\nEnter the coefficient..\n");
      scanf("%d",&cf);
      if(cf==0)
        break;
      printf("\nEnter the power of x..\n");
      scanf("%d",&px);
      printf("\nEnter the power of y...\n");
      scanf("%d",&py);
      insert_tail(cf,px,py,&first);
  }
  printf("Enter details of second polynomial\n");
  while(1)
  {
      printf("\nEnter the coefficient..\n");
      scanf("%d",&cf2);
      if(cf2==0)
        break;
      printf("\nEnter the power of x..\n");
      scanf("%d",&px2);
      printf("\nEnter the power of y...\n");
      scanf("%d",&py2);
      insert_tail(cf2,px2,py2,&second);

   }
   printf("\nThe first polynomial is...\n");
   display(first);
   printf("\nThe second polynomial is...\n");
   display(second);
   printf("\nEvaluating first polynomial..\n");
   result=polyevaluate(first);
   printf("Result=%d",result);
   printf("\nEvaluating second polynomial..\n");
   result2=polyevaluate(second);
   printf("Result=%d",result2);

   printf("\nSum of two polynomials is:\n");
   third=poly_add(first,second);
  }

   int polyevaluate(struct node *p)
   {
     int x,y,sum;
     printf("\nEnter the value of x and y..");
     scanf("%d %d",&x,&y);
     sum=0;
     while(p!=NULL)
     {
       sum=sum+(p->coeff*pow(x,p->px)*pow(y,p->py));
       p=p->next;
     }
    return sum;
 }

   void display(struct node *q)
    {
      while(q!=NULL)
      {
         if(q->coeff>0)
          printf("%d",q->coeff);
         else
          printf("%d",q->coeff);
         if(q->px>0)
         {
           if(q->px==1)
             printf("X ");
           else
             printf("X^%d ",q->px);;
          }
          if(q->py>0)
          {
           if(q->py==1)
            printf("Y");
           else
            printf("Y^%d +",q->py);
          }
         q=q->next;
       }
     }



    void insert_tail(int cf,int px,int py, struct node **p)
    {
      struct node *q,*temp;
      temp=(struct node*)malloc(sizeof(struct node));
      temp->coeff=cf;
      temp->px=px;
      temp->py=py;
      temp->next=NULL;

      q=*p;
      if(q==NULL)
        *p=temp;
      else
       {
        while(q->next!=NULL)
          q=q->next;
        q->next=temp;
      }
    }




    struct node *poly_add(struct node *p1,struct node *p2)
{
    struct node *poly3;
    while((p1 != NULL) && (p2 != NULL))
    {
        if (p1->px == p2->px && p1->py && p2->py)
        {
            insert_tail(p1->coeff+p2->coeff,p1->px,p1->py,&poly3);
            p1 = p1->next;
            p2 = p2->next;
        }
        else
        {
            if(p1->px > p2->px)
             {
                insert_tail(p1->coeff,p1->px,p1->py,&poly3);
                p1 = p1->next;
             }
             else
             {
                 insert_tail(p2->coeff,p2->px,p2->py,&poly3);
                 p2 = p2->next;
             }
    }
  }
  if (p1== NULL)
  {
      while (p2!=NULL)
      {
          insert_tail(p2->coeff,p2->px,p2->py,&poly3);
          p2 = p2 ->next;
      }
  }
  else
  {
      while (p1!=NULL)
      {
          insert_tail(p1->coeff,p1->px,p1->py,&poly3);
          p1 = p1->next;
      }
  return poly3;
}
}





