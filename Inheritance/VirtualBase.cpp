#include <cstdio>
#include <string>
using std::string;

struct A{
    string s;
    A() {}
    A(string t): s(t) {}
};

struct B: virtual public A{
    B(): A("B"){}
};

struct C: virtual public A {};

struct D: public B, public C {};

struct E: public C, public B {};

struct F: public B {};

int main(){
    D d;
    printf("\"%s\"\n",d.s.c_str());
    E e;
    printf("\"%s\"\n",e.s.c_str());
    F f;
    printf("\"%s\"\n",f.s.c_str());
    B b;
    printf("\"%s\"\n",b.s.c_str());
}
