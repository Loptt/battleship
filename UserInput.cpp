#include <iostream>
#include <string>
#include <cmath>
using namespace std;

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

		for (iRowIndexStart; iRowIndexStart <= iRowIndexEnd; ++iRowIndexStart)
		{
			if (iMatBoard[iRowIndexStart][iColIndex])
			{
				bIsWrongInput = true;
				break;
			}
		}

		if (!bIsWrongInput)
		{
			for (iRowIndexStart; iRowIndexStart <= iRowIndexEnd; ++iRowIndexStart)
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

		for (iColIndexStart; iColIndexStart <= iColIndexEnd; ++iColIndexStart)
		{
			if (iMatBoard[iRowIndex][iColIndexStart])
			{
				bIsWrongInput = true;
				break;
			}
		}

		if (!bIsWrongInput)
		{
			for (iColIndexStart; iColIndexStart <= iColIndexEnd; ++iColIndexStart)
			{
				iMatBoard[iRowIndex][iColIndexStart] = 1;
			}
		}
	}
}

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
							bIsWrongInput = false;
						}
					}
				}
			}
		}
	}
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