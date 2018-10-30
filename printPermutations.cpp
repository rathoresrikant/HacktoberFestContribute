#include <iostream>
#include <string>

using namespace std;

void swap(char *a, char *b)
{
    char c;
    c=*a;
    *a=*b;
    *b=c;
}

void permute(string a, int l, int r)
{
   if (l==r)
     cout <<a<<endl;
   else
   {
       for (int i=l;i<=r;i++)
       {
          swap((a[l]), (a[i]));
          permute(a, l+1, r);
          swap((a[l]), (a[i]));
       }
   }
}

int main()
{
    string str;
    cin >> str;
    permute(str,0,str.size()-1);
    return 0;
}
