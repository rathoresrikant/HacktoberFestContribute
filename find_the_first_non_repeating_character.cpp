#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	string sentence1, sentence2;
	int size1, size2;
	
	cin >> sentence1;
	cin >> sentence2;
	size1=sentence1.length();
	size2=sentence2.length();
	
	
	for (int i=0;i<min(size1, size2);i++)
	{
		if(sentence1[i]!=sentence2[i])
		{
			cout << "Letter " << i+1 << " is not repeat" << endl;
			return 0;
		}
	}
	if(size1==size2)
	{
		cout << "Both sentences are the same" << endl;
	}
	else if(size1>size2)
	{
		cout << "Second sentence are the part of first sentence" << endl;	
	}
	else
	{
		cout << "First sentence are the part of second sentence" << endl;
	}
	return 0;
}
