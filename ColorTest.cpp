#include <iostream>
#include <cstdio>
using namespace std;

#include <iostream>
using namespace std;

char cMatMap[53][81] =
{   "################################################################################",
    "#                                                                              #",
    "#                                                                              #",
    "#          ******   ******     ***     *****    **                             #",
    "#          **   **  **        ** **    **  **   **                             #",
    "#          ******   *****    *******   *****    **                             #",
    "#          **       **      **     **  ** **    **                             #",
    "#          **       ****** **       ** **   **  ******                         #",
    "#                                                                              #",
    "#                **   **      ***      *****    ****      ****    *****        #",
    "#                **   **     ** **     **  **   **  *    **  **   **  **       #",
    "#                *******    *******    ****     ******  **    **  *****        #",
    "#                **   **   **     **   ** **    **   *   **  **   ** **        #",
    "#                **   **  **       **  **   **  ******    ****    **  **       #",
    "#                                                                              #",
    "#                              PLAY GAME  (P)                                  #",
    "#                                                                              #",
    "#                             INSTRUCTIONS (I)                                 #",
    "#                                                                              #",
    "#                               ABOUT (A)                                      #",
    "#                                                                              #",
    "#                               EXIT  (E)                                      #",
    "#                                                                              #",
    "#                                                                              #",
    "#                                                                              #",
    "#                                                                              #",
    "#                                version 1.0                                   #",
    "#                                                                              #",
    "################################################################################",};
char cMatBoards[53][81] =
{   "################################################################################",
    "#                                                                              #",
    "#       NAME:                                                                  #",
    "#      A B C D E F G H I J                      A B C D E F G H I J            #",
    "#   1                                          1                               #",
    "#   2                                          2                               #",
    "#   3                                          3                               #",
    "#   4                                          4                               #",
    "#   5                                          5                               #",
    "#   6                                          6                               #",
    "#   7                                          7                               #",
    "#   8                                          8                               #",
    "#   9                                          9                               #",
    "#   10                                         10                              #",
    "#                                                                              #",
    "#                                                                              #",
    "#                                                                              #",
    "#                                                                              #",
    "#                                                                              #",
    "#                                                                              #",
    "#    Scoreboard:                                                               #",
    "#    Hits:                                                                     #",
    "#                                                                              #",
    "################################################################################",};

void displayMatrix( int &iArrCol,int &iArrRow, char cMatMap[53][81]){
    int iRowIndex,iColIndex;
    for (iColIndex = 0; iColIndex < iArrCol; iColIndex++)
    {
        cout<<"                               ";
        for(iRowIndex = 0; iRowIndex < iArrRow; iRowIndex++ )
        {
            printf("\x1b[31;47m %c \x1b[0m", cMatMap[iColIndex][iRowIndex]);
            
        }
        cout<<endl;
    }
}


int main(){
    int iHeight = 53, iWidth = 81;
    displayMatrix(iHeight,iWidth,cMatMap);
    displayMatrix(iHeight,iWidth,cMatBoards);
    return 0;
}