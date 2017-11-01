#include <iostream>
#include <string>
using namespace std;

/*
getPlayerName
Function to let the user input a name to use
Paramenters: none
Return: a string with the name
*/
string getPlayerName()
{
	string sName;
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
	cin >> cTeam;
	while (cTeam != 'J' && cTeam != 'U')
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
			bMatBoard[iRowIndex][iColIndex] = 0;
		}
	}
}

/*
setupGame
Function to set the boards and ships for a new game
Paramenters: two Boards
Return: nothing
*/
void setupGame(int iMatPlayer1Board[10][10], int iMatPlayer2Board[10][10], &sPlayerName, &cTeam)
{
	eraseBoard(iMatPlayer1Board);
	eraseBoard(iMatPlayer2Board);

	sPlayerName = getPlayerName();

	cTeam = chooseTeam();

	int iShipSize;

	if (cTeam == 'J')
	{

		//Carrier
		iShipSize = 5;

		cout << "Enter the starting and ending coordinates of your " << sJapananeseCarrier;
		cout << " (" << iShipSize << " spaces)" << endl;

		getPositions(iMatPlayer1Board, iShipSize);

		//Battleship
		iShipSize = 4;

		cout << "Enter the starting and ending coordinates of your " << sJapananeseBattleship;
		cout << " (" << iShipSize << " spaces)" << endl;

		getPositions(iMatPlayer1Board, iShipSize);

		//Cruiser
		iShipSize = 3;

		cout << "Enter the starting and ending coordinates of your " << sJapananeseCruiser;
		cout << " (" << iShipSize << " spaces)" << endl;

		getPositions(iMatPlayer1Board, iShipSize);

		//Submarine
		cout << "Enter the starting and ending coordinates of your " << sJapananeseSubmarine;
		cout << " (" << iShipSize << " spaces)" << endl;

		getPositions(iMatPlayer1Board, iShipSize);

		//Destroyer
		int iShipSize = 2;

		cout << "Enter the starting and ending coordinates of your " << sJapananeseSubmarine;
		cout << " (" << iShipSize << " spaces)" << endl;

		getPositions(iMatPlayer1Board, iShipSize);
	}
	else
	{
		//Carrier
		iShipSize = 5;

		cout << "Enter the starting and ending coordinates of your " << sAmericanCarrier;
		cout << " (" << iShipSize << " spaces)" << endl;

		getPositions(iMatPlayer1Board, iShipSize);

		//Battleship
		iShipSize = 4;

		cout << "Enter the starting and ending coordinates of your " << sAmericanBattleship;
		cout << " (" << iShipSize << " spaces)" << endl;

		getPositions(iMatPlayer1Board, iShipSize);

		//Cruiser
		iShipSize = 3;

		cout << "Enter the starting and ending coordinates of your " << sAmericanCruiser;
		cout << " (" << iShipSize << " spaces)" << endl;

		getPositions(iMatPlayer1Board, iShipSize);

		//Submarine
		cout << "Enter the starting and ending coordinates of your " << sAmericanSubmarine;
		cout << " (" << iShipSize << " spaces)" << endl;

		getPositions(iMatPlayer1Board, iShipSize);

		//Destroyer
		int iShipSize = 2;

		cout << "Enter the starting and ending coordinates of your " << sAmericanSubmarine;
		cout << " (" << iShipSize << " spaces)" << endl;

		getPositions(iMatPlayer1Board, iShipSize);
	}
}