/*
MAIN FILE
Erick Francisco González Martínez  A01039859
Carlos Daniel Estrada Guerra       A01039919
 BATTLESHIP_GAME
 version 1.0
*/

#include <iostream>
#include <string>
using namespace std;

//Battle space matrix constant size
const int iWidth =10;
const int iHeight =10;

char getMenuInput()
{
	char cInput;
	cin >> cInput;
	return cInput;
}

/*
main
Function to call other functions
Paramenters: none
Return: 0
*/
int main()
{
	bool bRunGame = true;

	while (bRunGame)
	{
		int iMatPlayer1Board[10][10];
		int iMatPlayer2Board[10][10];
		string sPlayerName;
		char cTeam;

		char cInput = getMenuInput();

		switch(cInput)
		{	
			//Start game
			case 'S':
				setupGame(iMatPlayer1Board,iMatPlayer2Board, sPlayerName, cTeam);
				runGame(iMatPlayer1Board, iMatPlayer2Board, sPlayerName, cTeam);
				endGame();
				break;

			//Show instructions
			case 'I':
				displayInstructions();
				break;

			//Show about information	
			case 'A':
				displayAbout();
				break;

			//Exit game
			case 'E':
				bRunGame = false;
				break;

			//Case when a wrong letter is introduced
			default:
				cout << "Invalid Option" << endl;
				break;
		}
	}

	return 0;    
}



