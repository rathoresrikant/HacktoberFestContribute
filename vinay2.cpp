#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char str[20];
	int len, i, j;
	cout<<"Enter a string : ";
	cin.getline(str,20);
	len = strlen(str);
	for(i=0; i<len; i++)
	{
		if(str[i]=='a' || str[i]=='e' || str[i]=='i' ||
		str[i]=='o' || str[i]=='u' || str[i]=='A' ||
		str[i]=='E' || str[i]=='I' || str[i]=='O' ||
		str[i]=='U')
		{
			for(j=i; j<len; j++)
			{
				str[j]=str[j+1];
			}
		len--;
		}
	}
	cout<<"After deleting the vowels, the string will be : "<<str;
    return 0;
}
