#include<iostream>
class A
{
    int a;
    int b;

public:
    A(int a_,int b_):a(a_),b(b_){}

    int  sum()
    {

        return a+b;
    }
    float average()
    {

        float x=(float(a) +b)/2;
        return x;

    }


};

class B
{
    int x;
    int y;

public:

    B(int x_,int y_):x(x_),y(y_){}

    int mult()
    {
        return x*y;
    }
    

};
class C :public A, public B
{

public:
    C(int a, int b):u(a),v(b),A(a,b),B(a,b){}
    void show()
    {
        std::cout<<"\nsum : "<<sum();
        std::cout<<"\n Avg : "<<average();
        std::cout<<"\nMult : "<<mult();
    }
    

private:
    int u,v;
    
};

int main()
{
    C c(10,20);
    c.show();


}


