#include<iostream>
using namespace std;
void concatenate(char a[])
{
    char s[100];
    int i=0,k=0;
    while(a[i]!='\0')
    {

        s[k++]=a[i];i++;
    }
    s[k]='\0';
    for(i=0;a[i]!='\0';i++);
    for(k=0;s[k]!='\0';k++)
    {

        a[i]=s[k];i++;
    }
    a[i]='\0';


}
int length(char s[])
{

    int i=0,c=0;
    while(s[i]!='\0')
    {
        i++;c++;
    }
    return c;
}
bool isrotation(char s[],char a[])
{
    int c1=length(s),c2=length(a);
         int i,j,k;
        for(i=0;s[i]!='\0';i++)
        { k=0;j=i;
            if(s[j]==a[k])
            {
                for(k=1;a[k]!='\0';k++)
                {j=j+1;
                    if(s[j]==a[k])
                       {
                          continue;
                       }
                    else
                        break;
                }
                if(k==c2)
                    return true;

            }

        }

        return false;
}
int main()
{ /* This is a solution for checking whether the given string is a rotation of another string,
     where rotation means left shifting or right shifting of some of the characters.
     So first we concatenate the first string with itself and then try to find whether the second string is substring of the first string,
     if it is a substring then they are rotation of each other and if not then they are not rotation of each other.
     */

    char s1[100],s2[100];
    cout<<"Enter the strings:";
    cin.getline(s1,100);
    cin.getline(s2,100);
    cout<<"First string: "<<s1<<endl;
    cout<<"Second string: "<<s2<<endl;
    concatenate(s1);
    int l;
    l=isrotation(s1,s2);
    if(l==1)
        cout<<"The given strings are rotation of each other"<<endl;
    else
        cout<<"The given strings are not rotation of each other"<<endl;
}
