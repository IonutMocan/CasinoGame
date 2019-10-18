// ---------------- CASINO GAME

#include <iostream>
#include <Windows.h> // Header for function Sleep(miliseconds); 
#include <string> // Header for function getline(); 
#include <cstdlib> // Header for function random();
#include <ctime> // Header for function time();
using namespace std;


// -------------- Draw specific line function
void DrawLine(int _size, string _template) {
	cout << "\t";
	for (int i = 0; i < _size; ++i)
		cout << _template;
	cout << endl;
}


void main() {
	// ------------- Declaration area
	string PlayerName;
	int MoneyAmount;
	int Bet;
	int Guess;
	int Dice;
	string PlayerChoice;
	string LennyFacesList[11] = { "0","(\"O\")","(*o*)","(*u*)","(*.*)", "(^o^)", "(^u^)", "(^_^)", "(*_*)", "(-_-)", "(-n-)" };

	// ------------- Seed the random generator
	srand(time(0));

	// ------------- Welcome section
	cout << "\n\n";
	cout << "\t\t\t";
	DrawLine(55, "-");
	cout << "\n\t\t\t\t\t\tWELCOME TO THE CASINO!\n" << endl;
	cout << "\t\t\t";
	DrawLine(55, "-");
	cout << "\n\n";


	// ------------- Definition area
	cout << "\n\t\tGame registration, enter your name: ";
	getline(cin, PlayerName); // ------------- Getting the player name
	cout << "\n\t\tI'm glad to meet you, " << PlayerName << "!";
	cout << "\n\n\t";
	DrawLine(90, "-");
	// ------------- Setting the right MoneyAmount of money
	do {
		cout << "\n\n\t\tTell us the amount of money are you gonna play with ( Minimum amount accepted - $100 ): ";
		cin >> MoneyAmount;
		if (MoneyAmount < 100) {
			cout << "\n\t\tSorry.. The minimum amount of money required in order to play is $100!";
		}
	} while (MoneyAmount < 100);


	// ------------- Getting ready to move on
	cout << "\n\n\t";
	DrawLine(90, "-");
	cout << "\n\t\t\Now you are ready to play!$! (*u*)";

	// ------------- Countdown
	for (int i = 3; i > 0; --i) {
		cout << "\n\t\t" << i << "..";
		Sleep(1000);
	}

	// Game "window" title
	int a = 2;
	do {
		system("cls");
		cout << "\n\n";
		cout << "\t\t\t";
		DrawLine(55, "-");
		cout << "\n\t\t\t\t\t    Guess THE NUMBER, CASINO GAME!\n" << endl;
		cout << "\t\t\t";
		DrawLine(55, "-");
		cout << "\n\n";

		// The set of rules for this game
		cout << "\n\t\t\t\tGAME RULES:" << endl;
		cout << "\t\t1. Choose any number between 1 to 10\n";
		cout << "\t\t2. If you win you will get 10 times of money you bet\n";
		cout << "\t\t3. If you bet on wrong number you will lose your betting MoneyAmount\n\n";
		DrawLine(105, "-");

		// The start amount of money
		cout << "\n\t\tYOUR CURRENT BALANCE: $" << MoneyAmount;

		// ------------- Setting the right bet
		do {
			
			cout << "\n\n\t\tTell us the bet that you are gonna use ( the bet needs to be between $10 - $100 ): ";
			cin >> Bet;
			if (Bet < (MoneyAmount+1))
			{
			if (Bet > 100) {
				cout << "\n\t\tSorry.. The maximum bet available to play with is $100!";
			}
			if (Bet < 10) {
				cout << "\n\t\tSorry.. The minimum bet available to play with is $10!";
			}
			}
			else
			{
				cout << "\n\t\tSorry.. You don't have so much money.. Try a smaller bet!";
			}
			
		} while (Bet < 10 || Bet > 100 || MoneyAmount<Bet);

		// ------------ Getting player Guess
		do
		{
			cout << "\n\t\tGuess your number to bet between 1 to 10: ";
			cin >> Guess;
			if (Guess <= 0 || Guess > 10)
				cout << "\n\t\tPlease check your number it should be between 1 to 10..\n";
		} while (Guess <= 0 || Guess > 10);

		Dice = rand() % 10 + 1; // Generate a random number betwee 1 - 10

		cout << "\n\t\tExtracting the random number..";

		// ------------- Random Extraction countdown
		for (int i = 10; i > 0; --i) {
			cout << "\n\t\t" << i << ".." << "  " << LennyFacesList[i];
			Sleep(1000);
		}
		cout << "\n";

		// -------------- Check the guess
		if (Dice == Guess)
		{
			cout << "\n\t\tYOU JUST WON $" << Bet * 10 << " CASH !$!$!$!$!$!$!";
			MoneyAmount = MoneyAmount + Bet * 10;
		}
		else
		{
			cout << "\n\t\tYou got some bad luck this time, but the next it's gonna be much better for sure! " << "\n";
			MoneyAmount = MoneyAmount - Bet;
		}

		// Show the extracted number
		cout << "\n\t\tThe extracted number this time was: " << Dice << "\n";
		cout << "\n\t\t" << PlayerName << ", you have $" << MoneyAmount << " now!\n";

		// Clouse condition if payer got no more money
		if (MoneyAmount == 0)
		{
			cout << "\n\t\tOh no.. You have no more money.. Such a bad luck.. ";
			break;
		}

		// Check if player wants to play again or quit
		do {
			cout << "\n\t\tIf you want to play again just type \"YES\" otherwise type \"EXIT\" to quit: ";
			cin >> PlayerChoice;
			if (PlayerChoice != "YES" && PlayerChoice != "EXIT") {
				cout << "Wrong command!";
			}
		} while (PlayerChoice != "YES" && PlayerChoice != "EXIT");

		// Exit condition
		if (PlayerChoice == "EXIT")
			system("exit");
	} while (PlayerChoice == "YES");

}