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

void printSetupBoard(int iMatBoard[10][10])
{
	cout << "\x1b[37m                           YOUR BOARD" << endl << endl;
	cout << "              A   B   C   D   E   F   G   H   I   J" << endl;
	cout << "             _______________________________________ " << endl;

	for (int iRowIndex = 0; iRowIndex < 10; ++iRowIndex)
	{
		cout << "            |   |   |   |   |   |   |   |   |   |   |" << endl;
		cout << "          " << iRowIndex << " ";

		for (int iColIndex = 0; iColIndex < 10; ++iColIndex)
		{
			if (iMatBoard[iRowIndex][iColIndex])
			{
				cout << "|\x1b[0m O \x1b[37m";
			}
			else
			{
				cout << "|\x1b[34m . \x1b[37m";
			}
		}
		cout << "|" << endl;
		cout << "            |___|___|___|___|___|___|___|___|___|___|" << endl;		
	}
	cout << "\x1b[0m" << endl << endl;
}

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

		for (int i = 0; i < iShipSize +2; ++i)
		{
			cout << iArrShipPosition[i] << endl;
		}

		writeComputerInput(iMatBoard, iArrShipPosition, iShipSize, bIsOverlapped);
	}
	
}

void getComputerPositions(int iMatBoard[10][10], int iArrComputerCarrierPosition[], int iArrComputerBattleshipPosition[],
			           	  int iArrComputerCruiserPosition[], int iArrComputerSubmarinePosition[], int iArrComputerDestroyerPosition[])
{
	//Computer Carrier
	int iShipSize = 5;
	generateRandomPosition(iMatBoard, iArrComputerCarrierPosition, iShipSize);

	//Computer Battleship
	iShipSize = 4;

	generateRandomPosition(iMatBoard, iArrComputerBattleshipPosition, iShipSize);

	//Computer Cruiser
	iShipSize = 3;

	generateRandomPosition(iMatBoard, iArrComputerCruiserPosition, iShipSize);

	//Computer Submarine
	iShipSize = 3;

	generateRandomPosition(iMatBoard, iArrComputerSubmarinePosition, iShipSize);

	//Computer Destroyer
	iShipSize = 2;

	generateRandomPosition(iMatBoard, iArrComputerDestroyerPosition, iShipSize);
}

int main()
{
	int iMatComputerBoard[10][10];
	eraseBoard(iMatComputerBoard);

	int iArrComputerCarrierPosition[7];
	int iArrComputerBattleshipPosition[6];
	int iArrComputerCruiserPosition[5];
	int iArrComputerSubmarinePosition[5];
	int iArrComputerDestroyerPosition[4];

	getComputerPositions(iMatComputerBoard, iArrComputerCarrierPosition, iArrComputerBattleshipPosition, iArrComputerCruiserPosition,
						 iArrComputerSubmarinePosition, iArrComputerDestroyerPosition);

	printSetupBoard(iMatComputerBoard);

	return 0;
}