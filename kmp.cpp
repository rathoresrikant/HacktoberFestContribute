#include<bits/stdc++.h>
using namespace std;
/*AUTHOR PANKAJ JOSHI
ALGO:KMP STRING MATCHER
MNNIT*/

int * pa(char *s)
{
	
	int l=strlen(s);
	int *x=new int[l];
	x[0]=0;
	int j=0;
	int i;
	for(i=j+1;i<l;i++)
	{
		if(s[i]!=s[j])
		{
			if(j==0)
			{
				x[i]=0;
			}
			else
			{
			while(1)
			{ j=x[--j];
				if(j==0)
				{
					x[i]=0;
					break;
				}
				if(s[j]==s[i])
				{
					x[i]=j+1;
					j++;
					break;
				}
			}}
		}
		else
		{
			x[i]=j+1;
			j++;
		}

	}
   return x;

}


void kmp(char *s,char *p)
{
	int *pi=pa(p);

	int l=strlen(s);
	int ls=strlen(p);
	//for(int i=0;i<ls;i++)cout<<pi[i]<<" ";
	int j=0;
	for(int i=0;i<l;i++)
	{

		if(s[i]==p[j])
		{
			//cout<<j<<endl;
			j++;

		}
		else
		{
			while(1)
			{
			 j=pi[--j];
			 if(s[i]==p[j])
			 {
			 	//cout<<j<<endl;
			 	j++;
			 	break;

			 }
			 else {
			 	if(j==0)
			 	{
			 		break;
			 	}
			 }

             }

		}
	}
	if((j)==ls){
		cout<<"pattern found\n";
	}
	else{
		cout<<"pattern not found\n";
	}

}



int main()
{
	char s[]="abxabcabcaby";
	char p[]="abcaby";
	kmp(s,p);
}
