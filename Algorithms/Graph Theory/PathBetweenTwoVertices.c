#include<stdio.h>
int a[100][100],n,s,d;

int path[100];
int visit[100];
int path_index;

void creategraph();
void findpath(int,int);

void creategraph()
{
  int i,j;
  while(1)
  {
      printf("Enter the source and the destination vertex..");
      scanf("%d%d",&i,&j);
      if((i==0)&&(j==0))
         break;
      a[i][j]=1;  //Adjacency Matrix
   }
}

void findpath(int start,int end)
{
  int boo;
  visit[start] = 1;
  path[path_index++] = start;  //path_index starts from 0

  if(start == end)
  {
    for(int i = 0;i<path_index;i++)
    {
      printf("%d ",path[i]);
    }
    printf("\n");
  }

  else
  {
    for(int j = 1 ;j <= n;j++)
    {
      boo = a[start][j];
      if(!visit[j] && boo == 1)
        findpath(j,end);
    }
  }
  path_index--;
  visit[start] = 0;
}

int main()
{  
  printf("Enter the number of vertices..");
  scanf("%d",&n);
  creategraph();
  
  printf("Enter start and end vertice = ");
  scanf("%d %d",&s,&d);
  findpath(s,d);
}