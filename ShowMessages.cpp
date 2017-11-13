#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include <iomanip>
using namespace std;

//Japanese ship names
const string sJapaneseCarrier = "Ryujo Carrier";
const string sJapaneseBattleship = "Nagato Battleship";
const string sJapaneseCruiser = "Furutaka Cruiser";
const string sJapaneseSubmarine = "Ro-51 Submarine";
const string sJapaneseDestroyer = "Kamikaze Destroyer";

//American ships names
const string sAmericanCarrier = "USS Princeton Carrier";
const string sAmericanBattleship = "USS Arizona Battleship";
const string sAmericanCruiser = "USS Minneapolis Cruiser";
const string sAmericanSubmarine = "USS Hawkbill Submarine";
const string sAmericanDestroyer = "USS Frankford Destroyer";

void cleanScreen()
{
	for (int iCounter = 0; iCounter < 50; ++iCounter)
	{
		cout << endl;
	}
}

void pressToContinue()
{
	cout << "Press Enter to continue...";
    cin.ignore();
}

void showComputerTurn()
{
	cleanScreen();

	int iIndenting = 75;

	cout << "\x1b[31m";
	cout << setw(iIndenting) << " ******   **   **   ******   **        **  **  **   ** " << endl;
	cout << setw(iIndenting) << " **       ***  **   **       ***      ***   ****    ** " << endl;
	cout << setw(iIndenting) << " ******   **** **   ******   ****    ****    **     ** " << endl;
	cout << setw(iIndenting) << " **       ** ****   **       ** **  ** **    **     ** " << endl;
	cout << setw(iIndenting) << " **       **  ***   **       **  ****  **    **        " << endl;
	cout << setw(iIndenting) << " ******   **   **   ******   **   **   **    **     ** " << endl;
	cout << "\x1b[37m";

	cout << endl << endl;

	cout << setw(iIndenting + 2) << "It's the enemy's turn to strike! Brace yourself for impact!" << endl;	

	for (int iCounter = 0; iCounter < 7; ++iCounter)
	{
		cout << endl;
	}

	usleep(2000000);
}

void showHit(bool bIsPlayer)
{
	cleanScreen();

	int iIndenting = 60;

	cout << setw(iIndenting) << "**   **   **   ******   ** " << endl;
	cout << setw(iIndenting) << "**   **   **   ******   ** " << endl;
	cout << setw(iIndenting) << "*******   **     **     ** " << endl;
	cout << setw(iIndenting) << "*******   **     **     ** " << endl;
	cout << setw(iIndenting) << "**   **   **     **        " << endl;
	cout << setw(iIndenting) << "**   **   **     **     ** " << endl;

	cout << endl << endl;

	if (bIsPlayer)
	{
		cout << setw(iIndenting + 7) << "Admiral, we've hit one of the enemy ships!" << endl;
	}
	else
	{
		cout << setw(iIndenting + 9) << "Admiral, The enemy has hit one of your ships!" << endl;
	}

	for (int iCounter = 0; iCounter < 7; ++iCounter)
	{
		cout << endl;
	}

	usleep(3000000);

}

void showSank(bool bIsPlayer, string sShip)
{
	cleanScreen();

	int iIndenting = 75;

	cout << "\x1b[31m";
	cout << setw(iIndenting) << "  *****        **        **   **    **  **   ** " << endl;
	cout << setw(iIndenting) << " **           ****       ***  **    ** **    ** " << endl;
	cout << setw(iIndenting) << " ****        **  **      **** **    ***      ** " << endl;
	cout << setw(iIndenting) << "   ****     ********     ** ****    ****     ** " << endl;
	cout << setw(iIndenting) << "     **    **      **    **  ***    ** **       " << endl;
	cout << setw(iIndenting) << "  *****   **        **   **   **    **  **   ** " << endl;
	cout << "\x1b[37m";

	cout << endl << endl;

	if (bIsPlayer)
	{
		cout << setw(iIndenting - 21) << "You have sank the enemy " << "\x1b[36m" << sShip << "\x1b[37m" << "!";
	}
	else
	{
		cout << setw(iIndenting - 25) << "The enemy has sank our " << "\x1b[36m" << sShip << "\x1b[37m" << "! A black day!";
	}

	for (int iCounter = 0; iCounter < 7; ++iCounter)
	{
		cout << endl;
	}

	pressToContinue();
}

void showMiss(bool bIsPlayer)
{
	cleanScreen();

	int iIndenting = 65	;
	
	cout << setw(iIndenting) << "**        **   **    *****    *****   ** " << endl;
	cout << setw(iIndenting) << "***      ***   **   **       **       ** " << endl;
	cout << setw(iIndenting) << "****    ****   **   ****     ****     ** " << endl;
	cout << setw(iIndenting) << "** **  ** **   **     ****     ****   ** " << endl;
	cout << setw(iIndenting) << "**  ****  **   **       **       **      " << endl;
	cout << setw(iIndenting) << "**   **   **   **    *****    *****   ** " << endl;

	cout << endl << endl;

	if (bIsPlayer)
	{
		cout << setw(iIndenting + 0) << "Admiral, we've miss the shot, a tragedy!" << endl;
	}
	else
	{
		cout << setw(iIndenting + 19) << "Admiral, The enemy has missed the shot, but our luck might run out soon!" << endl;
	}

	for (int iCounter = 0; iCounter < 7; ++iCounter)
	{
		cout << endl;
	}

	usleep(3000000);

}

int main()
{
	//showHit(1);
	//showHit(0);
	//showMiss(1);
	//showMiss(0);
	showSank(1, "HOLIII");
}