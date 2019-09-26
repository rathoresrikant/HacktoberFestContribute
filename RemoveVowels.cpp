/*
	Programmer: Justin Taylor
	Date: 10/19/2018
	Purpose: To remove all vowels from a user input string
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string theString;

	const int numVowels = 5;
	char vowels[numVowels] = { 'a', 'e', 'i', 'o', 'u' };

	cout << "Input string: ";
	getline(cin, theString);

	for (int i = 0; i < theString.size(); i ++)
	{
		for (int j = 0; j < numVowels; j++)
		{
			if (theString[i] == vowels[j])
			{
				theString.erase(theString.begin() + i);
				i = -1;
				break;
			}
		}
	}

	cout << "The new string: ";
	cout << theString << endl;

	system("pause");
	return 0;
}