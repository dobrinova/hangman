/**
*
* Solution to course project # 14
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Monika Dobrinova
* @idnumber 8MI0600008
* @compiler VC
*
* <file with helper functions for the New Game option>
*
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include "Newgame.h"

using namespace std;
const int SHORTEST_WORD = 3;
const int LONGEST_WORD = 12;
const int MINIMUM_ATTEMPTS = 1;
const int MAXIMUM_ATTEMPTS = 10;

char* my_strcat(char* s1, const char* s2)
{
	char* start = s1;
	while (*start != '\0')
	{
		start++;
	}
	while (*s2 != '\0')
	{
		*start++ = *s2++;
	}
	*start = '\0';
	return s1;
}

int FindRandomIndex(const int first, const int last) {
	srand(time(0));
	return first + (rand() % last);
}

bool Validation(char letter_attempt) {
	if (letter_attempt < 'a' || letter_attempt > 'z')
	{
		cout << "Invalid imput. Put down another LETTER." << '\n' << '\n';
		return 0;
	}
	return 1;
}

void NewGame(int& lenght, int& attempts) {
	char lenghtStr[3] = {};
	switch (lenght) {
		case 10:
			lenghtStr[0] = '1';
			lenghtStr[1] = '0';
			break;
		case 11:
			lenghtStr[0] = '1';
			lenghtStr[1] = '1';
			break;
		case 12:
			lenghtStr[0] = '1';
			lenghtStr[1] = '2';
			break;
		default:
			lenghtStr[0] = char(lenght + 48);
			lenghtStr[1] = '\0';
	}
	
	const int ByDefault = 4;
	char word[ByDefault];
	fstream file;
	file.open(my_strcat(lenghtStr, "letters.txt"));
	const int WORDS_PER_FILE = 15;
	const int RandomWord = FindRandomIndex(1, WORDS_PER_FILE);
	for (size_t i = 0; i < RandomWord; i++)
	{
		file >> word;
	}

	string line = word;			
	istringstream iss(line);
	vector<string> arr_word;
	for (string s; iss >> s;) {
		arr_word.push_back(s);
	}
	int n = arr_word.size();
	
	const char dashes = '_';
	char letter_attempt[MAXIMUM_ATTEMPTS];
	char guesses_in_progress[LONGEST_WORD];
	for (int i = 0; i < lenght; i++)
	{
		guesses_in_progress[i] = dashes;
		cout << guesses_in_progress[i] << " ";
	}

	while (attempts >= 0)
	{
		cout << '\n' << '\n' << "You have " << attempts << " more attempts." << "\n";
		cout << '\n' << "Imput you answer: ";
		char  letter_attempt;
		cin >> letter_attempt;
		
		Validation(letter_attempt);
		while (Validation == 0)
		{
			cin >> letter_attempt;
			Validation(letter_attempt);
		}
		
		int counter = 0, k = 0, pointer = 0;
		for (int j = 0; j < lenght; j++) {
			if (arr_word[k][j] == letter_attempt)
			{
				guesses_in_progress[j] = letter_attempt;
				pointer++;
			}
			cout << guesses_in_progress[j] << " ";
		}
		if (pointer == 0)
		{
			attempts--;
		}

		for (int t = 0; t < lenght; t++)
		{
			if (guesses_in_progress[t] != dashes)
			{
				counter ++;
				if (counter == lenght)
				{
					cout << '\n' << "You successfully guessed the word " << word << "!" << '\n' << '\n';
					main();
				}	
			}
		}
		if (attempts == 0)
		{
			cout << '\n' << "You failed!" << '\n';
			main();
		}	
	}		
}