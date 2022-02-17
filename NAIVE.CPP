#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<dos.h>
void main()
{ clrscr();
 int i,m,n,c=0,s;
 int count=0;
 double diff1;
 time_t end1,beg1;
 char t[100], p[100];
/* cout<<"\n enter length of text";
 cin>>m;   */
 cout<<"\n enter the text";
 gets(t);
 /*cout<<"\n enetr length of pattern";
 cin>>n;*/
 cout<<"\n enter pattern";
 gets(p);
 m=strlen(t);
 n=strlen(p);
 cout<<"\n length of text="<<m;
 cout<<"\n length of pattern="<<n;
 beg1=clock();
for(s=0;s<(m-n);s++)
{ int a=0,i=s;
c=0;
delay(100);
  while((a<n)&&(i<m))
  {
  count++;
   if(p[a]==t[i])
   {
    a++;
    i++;
    c++;
   }
  else
  {
   break;
  }
  }
 if(c==n)
 break;
}
end1=clock();
diff1=(double)((end1-beg1)/CLOCKS_PER_SEC);
printf("\nTime taken:%lf",diff1);
printf("\nComparisions in naive:%d",count);
if(c==n)
{
 cout<<"\n pattern exist at position"<<s+1;
}
else
{
 cout<<"\n pattern doesnot exist in the text";
}
getch();
}



