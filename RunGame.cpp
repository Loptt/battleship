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

void writeComputerInput(int iMatBoard[10][10], int iArrShipPosition[], int iShipSize, bool &bIsOverlapped)
{
	bIsOverlapped = false;

	//Horizontal positioning
	if (iArrShipPosition[0])
	{
		int iRowIndex = iArrShipPosition[1];

		for (int iColIndex = iArrShipPosition[2]; iColIndex <= iArrShipPosition[iShipSize+1]; ++iColIndex)
		{
			if (iMatBoard[iRowIndex][iColIndex])
			{
				bIsOverlapped = true;
				break;
			}
		}

		if (!bIsOverlapped)
		{
			for (int iColIndex = iArrShipPosition[2]; iColIndex <= iArrShipPosition[iShipSize+1]; ++iColIndex)
			{
				iMatBoard[iRowIndex][iColIndex] = 1;
			}
		}
	}

	//Vertical Positioning
	else
	{
		int iColIndex = iArrShipPosition[1];

		for (int iRowIndex = iArrShipPosition[2]; iRowIndex <= iArrShipPosition[iShipSize+1]; ++iRowIndex)
		{
			if (iMatBoard[iRowIndex][iColIndex])
			{
				bIsOverlapped = true;
				break;
			}
		}

		if (!bIsOverlapped)
		{
			for (int iRowIndex = iArrShipPosition[2]; iRowIndex <= iArrShipPosition[iShipSize+1]; ++iRowIndex)
			{
				iMatBoard[iRowIndex][iColIndex] = 1;
			}
		}
	}
}

/*
writeComputerInput
Function to generate a random ship position, validate it, and to write it in the board
Parameters: The board, the array with the position, and the ship size
Return: nothing
*/
void generateRandomPosition(int iMatBoard[10][10], int iArrShipPosition[], int iShipSize)
{
	srand(time(NULL));

	bool bIsOverlapped = true;

	while(bIsOverlapped)
	{
		iArrShipPosition[0] = rand() % 2;

		iArrShipPosition[1] = rand() % 10;

		iArrShipPosition[2] = rand() % (10-iShipSize);

		int iExternalCounter = 1;

		for (int iCounter = 3; iCounter < iShipSize + 2 ; ++iCounter)
		{
			iArrShipPosition[iCounter] = iArrShipPosition[2] + iExternalCounter++;
		}

		writeComputerInput(iMatBoard, iArrShipPosition, iShipSize, bIsOverlapped);
	}
	
}

void eraseBoard(int iMatBoard[10][10])
{
	for (int iRowIndex = 0; iRowIndex < 10; ++iRowIndex)
	{
		for (int iColIndex = 0; iColIndex < 10; ++iColIndex)
		{
			iMatBoard[iRowIndex][iColIndex] = 0;
		}
	}
}

void cleanScreen()
{
	for (int iCounter = 0; iCounter < 50; ++iCounter)
	{
		cout << endl;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////

void printRunningBoard(int iMatPlayerBoard[10][10], int iMatComputerBoard[10][10])
{
	cout << "\x1b[37m                           YOUR BOARD                                                COMPUTER BOARD" << endl << endl;
	cout << "              A   B   C   D   E   F   G   H   I   J                      A   B   C   D   E   F   G   H   I   J " << endl;
	cout << "             _______________________________________                    _______________________________________" << endl;

	for (int iRowIndex = 0; iRowIndex < 10; ++iRowIndex)
	{
		cout << "            |   |   |   |   |   |   |   |   |   |   |                  |   |   |   |   |   |   |   |   |   |   |" << endl;
		cout << "          " << iRowIndex << " ";

			for (int iColIndex = 0; iColIndex < 10; ++iColIndex)
			{
				if (iMatPlayerBoard[iRowIndex][iColIndex] == 1)
				{
					cout << "|\x1b[0m O \x1b[37m";
				}
				else
				{
					if (iMatPlayerBoard[iRowIndex][iColIndex] == 2 || iMatPlayerBoard[iRowIndex][iColIndex] == 4)
					{
						cout << "|\x1b[31m X \x1b[37m";
					}
					else
					{
						if (iMatPlayerBoard[iRowIndex][iColIndex] == 3)
						{
							cout << "|\x1b[37m @ \x1b[37m";					
						}
						else
						{
							cout << "|\x1b[34m . \x1b[37m";
						}
					}
				}
			}
		cout << "|" << "                " << iRowIndex << " ";

		for (int iColIndex = 0; iColIndex < 10; ++iColIndex)
		{
			if (iMatComputerBoard[iRowIndex][iColIndex] == 1)
			{
				cout << "|\x1b[34m . \x1b[37m";
			}
			else
			{
				if (iMatComputerBoard[iRowIndex][iColIndex] == 2)
				{
					cout << "|\x1b[31m X \x1b[37m";
				}
				else
				{
					if (iMatComputerBoard[iRowIndex][iColIndex] == 4)
					{
						cout << "|\x1b[31m X \x1b[37m";
					}
					else
					{
						if (iMatComputerBoard[iRowIndex][iColIndex] == 3)
						{
							cout << "|\x1b[37m @ \x1b[37m";					
						}
						else
						{
							cout << "|\x1b[34m . \x1b[37m";
						}
					}
				}
			}
		}
		cout << "|" << endl;

		cout << "            |___|___|___|___|___|___|___|___|___|___|                  |___|___|___|___|___|___|___|___|___|___|" << endl;		
	}
	cout << "\x1b[0m" << endl << endl;
}

bool checkIfWinner(int iMatBoard[10][10], bool &bGameIsRunning)
{
	bool bIsWinner = true;

	for (int iRowIndex = 0; iRowIndex < 10; ++iRowIndex)
	{
		for (int iColIndex = 0; iColIndex < 10; ++iColIndex)
		{
			if (iMatBoard[iRowIndex][iColIndex] == 1)
			{
				bIsWinner = false;
			}
		}
	}

	if (bIsWinner)
	{
		bGameIsRunning = false;
	}

	return bIsWinner;
}

void checkIndividualShip(int iMatComputerBoard[10][10], int iArrShipPosition[], int iShipSize, char cTeam, int iCounter)
{
	bool bIsSunken = true;
	string sArrShips[10] = {sAmericanCarrier, sJapaneseCarrier, sAmericanBattleship, sJapaneseBattleship, sAmericanCruiser,
							sJapaneseCruiser, sAmericanSubmarine, sJapaneseSubmarine, sAmericanDestroyer, sJapaneseDestroyer};

	//Check for horizontal positioning
	if (iArrShipPosition[0])
	{
		int iRowIndex = iArrShipPosition[1];

		for (int iColIndex = iArrShipPosition[2]; iColIndex <= iArrShipPosition[iShipSize + 1]; ++iColIndex)
		{
			if (iMatComputerBoard[iRowIndex][iColIndex] != 2)
			{
				bIsSunken = false;
			}
		}

		if (bIsSunken)
		{
			cout << "You have sank the enemy ";

			if (cTeam == 'J' || cTeam == 'j')
			{
				cout << sArrShips[iCounter] << "!" << endl;
			}
			else
			{
				cout << sArrShips[iCounter + 1] << "!" << endl;
			}

			for (int iColIndex = iArrShipPosition[2]; iColIndex <= iArrShipPosition[iShipSize + 1]; ++iColIndex)
			{
				iMatComputerBoard[iRowIndex][iColIndex] = 4;
			}
		}
	}

	//Check for vertical positioning
	else
	{
		int iColIndex = iArrShipPosition[1];

		for (int iRowIndex = iArrShipPosition[2]; iRowIndex <= iArrShipPosition[iShipSize + 1]; ++iRowIndex)
		{
			if (iMatComputerBoard[iRowIndex][iColIndex] != 2)
			{
				bIsSunken = false;
			}
		}

		if (bIsSunken)
		{
			cout << "You have sank the enemy ";

			if (cTeam == 'J' || cTeam == 'j')
			{
				cout << sArrShips[iCounter] << "!" << endl;
			}
			else
			{
				cout << sArrShips[iCounter + 1] << "!" << endl;
			}

			for (int iRowIndex = iArrShipPosition[2]; iRowIndex <= iArrShipPosition[iShipSize + 1]; ++iRowIndex)
			{
				iMatComputerBoard[iRowIndex][iColIndex] = 4;
			}
		}
	}
}

void checkComputerShips(int iMatComputerBoard[10][10], char cTeam, int iArrComputerCarrierPosition[], int iArrComputerBattleshipPosition[], 
				        int iArrComputerCruiserPosition[], int iArrComputerSubmarinePosition[], int iArrComputerDestroyerPosition[])
{
	int iShipSize;
	int iCounter = 0;

	//Check Carrier status
	iShipSize = 5;
	checkIndividualShip(iMatComputerBoard, iArrComputerCarrierPosition, iShipSize, cTeam, iCounter);

	iCounter += 2;

	//Check Battleship status
	iShipSize = 4;
	checkIndividualShip(iMatComputerBoard, iArrComputerBattleshipPosition, iShipSize, cTeam, iCounter);

	iCounter += 2;

	//Check Cruiser status
	iShipSize = 3;
	checkIndividualShip(iMatComputerBoard, iArrComputerCruiserPosition, iShipSize, cTeam, iCounter);

	iCounter += 2;

	//Check Submarine status
	iShipSize = 3;
	checkIndividualShip(iMatComputerBoard, iArrComputerSubmarinePosition, iShipSize, cTeam, iCounter);

	iCounter += 2;

	//Check Destroyer status
	iShipSize = 2;
	checkIndividualShip(iMatComputerBoard, iArrComputerDestroyerPosition, iShipSize, cTeam, iCounter);

}

void playerExectueShot(int iMatComputerBoard[10][10], int iXCoordinate, int iYCoordinate, bool &bIsWrongInput)
{
	if (iMatComputerBoard[iYCoordinate][iXCoordinate] == 0)
	{	
		cout << "You've missed!" << endl;
		iMatComputerBoard[iYCoordinate][iXCoordinate] = 3;	
		bIsWrongInput = false;
	}
	else
	{
		if (iMatComputerBoard[iYCoordinate][iXCoordinate] == 1)
		{
			cout << "You've hit a ship!" << endl;
			iMatComputerBoard[iYCoordinate][iXCoordinate] = 2;
			bIsWrongInput = false;
		}
		else
		{
			if (iMatComputerBoard[iYCoordinate][iXCoordinate] == 2 || iMatComputerBoard[iYCoordinate][iXCoordinate] == 4)
			{
				cout << "\x1b[31mInvalid coordinate, you've already hit that spot\x1b[0m" << endl;
			}
			else
			{
				if (iMatComputerBoard[iYCoordinate][iXCoordinate == 3])
				{
					cout << "\x1b[31mInvalid coordinate, you've already hit that spot\x1b[0m" << endl;
				}
			}
		}
	}
}

void getPlayerCoordinate(int iMatPlayerBoard[10][10], int iMatComputerBoard[10][10], string sPlayerName, char cTeam)
{
	string sHitCoordinate;

	bool bIsWrongInput = true;

	printRunningBoard(iMatPlayerBoard, iMatComputerBoard);

	cout << "Admiral " << sPlayerName;

	if (cTeam == 'J' || cTeam == 'j')
	{
		cout << "-San";
	}

	cout << ",  enter the coordinates where you want to strike!" << endl;

	while (bIsWrongInput)
	{
		cin >> sHitCoordinate;

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
					playerExectueShot(iMatComputerBoard, iXCoordinate, iYCoordinate, bIsWrongInput);
				}
			}
		}
	}
}


void playerTurn(int iMatPlayerBoard[10][10], int iMatComputerBoard[10][10], string sPlayerName, char cTeam, int iArrComputerCarrierPosition[], 
				int iArrComputerBattleshipPosition[], int iArrComputerCruiserPosition[], 
				int iArrComputerSubmarinePosition[], int iArrComputerDestroyerPosition[])
{
	getPlayerCoordinate(iMatPlayerBoard, iMatComputerBoard, sPlayerName, cTeam);

	checkComputerShips(iMatComputerBoard, cTeam, iArrComputerCarrierPosition, iArrComputerBattleshipPosition, iArrComputerCruiserPosition,
					   iArrComputerSubmarinePosition, iArrComputerDestroyerPosition);
}

void runGame(int iMatPlayerBoard[10][10], int iMatComputerBoard[10][10], string sPlayerName, char cTeam,
             int iArrPlayerCarrierPosition[7], int iArrPlayerBattleshipPosition[6], int iArrPlayerCruiserPosition[5],
		     int iArrPlayerSubmarinePosition[5], int iArrPlayerDestroyerPosition[4], int iArrComputerCarrierPosition[7],
		     int iArrComputerBattleshipPosition[6], int iArrComputerCruiserPosition[5], int iArrComputerSubmarinePosition[5],
		     int iArrComputerDestroyerPosition[4])
{
	bool bGameIsRunning = true;
	bool bIsWinner = false;

	cleanScreen();

	while (bGameIsRunning)
	{
		playerTurn(iMatPlayerBoard, iMatComputerBoard, sPlayerName, cTeam, iArrComputerCarrierPosition, iArrComputerBattleshipPosition, iArrComputerCruiserPosition,
				   iArrComputerSubmarinePosition, iArrComputerDestroyerPosition);

		bIsWinner = checkIfWinner(iMatComputerBoard, bGameIsRunning);

		if (!bGameIsRunning)
		{
			break;
		}

		//computerTurn(iMatPlayerBoard, iArrPlayerCarrierPosition, iArrPlayerBattleshipPosition,
		//	         iArrPlayerCruiserPosition, iArrPlayerSubmarinePosition, iArrPlayerDestroyerPosition);

		//bIsWinner = !checkIfWinner(iMatPlayerBoard, bGameIsRunning);
	}

	if (bIsWinner)
	{
		cout << "You won!" << endl;
	}
	else
	{
		cout << "You lost!" << endl;
	}
}

int main()
{
	int iMatPlayerBoard[10][10];
	int iMatComputerBoard[10][10];

	eraseBoard(iMatPlayerBoard);
	eraseBoard(iMatComputerBoard);

		int iArrPlayerCarrierPosition[7];
		int iArrPlayerBattleshipPosition[6];
		int iArrPlayerCruiserPosition[5];
		int iArrPlayerSubmarinePosition[5];
		int iArrPlayerDestroyerPosition[4];

		int iArrComputerCarrierPosition[7];
		int iArrComputerBattleshipPosition[6];
		int iArrComputerCruiserPosition[5];
		int iArrComputerSubmarinePosition[5];
		int iArrComputerDestroyerPosition[4];	 

		generateRandomPosition(iMatComputerBoard, iArrComputerCarrierPosition, 5);
		generateRandomPosition(iMatComputerBoard, iArrComputerBattleshipPosition, 4);
		generateRandomPosition(iMatComputerBoard, iArrComputerCruiserPosition, 3);
		generateRandomPosition(iMatComputerBoard, iArrComputerSubmarinePosition, 3);
		generateRandomPosition(iMatComputerBoard, iArrComputerDestroyerPosition, 2);

		string sPlayerName = "Yon";

		char cTeam = 'U';

printRunningBoard(iMatPlayerBoard, iMatComputerBoard);
	runGame(iMatPlayerBoard, iMatComputerBoard, sPlayerName, cTeam, iArrPlayerCarrierPosition,
						iArrPlayerBattleshipPosition, iArrPlayerCruiserPosition, iArrPlayerSubmarinePosition,
						iArrPlayerDestroyerPosition, iArrComputerCarrierPosition, iArrComputerBattleshipPosition,
						iArrComputerCruiserPosition, iArrComputerSubmarinePosition, iArrComputerDestroyerPosition);

}