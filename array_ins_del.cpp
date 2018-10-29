//Program to insert and delete an element in an array

#include<iostream.h>
#include<conio.h>

void main()
 {
  clrscr();
  int a[20],n,ele,pos=-1,i,ch;

  cout<<"Enter the number of entries in the array:\n";
  cin>>n;
  cout<<"Enter the elements of the array in ascending order:\n";
  for (i=0;i<n;i++)
   cin>>a[i];

  clrscr();
  getch();
  cout<<"What do you wish to do....?\n";
  cout<<" 1. Insert an element\n";
  cout<<" 2. Delete an element\n";
  cout<<" 3. Exit\n";
  cin>>ch;

  switch (ch)
   {
    case 1:cout<<"Enter the element to be inserted:\t";
	   cin>>ele;
	   if (ele<a[0])
	    pos=0;
	   else if (ele>a[n-1])
	    pos=n;
	   else
	    {
	     for (i=0;i<n;i++)
	      {
	       if ( ele>a[i] && ele<a[i+1] )
		{
		 pos=i+1;
		 break;
		}
	      }
	    }
	   for (i=n;i>pos;i--)
	    a[i]=a[i-1];
	   a[pos]=ele;
	   n++;
	   break;

    case 2:cout<<"Enter the element to be deleted:\t";
	   cin>>ele;
	   for (i=0;i<n;i++)
	    {
	     if (ele==a[i])
	      {
	       pos=i;
	       break;
	      }
	    }
	   if (pos>-1)
	    {
	     for (i=pos;i<n-1;i++)
	      a[i]=a[i+1];
	     n--;
	    }
	   else
	    cout<<"Element not found....!";
	   break;
   }

  getch();
  cout<<"\nFinal array:\n";
  for (i=0;i<n;i++)
   cout<<a[i]<<" ";

  getch();
 }
