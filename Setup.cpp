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

/*	
cleanScreen
Function to clean up the screen of any element
Parameters: none
Retrun nothing
*/
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
printSetupBoard
Function to print the player or computer board in the console
Parameters: The board to print
Return: nothing
*/
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

void getComputerPositions(int iMatBoard[10][10])
{

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
				cout << "\x1b[31mInvalid coordinates. Space already occupied by another ship\x1b[0m" << endl;
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
				cout << "\x1b[31mInvalid coordinates. Space already occupied by another ship\x1b[0m" << endl;
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
readUserPositions
Function to let the user input coordinates
Parameters: The player board and the size of the ship to input
Return: nothing
*/
void readUserPositions(int iMatBoard[10][10], int iShipSize)
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
			cout << "\x1b[31mInvalid coordinates. Please enter two characters per coordinate\x1b[0m" << endl;
		}
		else
		{
			//Check if the first character is a letter in valid range
			if (sFirstPosition[0] < 65 || sFirstPosition[0] > 74)
			{
				cout << "\x1b[31mInvalid coordinates. Please enter letters from A to J capitalized\x1b[0m" << endl;
			}
			else
			{
				//Check if the second character is a number in valid range
				if (sFirstPosition[1] < 48 || sSecondPosition[1] > 57)
				{
					cout << "\x1b[31mInvalid coordinates. Please enter a digit as second parameter\x1b[0m" << endl;
				}
				else
				{
					//Check if the coordinates are valid positions
					if (sFirstPosition[0] != sSecondPosition[0] &&
	      	   			sFirstPosition[1] != sSecondPosition[1])
					{
						cout << "\x1b[31mInvalid coordinates. Please place ships horizontally or vertically\x1b[0m" << endl;
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
							cout << "\x1b[31mInvalid coordinates. Please make sure the coordinates are for a ship of size ";
							cout << iShipSize << "\x1b[0m" <<endl;
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

/*
getPlayerPositions
Function to ask the user for the ship positions 
Parameters: The Player board, the name, and the char of the team
Retrun nothing
*/
void getPlayerPositions(int iMatPlayerBoard[10][10], string sPlayerName, char cTeam)
{
	int iShipSize;

	if (cTeam == 'J')
	{
		printSetupBoard(iMatPlayerBoard);

		//Carrier
		iShipSize = 5;

		cout << "Admiral " << sPlayerName << "-San, enter the starting and ending coordinates of your " << sJapaneseCarrier;
		cout << " (" << iShipSize << " spaces)" << endl;

		readUserPositions(iMatPlayerBoard, iShipSize);

		cleanScreen();

		printSetupBoard(iMatPlayerBoard);

		//Battleship
		iShipSize = 4;

		cout << "Admiral " << sPlayerName << "-San, enter the starting and ending coordinates of your " << sJapananeseBattleship;
		cout << " (" << iShipSize << " spaces)" << endl;

		readUserPositions(iMatPlayerBoard, iShipSize);	

		cleanScreen();

		printSetupBoard(iMatPlayerBoard);

		//Cruiser
		iShipSize = 3;

		cout << "Admiral " << sPlayerName << "-San, enter the starting and ending coordinates of your " << sJapaneseCruiser;
		cout << " (" << iShipSize << " spaces)" << endl;

		readUserPositions(iMatPlayerBoard, iShipSize);

		cleanScreen();

		printSetupBoard(iMatPlayerBoard);

		//Submarine
		cout << "Admiral " << sPlayerName << "-San, enter the starting and ending coordinates of your " << sJapaneseSubmarine;
		cout << " (" << iShipSize << " spaces)" << endl;

		readUserPositions(iMatPlayerBoard, iShipSize);

		cleanScreen();

		printSetupBoard(iMatPlayerBoard);

		//Destroyer
		int iShipSize = 2;

		cout << "Admiral " << sPlayerName << "-San, enter the starting and ending coordinates of your " << sJapaneseDestroyer;
		cout << " (" << iShipSize << " spaces)" << endl;

		readUserPositions(iMatPlayerBoard, iShipSize);

		cleanScreen();

		printSetupBoard(iMatPlayerBoard);

	}
	else
	{
		printSetupBoard(iMatPlayerBoard);

		//Carrier
		iShipSize = 5;

		cout << "Admiral " << sPlayerName << ", enter the starting and ending coordinates of your " << sAmericanCarrier;
		cout << " (" << iShipSize << " spaces)" << endl;

		readUserPositions(iMatPlayerBoard, iShipSize);

		cleanScreen();

		printSetupBoard(iMatPlayerBoard);

		//Battleship
		iShipSize = 4;

		cout << "Admiral " << sPlayerName << ", enter the starting and ending coordinates of your " << sAmericanBattleship;
		cout << " (" << iShipSize << " spaces)" << endl;

		readUserPositions(iMatPlayerBoard, iShipSize);

		cleanScreen();

		printSetupBoard(iMatPlayerBoard);

		//Cruiser
		iShipSize = 3;

		cout << "Admiral " << sPlayerName << ", enter the starting and ending coordinates of your " << sAmericanCruiser;
		cout << " (" << iShipSize << " spaces)" << endl;

		readUserPositions(iMatPlayerBoard, iShipSize);

		cleanScreen();

		printSetupBoard(iMatPlayerBoard);

		//Submarine
		cout << "Admiral " << sPlayerName << ", enter the starting and ending coordinates of your " << sAmericanSubmarine;
		cout << " (" << iShipSize << " spaces)" << endl;

		readUserPositions(iMatPlayerBoard, iShipSize);

		cleanScreen();

		printSetupBoard(iMatPlayerBoard);

		//Destroyer
		int iShipSize = 2;

		cout << "Admiral " << sPlayerName << ", enter the starting and ending coordinates of your " << sAmericanDestroyer;
		cout << " (" << iShipSize << " spaces)" << endl;

		readUserPositions(iMatPlayerBoard, iShipSize);

		cleanScreen();

		printSetupBoard(iMatPlayerBoard);

	}
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

	cleanScreen();

	getPlayerPositions(iMatPlayerBoard, sPlayerName, cTeam);

	//getComputerPositions(iMatComputerBoard);
}

int main()
{

	int matrix1[10][10], matrix2[10][10];
	string name;
	char team;
	setupGame(matrix1, matrix2, name, team);
	return 0;
}
