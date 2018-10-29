#include <list>
#include <iostream>

using namespace std;
template <typename T>
void swap (list<T> &x)
{
    T end= x.back();
    T front = x.front();
    x.pop_back();
    x.pop_front();
    x.push_back(front);
    x.push_front(end);
}

template <typename T>
void print (list<T> x)
{
    for(typename list<T>::iterator it=x.begin();it!=x.end();it++)
        cout<<*it<<" ";
}

int main()
{
    list <int> a;
    int x;
    cout<<"Insert 10 numbers"<<endl;
    for(int i=0;i<10;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    print(a);
    cout<<endl;
    swap(a);
    print(a);
    return 0;
}
