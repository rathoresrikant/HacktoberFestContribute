#include<iostream>
#include<conio.h>

using namespace std;

void fibonacci(int n)
{
  cout<<"\n\n";
  long double first=0;
  long double second=1;
  cout<<first<<"\t"<<second;                    //to generate series
  /*if(n==1)
  	cout<<"\n\nTerm "<<n<<" of the Fibonacci Sequence is :\t"<<first;         //to generate nth term
  if(n==2)	
	cout<<"\n\nTerm "<<n<<" of the Fibonacci Sequence is :\t"<<second;
  */
  if(n>2)
  {  
	long double third;
	for(int i=3;i<=n;i++)
    {
      third=first+second;
      cout<<"\t"<<third;                    //to generate series
      first=second;
      second=third;
    }
    //cout<<"\n\nTerm "<<n<<" of the Fibonacci Sequence is :\t"<<third;         //to generate nth term
  }
}
 
int main()
{
  int x;
  cout<<"\n\nThis is a program to print out the Fibonacci Sequence";
  cout<<"\n\nChoose the number of terms upto which the fibonacci sequence is to be generated :\t";  //to generate series
  //cout<<"\n\nWhich term of the fibonacci sequence is to be generated :\t";        //to generate nth term
  cin>>x;
  fibonacci(x);
  getch();
  return 0;
}
