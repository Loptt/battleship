#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
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

void exectueShot(int iMatBoard[10][10] int iXCoordinate, int iYCoordinate bool &bIsWrongInput)
{
	if (iMatBoard[iXCoordinate][iYCoordinate] == 0)
	{
		cout << "You've missed!" << endl;
		iMatBoard[iXCoordinate][iYCoordinate] = 3;
		bIsWrongInput = false;
	}
	else
	{
		if (iMatBoard[iXCoordinate][iYCoordinate] == 1)
		{
			cout << "You've hit a ship!" << endl;
			iMatBoard[iXCoordinate][iYCoordinate] = 2;
			bIsWrongInput = false;
		}
		else
		{
			if (iMatBoard[iXCoordinate][iYCoordinate] == 2)
			{
				cout << "\x1b[31mInvalid coordinate, you've already hit that spot\x1b[0m" << endl;
			}
			else
			{
				cout << "\x1b[31mInvalid coordinate, you've already hit that spot\x1b[0m" << endl;
			}
		}
	}
}

void getPlayerCoordinate()
{
	string sHitCoordinate;

	bool bIsWrongInput = true;

	cout << "Admiral " << sPlayerName;

	if (cTeam == 'J' || cTeam == 'j')
	{
		cout << "-San";
	}

	cout << ",  enter the coordinates where you want to strike!" << endl;

	while (bIsWrongInput)
	{
		cin >> sHitCoordinate

		//Check if the coordinates are two characters long
		if (sHitCoordinate.length() != 2)
		{
			cout << "\x1b[31mInvalid coordinate. Please enter two characters as coordinate\x1b[0m" << endl;
		}
		else
		{
			//Check if the first character is a letter in valid range
			if (sHitCoordinate[0] < 65 || sHitCoordinate[0] > 74)
			{
				cout << "\x1b[31mInvalid coordinate. Please enter letters from A to J capitalized\x1b[0m" << endl;
			}
			else
			{
				//Check if the second character is a number in valid range
				if (sHitCoordinate[1] < 48 || sHitCoordinate[1] > 57)
				{
					cout << "\x1b[31mInvalid coordinate. Please enter a digit as second parameter\x1b[0m" << endl;
				}
				else
				{
					int iXCoordinate = sHitCoordinate[0] - 65;
					int iYCoordinate = sHitCoordinate[1] - 48;
					exectueShot(iMatBoard, iXCoordinate, iYCoordinate, bIsWrongInput);
				}
			}
		}
	}
}


void playerTurn(int iMatBoard[10][10], int iArrComputerCarrierPosition[], int iArrComputerBattleshipPosition[],
			    int iArrComputerCruiserPosition[], int iArrComputerSubmarinePosition[], int iArrComputerDestroyerPosition[])
{
	getPlayerCoordinate(iMatBoard, iArrComputerCarrierPosition, iArrComputerBattleshipPosition, iArrComputerCruiserPosition
		  				iArrComputerSubmarinePosition, iArrPlayerDestroyerPosition);

	

}

void runGame(int iMatPlayerBoard[10][10], int iMatComputerBoard[10][10], string &sPlayerName, char &cTeam,
             int iArrPlayerCarrierPosition[7], int iArrPlayerBattleshipPosition[6], int iArrPlayerCruiserPosition[5],
		     int iArrPlayerSubmarinePosition[5], int iArrPlayerDestroyerPosition[4], int iArrComputerCarrierPosition[7],
		     int iArrComputerBattleshipPosition[6], int iArrComputerCruiserPosition[5], int iArrComputerSubmarinePosition[5],
		     int iArrComputerDestroyerPosition[4])
{
	bool bGameIsRunning = true;
	bool bIsWinner = false;

	while (bGameIsRunning)
	{
		playerTurn(iMatComputerBoard, iArrComputerCarrierPosition, iArrComputerBattleshipPosition, iArrComputerCruiserPosition,
				   iArrComputerSubmarinePosition, iArrComputerDestroyerPosition);

		bIsWinner = checkIfWinner(iMatComputerBoard);

		computerTurn(iMatPlayerBoard, iArrPlayerCarrierPosition, iArrPlayerBattleshipPosition,
			         iArrPlayerCruiserPosition, iArrPlayerSubmarinePosition, iArrPlayerDestroyerPosition);

		bIsWinner = !checkIfWinner(iMatPlayerBoard);
	}

	if (bIsWinner)
	{
		
	}
}

int main()
{

}