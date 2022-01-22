#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int SHORTEST_WORD = 3;
const int LONGEST_WORD = 10;
const int MINIMUM_ATTEMPTS = 1;
const int MAXIMUM_ATTEMPTS = 10;

void MAIN_MENU() {
	cout << '\t' << "MAIN MENU" << '\n'
		<< "1. Start a new game" << '\n'
		<< "2. Settings" << '\n'
		<< "3. Exit" << '\n' << '\n';
}

void SETTINGS() {
	cout << '\t' << "SETTINGS" << '\n'
		<< "1. Change the lenght of the word. (the shortest word possible consists of 3 letters and the longest - of 10)" << '\n'
		<< "2. Change the amount of attempts. (the minimum attempts possible is 1 and the maximum is 10)" << '\n'
		<< "3. Return to main menu." << '\n' << '\n';
}

int RandomIndex(const int first, const int last) {
	srand(time(0));
	return first + (rand() % last);				
}
/*Стартиране на нова игра
Програмата избира случайна дума от речника.
Извежда се думата като неотгатнатите букви се заместват с _. (например за думата cat първоначално се извежда _ _ _)
Потребителя въвежда буква.
При въвеждане на невалидна буква (символ не от латинската азбука) се извежда съобщение за грешка.
При въвеждане на валидна буква:
*/
void NewGame(int lenght, int attempts) {
	//input a word
	const int ByDefault = 4;
	char word[ByDefault];
	fstream file;
	file.open("3letters.txt");
	
	const int RandomWord = RandomIndex(1, 4);
	for (size_t i = 0; i < RandomWord ; i++)
	{
		file >> word;
	}
	cout << word;
}

void Settings(int* lenght, int* attempts) {
	SETTINGS();
	int SettChoice;
	cin >> SettChoice;
	while (SettChoice != 3)
	{
		if (SettChoice == 1)
		{
			cout << "Imput the wanted lenght:" ;
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
			cout << "Imput the wanted attempts:" ;
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