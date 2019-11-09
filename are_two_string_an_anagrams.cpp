#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
	string sentence1, sentence2;
	int letter1[26]={0}, letter2[26]={0};
	
	cin >> sentence1;
	cin >> sentence2;
	
	if (sentence1.length()!=sentence2.length())
	{
		cout << "FALSE" << endl;
		return 0;
	}
	else
	{
		for(int i=0;i<sentence1.length();i++)
		{
			sentence1[i]=tolower(sentence1[i]);
			sentence2[i]=tolower(sentence2[i]);
			letter1[sentence1[i]-'a']++;
			letter2[sentence2[i]-'a']++;
		}
		for(int k=0;k<26;k++)
		{
			if(letter1[k]!=letter2[k])
			{
				cout << "FALSE" << endl;
				return 0;
			}
		}
		cout << "TRUE" << endl;
		return 0;
	}
}
