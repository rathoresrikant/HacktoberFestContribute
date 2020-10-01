#include<stdio.h>
#include<stdlib.h>
int partition(int a[],int beg,int end);
void quicksort(int a[],int beg,int end);
void main()
{
    int i,n,t,arr[100],loc;
    printf("enter size of array\n");
    scanf("%d",&n);
    printf("enter the array\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    quicksort(arr,0,n-1);
    printf("sorted array is\n");
    for(i=0;i<n;i++)
        printf("%d",arr[i]);
}
int partition(int a[],int beg,int end)
{
     int left,right,loc,t;
    left=beg=loc;
    right=end;
    int flag=0;
    while(flag!=1)
    {
      while(a[loc]<=a[right] && (loc!=right))

        right--;
        if(loc==right)
        flag=1;
        else if(a[loc]>a[right])
        {
            t=a[loc];
            a[loc]=a[right];
            a[right]=t;
            loc=right;
        }
    if(flag!=1)
    {

      while(a[loc]>=a[left] && (loc!=left))

         left++;
         if(loc==right)
            flag=1;
         else if(a[left]>a[loc])
         {
            t=a[left];
            a[left]=a[loc];
            a[loc]=t;
            loc=left;
         }
    }
   }

        return loc;
}
void quicksort(int a[],int beg,int end)
{
    int loc;
    if(beg<end)
    {
    loc=partition(a,beg,end);
    quicksort(a,beg,loc-1);
    quicksort(a,loc+1,end);
    }
}

