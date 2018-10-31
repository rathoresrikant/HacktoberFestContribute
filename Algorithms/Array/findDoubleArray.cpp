#include<iostream>
using namespace std;

//This program reads an array and a number and returns the position of the number in the array.

int main ()
{
	
	const int MAX = 100;
	
	int util_v, i = 0;
	
	double v[MAX], x;
	
	bool encontrado = false;
	
	do
	{
		cout << "Enter the size of the array (between 1 and " << MAX << "): ";
		cin >> util_v;
	} while (util_v < 1 || util_v > MAX);
	
	
	for (int i = 0;  i < util_v; i++)
	{
		cout << "Enter the value nº " << i+1 << endl;
		cin >> v[i];
	}
	
	cout << "Enter the value \"x\" to find: ";
	cin >> x;
	
	while (!encontrado && i < util_v)
	{
		if (v[i] == x)	
			encontrado = true;
		else
			i++;
	}
	
	if (encontrado)
		cout << "X has been found in the position " << i + 1;
	else
		cout << "X hasn't been found";
}
