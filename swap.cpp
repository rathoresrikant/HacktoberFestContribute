#include <iostream.h>
using namespace std;

int main()
{
	int X, Y;
	cout<<" PLEASE ENTER TWO NUMBERS : ";
	cin>>X>>Y;
	X = X + Y;
	Y = X - Y;
	X = X - Y;
	cout<<"Now the first number is "<<X<<" and second number is "<<Y<<" .\n";
}
