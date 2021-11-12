#include <iostream.h>
using namespace std;
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}
int main()
{
	int a, b;
	cout<<"Enter two numbers : ";
	cin>>a>>b;
	swap(&a,&b);
	cout<<"Now the first number is "<<a<<" and second number is "<<b<<endl;
	return 0;
}
