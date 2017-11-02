#include <iostream>
using namespace std;

char cMatMap[100][100] =
{   "################################################################################",
    "#                                                                              #",
    "#                                                                              #",
    "#                                                                              #",
    "#                                                                              #",
    "#         ****   ***   ****                                                    #",
    "#          ***   ***   ***                                                     #",
    "#          ***   ***   ***                                                     #",
    "#          ***   ***   ***                                                     #",
    "#           ***  ***   ***                                                     #",
    "#            *** ***  ***                                                      #",
    "#               *****                                                          #",
    "#                                                                              #",
    "#                                                                              #",
    "#                              PLAY GAME                                       #",
    "#                                                                              #",
    "#                             INSTRUCTIONS                                     #",
    "#                                                                              #",
    "#                                ABOUT                                         #",
    "#                                                                              #",
    "#                                                                              #",
    "################################################################################",};

void displayMap( int &iArrCol,int &iArrRow, char cMatMap[100][100]){
    int iRowIndex,iColIndex;
    for (iColIndex = 0; iColIndex < iArrCol; iColIndex++)
    {
        for(iRowIndex = 0; iRowIndex < iArrRow; iRowIndex++ )
        {
            cout<< cMatMap[iColIndex][iRowIndex];
        }
        cout<<endl;
    }
}

int main(){
    int iHeight = 100, iWidth =100;
    displayMap(iHeight,iWidth,cMatMap);
    
    return 0;
}

