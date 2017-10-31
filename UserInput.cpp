#include <iostream>
#include <string>
using namespace std;

void getPositions(bool bMatPlayerBoard[10][10])
{
	string sFirstPosition;
	string sSecondPosition;

	cin >> sFirstPosition >> sSecondPosition;

	//Check if the coordinates are two characters long
	while (sFirstPosition.length() > 2 || sSecondPosition.length() > 2)
	{
		cout << "Please enter valid coordinates" << endl;
		cin >> sFirstPosition >> sSecondPosition;
	}

	//Check if the first character is a letter in valid range
	while (sFirstPosition)
	
	//Check if the second character is a number in valid range
	while ()
	{

	}

	//Check if the coordinates are valid positions
	while (sFirstPosition[0] != sSecondPosition[0] ||
      		sFirstPosition[1] != sSecondPosition[1])
	{
		cout << "Please enter valid coordinates" << endl;
		cin >> sFirstPosition >> sSecondPosition;
	}

	char cFirstXCoordinate = sFirstPosition[0];
	char cSecondXCoordinate = sSecondPosition[0];

}