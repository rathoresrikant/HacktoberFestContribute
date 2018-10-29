#include<iostream>
#include<string>

template <class temp>
temp addValue(temp a, temp b)
{
	return (a+b);
}

int main()
{
	std::string 	x="abcd",y="efgh",z;
	z=addValue(x,y);
	std::cout<<z<<std::endl;
	return 0;
}
