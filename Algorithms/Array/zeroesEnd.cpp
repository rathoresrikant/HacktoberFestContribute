#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    cout<<"insert numbers (-999 close number)"<<endl;
    int x;
    cin>>x;
    while(x!= -999)
    {
        v.push_back(x);
        cin>>x;
    }

    vector <int> zeroes;
    vector <int> numbers;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==0)
            zeroes.push_back(v[i]);
        else
            numbers.push_back(v[i]);
    }

    v.clear();
    for(int i=0;i<numbers.size();i++)
    {
        v.push_back(numbers[i]);
    }

    for(int i=0;i<zeroes.size();i++)
    {
        v.push_back(zeroes[i]);
    }    
    cout<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }

    return 0;
}