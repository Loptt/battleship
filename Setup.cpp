#include <iostream>
#include <string>
#include <cmath>
#include <unistd.h>
using namespace std;

//Japanese ship names
const string sJapaneseCarrier = "Ryujo Carrier";
const string sJapananeseBattleship = "Nagato Battleship";
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

/*
getPlayerName
Function to let the user input a name to use
Paramenters: none
Return: a string with the name
*/
string getPlayerName()
{
	string sName;
	cout << "Enter your name: " << endl;
	cin >> sName;
	return sName;
}

/*
chooseTeam
Function to let the user choose a team through a char
Paramenters: none
Return: a char representing a team
*/
char chooseTeam()
{
	char cTeam;

	cout << "Do you want to play as Japan (J) or the United States (U)?" << endl;
	cin >> cTeam;

	while (cTeam != 'J' && cTeam != 'U' && cTeam != 'j' && cTeam != 'u')
	{
		cout << "Invalid team, please enter a valid letter" << endl;
		cin >> cTeam;
	}

	return cTeam;
}

/*
eraseBoard
Function to fill a board with zeroes (empty board)
Paramenters: a Matrix board
Return: nothing
*/
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

/*
writeInput
Function to write the ship position on the board
Parameters: The board, a boolean to validate the position, the first position, and the second position
Return: nothing
*/
void writeInput(int iMatBoard[10][10], bool &bIsWrongInput, string sFirstPosition, string sSecondPosition)
{
	int iFirstLetterCoordinate = sFirstPosition[0] - 65;
	int iSecondLetterCoordinate = sSecondPosition[0] - 65;
	int iFirstNumberCoordinate = sFirstPosition[1] - 48;
	int iSecondNumberCoordinate = sSecondPosition[1] - 48;

	int iRowIndexStart;
	int iColIndexStart;

	int iColIndexEnd;
	int iRowIndexEnd;

	bIsWrongInput = false;

	//For vertical positioning
	if (iFirstLetterCoordinate == iSecondLetterCoordinate)
	{
		int iColIndex = iFirstLetterCoordinate;

		if (iFirstNumberCoordinate > iSecondNumberCoordinate)
		{
			iRowIndexStart = iSecondNumberCoordinate;
			iRowIndexEnd = iFirstNumberCoordinate;
		}
		else
		{
			iRowIndexStart = iFirstNumberCoordinate;
			iRowIndexEnd = iSecondNumberCoordinate;
		}

		int iLoopInitiator = iRowIndexStart;

		for (iRowIndexStart; iRowIndexStart <= iRowIndexEnd; ++iRowIndexStart)
		{
			if (iMatBoard[iRowIndexStart][iColIndex])
			{
				cout << "Invalid coordinates. Space already occupied by another ship" << endl;
				bIsWrongInput = true;
				break;
			}
		}

		if (!bIsWrongInput)
		{
			for (iRowIndexStart = iLoopInitiator; iRowIndexStart <= iRowIndexEnd; ++iRowIndexStart)
			{
				iMatBoard[iRowIndexStart][iColIndex] = 1;
			}
		}
	}

	//For horizontal positioning
	else
	{
		int iRowIndex = iFirstNumberCoordinate;

		if (iFirstLetterCoordinate > iSecondLetterCoordinate)
		{
			iColIndexStart = iSecondLetterCoordinate;
			iColIndexEnd = iFirstLetterCoordinate;
		}
		else
		{
			iColIndexStart = iFirstLetterCoordinate;
			iColIndexEnd = iSecondLetterCoordinate ;
		}

		int iLoopInitiator = iColIndexStart;

		for (iColIndexStart; iColIndexStart <= iColIndexEnd; ++iColIndexStart)
		{
			if (iMatBoard[iRowIndex][iColIndexStart])
			{
				cout << "Invalid coordinates. Space already occupied by another ship" << endl;
				bIsWrongInput = true;
				break;
			}
		}

		if (!bIsWrongInput)
		{

			for (iColIndexStart = iLoopInitiator; iColIndexStart <= iColIndexEnd; ++iColIndexStart)
			{
				iMatBoard[iRowIndex][iColIndexStart] = 1;
			}
		}
	}
}

/*
getPositions
Function to ask the user of the positions of the ships
Parameters: The player board and the size of the ship to input
Return: nothing
*/
void getPositions(int iMatBoard[10][10], int iShipSize)
{
	string sFirstPosition;
	string sSecondPosition;

	int iDifference = 0;

	bool bIsWrongInput = true; 

	while (bIsWrongInput)
	{
		cin >> sFirstPosition >> sSecondPosition;

		//Check if the coordinates are two characters long
		if (sFirstPosition.length() != 2 || sSecondPosition.length() != 2)
		{
			cout << "Invalid coordinates. Please enter two characters per coordinate" << endl;
		}
		else
		{
			//Check if the first character is a letter in valid range
			if (sFirstPosition[0] < 65 || sFirstPosition[0] > 74)
			{
				cout << "Invalid coordinates. Please enter letters from A to J capitalized" << endl;
			}
			else
			{
				//Check if the second character is a number in valid range
				if (sFirstPosition[1] < 48 || sSecondPosition[1] > 57)
				{
					cout << "Invalid coordinates. Please enter a digit as second parameter" << endl;
				}
				else
				{
					//Check if the coordinates are valid positions
					if (sFirstPosition[0] != sSecondPosition[0] &&
	      	   			sFirstPosition[1] != sSecondPosition[1])
					{
						cout << "Invalid coordinates. Please place ships horizontally or vertically" << endl;
					}
					else
					{
						if (sFirstPosition[0] == sSecondPosition[0])
						{
							iDifference = abs(sFirstPosition[1] - sSecondPosition[1]) + 1; 
						}
						else
						{
							iDifference = abs(sFirstPosition[0] - sSecondPosition[0]) + 1; 
						}

						//Check if the ship is of adequate size
						if (iDifference != iShipSize)
						{
							cout << "Invalid coordinates. Please make sure the coordinates are for a ship of size ";
							cout << iShipSize << endl;
						}
						else
						{
							writeInput(iMatBoard, bIsWrongInput, sFirstPosition, sSecondPosition);
						}
					}
				}
			}
		}
	}
}

void printBoard(int iMatBoard[10][10])
{
	cout << "                             YOUR BOARD" << endl << endl;
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
				cout << "| O ";
			}
			else
			{
				cout << "|   ";
			}
		}
		cout << "|" << endl;
		cout << "            |___|___|___|___|___|___|___|___|___|___|" << endl;		
	}
	cout << endl << endl;
}

/*
setupGame
Function to set the boards and ships for a new game
Paramenters: two Boards
Return: nothing
*/
void setupGame(int iMatPlayerBoard[10][10], int iMatComputerBoard[10][10], string &sPlayerName, char &cTeam)
{
	eraseBoard(iMatPlayerBoard);
	eraseBoard(iMatComputerBoard);

	cleanScreen();

	sPlayerName = getPlayerName();

	cleanScreen();

	cTeam = chooseTeam();

	int iShipSize;

	cleanScreen();

	if (cTeam == 'J')
	{
		printBoard(iMatPlayerBoard);

		//Carrier
		iShipSize = 5;

		cout << "Admiral " << sPlayerName << "-San, enter the starting and ending coordinates of your " << sJapaneseCarrier;
		cout << " (" << iShipSize << " spaces)" << endl;

		getPositions(iMatPlayerBoard, iShipSize);

		cleanScreen();

		printBoard(iMatPlayerBoard);

		//Battleship
		iShipSize = 4;

		cout << "Admiral " << sPlayerName << "-San, enter the starting and ending coordinates of your " << sJapananeseBattleship;
		cout << " (" << iShipSize << " spaces)" << endl;

		getPositions(iMatPlayerBoard, iShipSize);	

		cleanScreen();

		printBoard(iMatPlayerBoard);

		//Cruiser
		iShipSize = 3;

		cout << "Admiral " << sPlayerName << "-San, enter the starting and ending coordinates of your " << sJapaneseCruiser;
		cout << " (" << iShipSize << " spaces)" << endl;

		getPositions(iMatPlayerBoard, iShipSize);

		cleanScreen();

		printBoard(iMatPlayerBoard);

		//Submarine
		cout << "Admiral " << sPlayerName << "-San, enter the starting and ending coordinates of your " << sJapaneseSubmarine;
		cout << " (" << iShipSize << " spaces)" << endl;

		getPositions(iMatPlayerBoard, iShipSize);

		cleanScreen();

		printBoard(iMatPlayerBoard);

		//Destroyer
		int iShipSize = 2;

		cout << "Admiral " << sPlayerName << "-San, enter the starting and ending coordinates of your " << sJapaneseDestroyer;
		cout << " (" << iShipSize << " spaces)" << endl;

		getPositions(iMatPlayerBoard, iShipSize);

		cleanScreen();

		printBoard(iMatPlayerBoard);

	}
	else
	{
		printBoard(iMatPlayerBoard);

		//Carrier
		iShipSize = 5;

		cout << "Admiral " << sPlayerName << ", enter the starting and ending coordinates of your " << sAmericanCarrier;
		cout << " (" << iShipSize << " spaces)" << endl;

		getPositions(iMatPlayerBoard, iShipSize);

		cleanScreen();

		printBoard(iMatPlayerBoard);

		//Battleship
		iShipSize = 4;

		cout << "Admiral " << sPlayerName << ", enter the starting and ending coordinates of your " << sAmericanBattleship;
		cout << " (" << iShipSize << " spaces)" << endl;

		getPositions(iMatPlayerBoard, iShipSize);

		cleanScreen();

		printBoard(iMatPlayerBoard);

		//Cruiser
		iShipSize = 3;

		cout << "Admiral " << sPlayerName << ", enter the starting and ending coordinates of your " << sAmericanCruiser;
		cout << " (" << iShipSize << " spaces)" << endl;

		getPositions(iMatPlayerBoard, iShipSize);

		cleanScreen();

		printBoard(iMatPlayerBoard);

		//Submarine
		cout << "Admiral " << sPlayerName << ", enter the starting and ending coordinates of your " << sAmericanSubmarine;
		cout << " (" << iShipSize << " spaces)" << endl;

		getPositions(iMatPlayerBoard, iShipSize);

		cleanScreen();

		printBoard(iMatPlayerBoard);

		//Destroyer
		int iShipSize = 2;

		cout << "Admiral " << sPlayerName << ", enter the starting and ending coordinates of your " << sAmericanDestroyer;
		cout << " (" << iShipSize << " spaces)" << endl;

		getPositions(iMatPlayerBoard, iShipSize);

		cleanScreen();

		printBoard(iMatPlayerBoard);

	}
}

int main()
{
	int matrix1[10][10], matrix2[10][10];
	string name;
	char team;
	setupGame(matrix1, matrix2, name, team);
	return 0;
}