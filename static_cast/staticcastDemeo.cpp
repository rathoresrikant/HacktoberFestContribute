#include<iostream>

enum class Ec
{
	A = 1,
	B = 2,
	C = 3
};

int main()
{
	int a = static_cast<int>(Ec::A);
	Ec b = static_cast<Ec>(1);
	if(b == Ec::A)
		std::cout<<"hello";
	std::cout<<a;

 return 0;
}
