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

/*
main
Function to call other functions
Paramenters: none
Return: 0
*/
int main()
{
	int iMatPlayer1Board[10][10];
	int iMatPlayer2Board[10][10];
	string sPlayerName;

	setupGame(iMatPlayer1Board,iMatPlayer2Board);

	return 0;    
}



