#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void writeInput(int iMatBoard[10][10], string sFirstPosition, string sSecondPosition, int iShipSize)
{

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
		cout << "Invalid coordinates. Please enter only two characters per coordinate" << endl;
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
			iDifference = abs(sFirstPosition[0] - sSecondPosition[0]) - 48 + 1; 
		}

		cout << iDifference << " " << iShipSize << endl;
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

int main()
{
	int matrix[10][10];
	getPositions(matrix, 5);
	return 0;
}