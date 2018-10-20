/*
	Programmer: Justin Taylor
	Date: 10/20/2018
	Purpose: Find the first non-repeating character in a string
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string theString;
	char theChar;

	cout << "Input string: ";
	cin >> theString;

	for (int i = theString.size() - 1; i >= 0; i--)
	{
		for (int j = theString.size() - 1; j >= 0; j--)
		{
			if (i != j && theString[i] == theString[j])
			{
				break;
			}

			else
			{
				theChar = theString[i];
			}
		}
	}

	cout << "The first non repeating character is: ";
	cout << theChar << endl;

	system("pause");
	return 0;
}