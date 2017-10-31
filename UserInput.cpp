#include <iostream>
#include <string>
using namespace std;

void writeInput(int iMatBoard[10][10], string sFirstPosition, string sSecondPosition)
{

}

void getPositions(int iMatBoard[10][10])
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
	while (sFirstPosition[0] < 65 || sFirstPosition[0] > 74)
	{
		cout << "Please enter valid coordinates letter" << endl;
		cin >> sFirstPosition >> sSecondPosition;
	}
	
	//Check if the second character is a number in valid range
	while (sFirstPosition[1] < 48 || sSecondPosition[1] > 57)
	{
		cout << "Please enter valid coordinates number" << endl;
		cin >> sFirstPosition >> sSecondPosition;
	}

	//Check if the coordinates are valid positions
	while (sFirstPosition[0] != sSecondPosition[0] &&
      		sFirstPosition[1] != sSecondPosition[1])
	{
		cout << "Please enter valid coordinates" << endl;
		cin >> sFirstPosition >> sSecondPosition;
	}

	writeInput(iMatBoard, sFirstPosition, sSecondPosition)
}

int main()
{
	int matrix[10][10];
	getPositions(matrix);
	return 0;
}