#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;
/*10/25/2020 
A simple hangman game where it reads from a file called
"words.txt". The file contains a list of words each on their own line.
A wrong answer will decrease the number of lives.
The right answer will display the location of the letter which was correct
*/

/*
checks if the user has won or lost
*/
bool winCondition(bool run, string blank, int lives) {

	if(lives > 0){
		if (blank.find('_') == string::npos) {
			cout << "Congratulations you won!" << endl;
			return false;
		}
		else
			return true;
	}

	else if (lives < 1) {
		cout << "0 lives left! YOU LOST!" << endl;
		return false;
	}
}

/*
will reveal the locations of the correct answer
if the wrong answer is entered
the number of lives is decreased*/
int displayAnswer(string guess, string word, string& blank){
	
	int firstFind = word.find(guess);
	static int Lives = 5;
	if (word.find(guess) != string::npos) {
		int i = firstFind;
		blank[i * 2] = word[i];
		for (i; i < word.length(); i++) {
			if (word.find(guess, i) != string::npos) {
				i = word.find(guess, i);
				blank[i * 2] = word[i];
			}
		}
		cout << blank << endl;
		return Lives;
	}

	else {
		cout << "You have " << --Lives << " lives left" << endl;
		return Lives;
	}

}

//counts the number of lines/words
int lineCount(ifstream& inFile) {

	
	string lineRead;
	int lineCount = 0;

	while (!inFile.eof()) {
		getline(inFile, lineRead);
		lineCount++;
	}
	return lineCount;
}

/*reads the file and saves the
strings into the heap*/
void createDatabase(string*& arrStr, int& size){

	ifstream inFile;
	inFile.open("words.txt");
	size = lineCount(inFile);

	inFile.clear();
	inFile.seekg(0, inFile.beg);

	arrStr = new string[size];

	for (int i = 0; i < size; i++) {
		getline(inFile, arrStr[i]);
	}

	inFile.close();

}

/*
This function will select a word from the array of strings
in the heap. will. Array will be deleted after word has 
been selected*/
string wordSelector(){

	int size;
	int wordRandom;
	int difficulty;
	string* strPtr;
	string wordSelected;
	createDatabase(strPtr, size);

	cout << "Please select a difficulty from 1-3 (1-easiest, 3-hardest): " << endl;
	cin >> difficulty;

	srand(time(0));	

	if (difficulty == 1) {//easy: will only give words that have a length of 4 or less
		wordRandom = rand() % size;
		wordSelected = strPtr[wordRandom];
		while (wordSelected.length() > 4) {
			wordRandom = rand() % size;
			wordSelected = strPtr[wordRandom];
			}
	}

	else if (difficulty == 2) {//medium: will only give words that have a length between 5-9
		wordRandom = rand() % size;
		wordSelected = strPtr[wordRandom];
		while (wordSelected.length() < 5 || wordSelected.length() > 9) {
			wordRandom = rand() % size;
			wordSelected = strPtr[wordRandom];
		}
	}

	else if (difficulty == 3) {//hard: will only give words that have a length of 10 or greater
		wordRandom = rand() % size;
		wordSelected = strPtr[wordRandom];
		while (wordSelected.length() < 10) {
			wordRandom = rand() % size;
			wordSelected = strPtr[wordRandom];
		}
	}

	return wordSelected;
	delete[] strPtr;
}

//main func
int main() {

	string wordToGuess = wordSelector();
	string userGuess;
	string blank;

	for (int i = 0; i < wordToGuess.length(); i++) {
		blank.append("_ ");
	}

	bool run = true;
	int liveCount;

	cout << "The length of the word to guess is " << wordToGuess.length() << endl;
	cout << blank << endl;

	while (run) {
		cout << "Please enter a letter: ";
		cin >> userGuess;

		liveCount = displayAnswer(userGuess, wordToGuess, blank);
		run = winCondition(run, blank, liveCount);
	}
}