#include <iostream>
using namespace std;
char cMatMap[22][22] =
{   "####################",
    "#                  #",
    "#                  #",
    "#                  #",
    "#                  #",
    "#                  #",
    "#                  #",
    "#                  #",
    "#                  #",
    "#                  #",
    "#                  #",
    "#                  #",
    "#                  #",
    "#                  #",
    "#                  #",
    "#                  #",
    "#                  #",
    "#                  #",
    "#                  #",
    "#                  #",
    "#                  #",
    "####################",};

void displayMap( int &iArrCol,int &iArrRow, char cMatMap[22][22]){
    int iRowIndex,iColIndex;
    for (iColIndex = 0; iColIndex < iArrCol; iColIndex++)
        //iRowIndex = 0; iRowIndex < iArrRow; iRowIndex++ )
    {
        for(iRowIndex = 0; iRowIndex < iArrRow; iRowIndex++ )
        {
            cout<< cMatMap[iColIndex][iRowIndex]<<endl;
        }
        cout<<endl;
    }
}

int main(){
    int iHeight = 22, iWidth =22;
    
    displayMap(iHeight,iWidth,cMatMap);
    
    return 0;
}


