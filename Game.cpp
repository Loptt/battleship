/*
MAIN FILE
Erick Francisco González Martínez  A01039859
Carlos Daniel Estrada Guerra       A01039919
 BATTLESHIP_GAME
 version 1.0
*/

#include <iostream>
#include <string>
//Own created libraries
#include "createdfunctions.h"
using namespace std;

//Battle space matrix constant size
const int iWidth =10;
const int iHeight =10;

/*
fillBoard
Function to fill a board with zeroes (empty board)
Paramenters: a Matrix board
Return: nothing
*/
void fillBoard(int iMatBoard[10][10])
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
main
Function to call other functions
Paramenters: none
Return: 0
*/
int main()
{
	int iMatPlayer1Board[10][10];
	int iMatPlayer2Board[10][10];

	fillBoard(iMatPlayer1Board);
	fillBoard(iMatPlayer2Board);

	return 0;    
}



