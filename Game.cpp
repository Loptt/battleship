/*
MAIN FILE
Erick Francisco González Martínez  A01039859
Carlos Daniel Estrada Guerra       A01039919
 BATTLESHIP_GAME
 version 1.0
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//Japanese ships names
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
getMenuInput
Function to get the input in the menu function
Paramenters: none
Return: a char provided by the user
*/
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
			case 'P':
			case 'p':
				setupGame(iMatPlayer1Board,iMatPlayer2Board, sPlayerName, cTeam);
				runGame(iMatPlayer1Board, iMatPlayer2Board, sPlayerName, cTeam);
				endGame();
				break;

			//Show instructions
			case 'I':
			case 'i':
				displayInstructions();
				break;

			//Show about information	
			case 'A':
			case 'a':
				displayAbout();
				break;

			//Exit game
			case 'E':
			case 'e':
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



