#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
void sort(char arr[],int n)
{
	 int i,key,j; 
  	 for (i=1;i<n;i++) 
  	 { 
       key=arr[i]; 
       j=i-1; 
  	   while(j>=0&&arr[j]>key) 
       { 
           arr[j+1]=arr[j]; 
           j=j-1; 
       } 
       arr[j+1]=key; 
   	} 
}


int main()
{
	int flag=0;
	char s1[20],s2[20];
	cout<<"Enter first string :\t";
	gets(s1);
	cout<<"Enter second string :\t";
	gets(s2);
	int len1=strlen(s1);
	int len2=strlen(s2);
	if(len1!=len2)
		cout<<"\nThe strings are not of the same size.";
	else
	{
		sort(s1,len1);
		sort(s2,len2);
		for(int i=0;i<len1;i++)
		{
			if(s1[i]!=s2[i])
				flag=1;
		}
		if(flag==1)
		{
			cout<<"\nThe strings are not anagrams."; 
		}
		if(flag==0)
		{
			cout<<"\nThe strings are anagram.";
		}
	}
	getch();
	return 0;
}
