#include<iostream>
using namespace std;
class parent
{
public:
int a;
void disp()
{
cout<<"parent\na="<<a;
}
};
class child : public parent
{
public:
int b;
void display()
{
cout<<"child\nb="<<b;
disp();
}
};
int main()
{
child c;
c.a=9;
c.b=89;
c.display();
return 0;
}
