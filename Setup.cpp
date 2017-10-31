#include <iostream>
#include <string>
using namespace std;

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

void setupGame(int iMatPlayer1Board[10][10], int iMatPlayer2Board[10][10])
{
	fillBoard(iMatPlayer1Board);
	fillBoard(iMatPlayer2Board);

	
}