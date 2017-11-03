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
#include <unistd.h>
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
		iint iMatPlayerBoard[10][10], iMatComputerBoard[10][10];

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

		string sPlayerName;

		char cTeam;

		char cInput = getMenuInput();

		switch(cInput)
		{	
			//Start game
			case 'P':
			case 'p':

				setupGame(iMatPlayerBoard, iMatComputerBoard, sPlayerName, cTeam, iArrPlayerCarrierPosition,
						  iArrPlayerBattleshipPosition, iArrPlayerCruiserPosition, iArrPlayerSubmarinePosition,
						  iArrPlayerDestroyerPosition, iArrComputerCarrierPosition, iArrComputerBattleshipPosition,
						  iArrComputerCruiserPosition, iArrComputerSubmarinePosition, iArrComputerDestroyerPosition);

				runGame(iMatPlayerBoard, iMatComputerBoard, sPlayerName, cTeam, iArrPlayerCarrierPosition,
						iArrPlayerBattleshipPosition, iArrPlayerCruiserPosition, iArrPlayerSubmarinePosition,
						iArrPlayerDestroyerPosition, iArrComputerCarrierPosition, iArrComputerBattleshipPosition,
						iArrComputerCruiserPosition, iArrComputerSubmarinePosition, iArrComputerDestroyerPosition);

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
				cout << "Invalid option" << endl;
				break;
		}
	}

	return 0;    
}



