#include <iostream>

using namespace std;

int main()
{
    int n=0;
    cout<<"Insert dimension"<<endl;
    cin>>n;
    cout<<"Insert elements"<<endl;
    int * array = new int [n];
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    int x, cont=0;
    cout<<"Insert number which you want the number of occurrences"<<endl;
    cin>>x;
    for(int i=0;i<n;i++)
    {
        if(array[i]==x)
            cont++;
    }
    cout<<"Occurrences: "<<cont<<endl;
    delete [] array;
    return 0;
}