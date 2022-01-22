#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "Settings.h"

using namespace std;
const int SHORTEST_WORD = 3;
const int LONGEST_WORD = 12;
const int MINIMUM_ATTEMPTS = 1;
const int MAXIMUM_ATTEMPTS = 10;

void MAIN_MENU() {
	cout << '\t' << "MAIN MENU" << '\n'
		<< "1. Start a new game" << '\n'
		<< "2. Settings" << '\n'
		<< "3. Exit" << '\n' << '\n';
}

int FindRandomIndex(const int first, const int last) {
	srand(time(0));
	return first + (rand() % last);				
}

bool Validation(char letter_array[1]) {
	if (letter_array[1] < 'a' || letter_array[1] > 'z')
	{
		cout << "Invalid imput. Put down another LETTER.";
		return 0;
	}
	return 1;
}

void NewGame(int &lenght, int &attempts) {
	const int ByDefault = 4;
	char word[ByDefault];
	fstream file;
	file.open("3letters.txt");
	const int WORDS_PER_FILE = 15;
	const int RandomWord = FindRandomIndex(1, WORDS_PER_FILE);
	for (size_t i = 0; i < RandomWord ; i++)
	{
		file >> word;
	}

	// Тurning a char (the word) into string
	string line = word;												
	string arr_word[LONGEST_WORD];
	int i = 0;
	stringstream ssin(line);
	while (ssin.good() && i < lenght) {
		ssin >> arr_word[i];
		++i;
	}
	
	//It is possible to turn the string into a stream by using the std::stringstream class 
	//(its constructor takes a string as parameter).Once it's built, you can use the >> operator 
	//on it (like on regular file based streams), which will extract, or tokenize word from it:
	const char dashes = '_';
	for (size_t dash = 0; dash < lenght; dash++)
	{
		cout << dashes;
	}

	string letter_attempt;
	cin >> letter_attempt;

	/*Turn string into array*/
	char letter_array[1];
	strcpy(letter_array, line.c_str());						//Makes mistake
	
	Validation(letter_array);
	while (Validation == 0)
	{
		cin >> letter_attempt;
		char letter_array[1];
		strcpy(letter_array, line.c_str());
		Validation(letter_array);
	}

	for (size_t i = 0; i < lenght ; i++) {
		if (arr_word[i] == letter_attempt )
		{
			cout << arr_word[i];
		}
		else
		{
			cout << dashes;

		}
	}
	/*
Извежда се думата като неотгатнатите букви се заместват с _. 
(например за думата cat първоначално се извежда _ _ _)
Потребителя въвежда буква.
При въвеждане на невалидна буква (символ не от латинската азбука) се извежда съобщение за грешка.
При въвеждане на валидна буква:
*/

}



int main() {
	int attempts = 3;							//By default
	int lenght = 3;								//By default
	
	MAIN_MENU();

	int choice;
	cin >> choice;
	while (choice != 3)
	{
		if (choice == 1)
		{
			NewGame(lenght, attempts);
		}
		else if (choice == 2)
		{
			Settings(&lenght, &attempts);
		}
		else
		{
			cout << "Error.";
		}
		MAIN_MENU();	
		cin >> choice;
	}
	return 0;
}