#include<bits/stdc++.h>
using namespace std;
int main()
{
  char operator;
    double n1,n2;

    printf("Enter an operator (+, -, *,/,%): ");
    

    printf("Enter two numbers: ");
    cin>>n1>>n2;

  switch(operator)
  {
   case '+':
        cout<<n1<<"+"<<n2<<"="<<n1+n2;
        break;

    case '-':
          cout<<n1<<"-"<<n2<<"="<<n1-n2;
        break;

    case '*':
        cout<<n1<<"*"<<n2<<"="<<n1*n2;
        break;

    case '/':
          cout<<n1<<"/"<<n2<<"="<<n1/n2;
        break;
    case '%':
      cout<<n1<<"%"<<n2<<"="<<n1%n2;
      break;
    default:
      cout<<"Please enter one of the operators +,-,*,/,%";
  }
  printf("\n");
  return 0;
   }


