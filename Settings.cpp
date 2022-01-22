#include <iostream>
#include "Settings.h"

using namespace std;

const int SHORTEST_WORD = 3;
const int LONGEST_WORD = 12;
const int MINIMUM_ATTEMPTS = 1;
const int MAXIMUM_ATTEMPTS = 10;

void SETTINGS() {
	cout << '\t' << "SETTINGS" << '\n'
		<< "1. Change the lenght of the word. (the shortest word possible consists of 3 letters and the longest - of 10)" << '\n'
		<< "2. Change the amount of attempts. (the minimum attempts possible is 1 and the maximum is 10)" << '\n'
		<< "3. Return to main menu." << '\n' << '\n';
}

void Settings(int* lenght, int* attempts) {
	SETTINGS();
	int SettChoice;
	cin >> SettChoice;
	while (SettChoice != 3)
	{
		if (SettChoice == 1)
		{
			cout << "Imput the wanted lenght:";
			int NewLenght;
			cin >> NewLenght;
			while (NewLenght < SHORTEST_WORD || NewLenght > LONGEST_WORD)
			{
				cout << "Imput valid lenght:";
				cin >> NewLenght;
			}
			*lenght = NewLenght;
		}
		else if (SettChoice == 2)
		{
			cout << "Imput the wanted attempts:";
			int NewAttempts;
			cin >> NewAttempts;
			while (NewAttempts < MINIMUM_ATTEMPTS || NewAttempts > MAXIMUM_ATTEMPTS)
			{
				cout << "Imput valid attempts:";
				cin >> NewAttempts;
			}
			*attempts = NewAttempts;
		}
		else
		{
			cout << "Error.";
		}
		SETTINGS();
		cin >> SettChoice;
	}
}