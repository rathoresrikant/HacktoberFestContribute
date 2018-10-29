#include <iostream>

using namespace std;

int main()
{
    unsigned long long int a;
    cin >>a;
    bool b[128];
    for(int i=0;i<128;i++)
        b[i]=false;
    int compt=0;
    while(a!=0)
    {
        if((a&1)==1)
        {
            b[compt]=true;
        }
        a=a>>1;
        compt++;
    }

    //if you dont want format
    for(int i=0;i<compt;i++)
    {
        if(b[compt-i-1])
            cout<<1;
        else
            cout<<0;
    }
    cout <<endl;

    //with format
    int format;
    cin >>format;
    for(int i=0;i<format;i++)
    {
        if(b[format-i-1])
            cout<<1;
        else
            cout<<0;
    }
    return 0;
}
