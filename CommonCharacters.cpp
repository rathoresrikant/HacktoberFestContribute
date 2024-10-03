#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	string theString1;
	string theString2;
	
	vector<char> commonChars;
	vector<char>::iterator iter;

	bool repeating = false;

	cout << "Input String1: ";
	cin >> theString1;

	cout << "Input String2: ";
	cin >> theString2;

	for (int i = 0; i < theString1.size(); i++)
	{
		for (int j = 0; j < theString2.size(); j++)
		{
			for (iter = commonChars.begin(); iter != commonChars.end(); iter++)
			{
				if (*iter == theString1[i])
				{
					repeating = true;
					break;
				}
			}

			if (theString1[i] == theString2[j] && !repeating)
			{
				commonChars.push_back(theString1[i]);
				break;
			}
		}

		repeating = false;
	}

	sort(commonChars.begin(), commonChars.end());

	cout << "The common characters in this string are: " << endl;

	for (iter = commonChars.begin(); iter != commonChars.end(); iter++)
	{
		cout << *iter << endl;
	}

	system("pause");
	return 0;
}