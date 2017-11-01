#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void writeInput(int iMatBoard[10][10], string sFirstPosition, string sSecondPosition, int iShipSize)
{
	int iFirstLetterCoordinate = sFirstPosition[0] - 65;
	int iSecondLetterCoordinate = sSecondPosition[0] - 65;
	int iFirstNumberCoordinate = sFirstPosition[1] - 48;
	int iSecondNumberCoordinate = sSecondPosition[1] - 48;

	cout << iFirstLetterCoordinate << iSecondLetterCoordinate << endl;

	int iRowIndexStart;
	int iColIndexStart;

	int iColIndexEnd;
	int iRowIndexEnd;

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

		for (iRowIndexStart; iRowIndexStart <= iRowIndexEnd; ++iRowIndexStart)
		{
			iMatBoard[iRowIndexStart][iColIndex] = 1;
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

		for (iColIndexStart; iColIndexStart <= iColIndexEnd; ++iColIndexStart)
		{
			iMatBoard[iRowIndex][iColIndexStart] = 1;
		}
	}
}

void getPositions(int iMatBoard[10][10], int iShipSize)
{
	string sFirstPosition;
	string sSecondPosition;

	int iDifference = 0;

	cin >> sFirstPosition >> sSecondPosition;

	//Check if the coordinates are two characters long
	while (sFirstPosition.length() != 2 || sSecondPosition.length() != 2)
	{
		cout << "Invalid coordinates. Please enter two characters per coordinate" << endl;
		cin >> sFirstPosition >> sSecondPosition;
	}

	//Check if the first character is a letter in valid range
	while (sFirstPosition[0] < 65 || sFirstPosition[0] > 74)
	{
		cout << "Invalid coordinates. Please enter letters from A to J capitalized" << endl;
		cin >> sFirstPosition >> sSecondPosition;
	}
	
	//Check if the second character is a number in valid range
	while (sFirstPosition[1] < 48 || sSecondPosition[1] > 57)
	{
		cout << "Invalid coordinates. Please enter a digit as second parameter" << endl;
		cin >> sFirstPosition >> sSecondPosition;
	}

	//Check if the coordinates are valid positions
	while (sFirstPosition[0] != sSecondPosition[0] &&
      	   sFirstPosition[1] != sSecondPosition[1])
	{
		cout << "Invalid coordinates. Please place ships horizontally or vertically" << endl;
		cin >> sFirstPosition >> sSecondPosition;
	}

	//Check if the ship is of adequate size
	do
	{
		if (sFirstPosition[0] == sSecondPosition[0])
		{
			iDifference = abs(sFirstPosition[1] - sSecondPosition[1]) + 1; 
		}
		else
		{
			iDifference = abs(sFirstPosition[0] - sSecondPosition[0]) + 1; 
		}

		if (iDifference != iShipSize)
		{
			cout << "Invalid coordinates. Please make sure the coordinates for a ship of size ";
			cout << iShipSize << endl;
			cin >> sFirstPosition >> sSecondPosition;
		}

	}
	while (iDifference != iShipSize);

	writeInput(iMatBoard, sFirstPosition, sSecondPosition, iShipSize);
}

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

int main()
{
	int matrix[10][10];
	eraseBoard(matrix);
	getPositions(matrix, 5);

	cout << "  ABCDEFGHIJ" << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << i << " ";
		for (int j = 0; j < 10; ++j)
		{
			if (matrix[i][j])
			{
				cout << "O";
			}
			else
			{
				cout << ".";
			}
		}

		cout << endl;
	}

	return 0;
}