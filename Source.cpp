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
* <MAIN FUNCTION>
*
*/
#include <iostream>
#include "Settings.h"
#include "Newgame.h"

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

int main() {
	int attempts = 6;							//By default
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