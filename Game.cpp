
/*
MAIN FILE
 
 Carlos Daniel Estrada Guerra       A01039919
 Erick Francisco González Martínez  A01039859
 
 BATTLESHIP_GAME
 version 1.0
*/

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include <iomanip>
#include <thread>
#include <chrono>
using namespace std;

using std::cout;
using std::flush;
using std::string;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

//Japanese ship names
const string sJapaneseCarrier = "Ryujo Carrier";
const string sJapaneseBattleship = "Nagato Battleship";
const string sJapaneseCruiser = "Furutaka Cruiser";
const string sJapaneseSubmarine = "Ro-51 Submarine";
const string sJapaneseDestroyer = "Kamikaze Destroyer";

//American ships names
const string sAmericanCarrier = "USS Princeton Carrier";
const string sAmericanBattleship = "USS Arizona Battleship";
const string sAmericanCruiser = "USS Minneapolis Cruiser";
const string sAmericanSubmarine = "USS Hawkbill Submarine";
const string sAmericanDestroyer = "USS Frankford Destroyer";


/*
-------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------
    GENERAL USE FUNCTIONS
-------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------
*/

/*
getMenuInput
Function to get the input in the menu function
Paramenters: none
Return: a char provided by the user
*/
char getMenuInput()
{
  char cInput;
  cout << "\x1b[37mEnter an option to continue --> ";
  cin >> cInput;
  cout << endl;
  return cInput;
}

/*  
cleanScreen
Function to clean up the screen of any element
Parameters: none
Retrurn: nothing
*/
void cleanScreen()
{
  for (int iCounter = 0; iCounter < 50; ++iCounter)
  {
    cout << endl;
  }
}
/*  
pressToContinue
Function that displays the enter to continue and ignore any input
Parameters: none
Return: nothing
*/
void pressToContinue()
{
  cout << "\x1b[36mPress Enter to continue...\x1b[37m";
  cin.clear();
  cin.ignore();
}
/*  
pressToContinue
Function that displays the enter to get back to the main menu and ignore any input
Parameters: none
Retunr: nothing
*/
void pressToReturnToMenu()
{
  cout << "\x1b[36mPress Enter to return to the Main Menu...\x1b[37m";
    cin.ignore();
}
/*  
showIntro
Function that 
Parameters: The milliseconds it wants to be slowed down 
Return: nothing
*/
void showIntro(unsigned int millis_per_char)
{
    string sMessage1 = "\x1b[37mPearl Harbor attack, (December 7, 1941), a surprise aerial attack \n";
  string sMessage2 = "on the U.S. naval base at Pearl Harbor, by the Japanese \n";
  string sMessage3 = "precipitated the entry of the United States into World War II. \n";
  string sMessage4 = "Now both countires shall face eachother in the sea to show \n";
  string sMessage5 = "who is the king of the pacific... \n";

  cleanScreen();

  for (const char c: sMessage1)
  {

    cout << c << flush;
    

    sleep_for(milliseconds(millis_per_char));
  }

  for (const char c: sMessage2)
  {

    cout << c << flush;
    

    sleep_for(milliseconds(millis_per_char));
  }

  for (const char c: sMessage3)
  {

    cout << c << flush;
    

    sleep_for(milliseconds(millis_per_char));
  }

  for (const char c: sMessage4)
  {

    cout << c << flush;
    

    sleep_for(milliseconds(millis_per_char));
  }

  for (const char c: sMessage5)
  {

    cout << c << flush;
    

    sleep_for(milliseconds(millis_per_char));
  }

  cout << endl << endl;

  cin.ignore();
  pressToContinue();
}
/*  
showMenu
Function that displays the main menu of the game
Parameters: none
Return: nothing
*/
void showMenu()
{
  cleanScreen();

  int iHeight = 30;
  int iWidth = 81;
  char cMatMenu[30][81] =
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
      "################################################################################",
  }  ;

  for (int iRowIndex = 0; iRowIndex < iHeight; ++iRowIndex)
  {
    cout << setw(10);

    for (int iColIndex = 0; iColIndex < iWidth; ++iColIndex)
    {
      if (iRowIndex > 2 && iRowIndex < 14)
      {
        if (iColIndex > 1 && iColIndex < 75)
        {
          cout << "\x1b[5;31m" << cMatMenu[iRowIndex][iColIndex];
        }
        else
        {
          cout << "\x1b[25;37m" << cMatMenu[iRowIndex][iColIndex];
        }
      }
      else
      {
        cout << "\x1b[25;37m" << cMatMenu[iRowIndex][iColIndex];  
      }
    }

    cout << endl;
  }
}
/*  
displayInstructions
Function that displays the instructions of the game
Parameters: none
Return: nothing
*/
void displayInstructions()
{
  cleanScreen();

  char cMatInstructions[37][81] = {
    "################################################################################",
    "#                                 Instructions                                 #",
    "#------------------------------------------------------------------------------#",
    "# Objective of the Game                                                        #",
    "#  -Sink all the ships from the opponent and change the course of history      #",
    "#                                                                              #",
    "# Prepare for Battle                                                           #",
    "#         1. Enter your name                                                   #",
    "#         2. Choose a side: Either Japan (J) or United States (U)              #",
    "#         3. Choose a difficulty                                               #",
    "#         4. Set up all your battleships in the board by entering the starting #",
    "#        and finishing coordinates of each ship. WATCH OUT FOR SPACES!         #",
    "#                                                                              #",
    "#  How to Fight for the Glory                                                  #",
    "#      **Check the legend within the game**                                    #",
    "#  1. Your SHOT!                                                               #",
    "#      -You call the shots. Enter a coordinate where you want to strike.       #",
    "#                                                                              #",
    "#   2. HIT or MISS--->Sink a boat                                              #",
    "#      -Each shot will be declared as a shot or a miss.                        #",
    "#      -In case that you have sank a boat a message will be displayed.         #",
    "#                                                                              #",
    "#  3. Wait for Opponent                                                        #",
    "#      -Press enter to continue the game                                       #",
    "#      -In case that the opponent has sunk a boat a message will be displayed  #",
    "#                                                                              #",
    "#  4. Be defeated or win the glory                                             #",
    "#                                                                              #",
    "#------------------------------------------------------------------------------#",
    "#                                                                              #",
    "#                                    ENJOY!                                    #",
    "#                                                                              #",
    "################################################################################",
  }  ;
  for (int iRowIndex = 0; iRowIndex < 37; ++iRowIndex)
  {
    cout << setw(10);
    
    for (int iColIndex = 0; iColIndex < 81; ++iColIndex)
    {
      
        cout << "\x1b[37m" << cMatInstructions[iRowIndex][iColIndex];
    
    }
    
    cout << endl;
  }

  cin.ignore();
  pressToReturnToMenu();
}
/*  
displayAbout
Function that displays the main information about the developers of the game
Parameters: none
Return: nothing
*/
void displayAbout()
{
  cleanScreen();

  char cMatAbout[37][81] = 
     {"################################################################################",
    "#                                   About                                      #",
    "#------------------------------------------------------------------------------#",
    "#  Developers:                                 -This game is (E) rated.        #",
    "#  -Carlos Estrada                             -One Player vs. Computer        #",
    "#  -Erick Gonzalez                             -(Soon) PvP                     #",
    "#  Special Mention:                                                            #",
    "#  -Javier Giese                                                               #",
    "#                                                                              #",
    "#                            IN COLLABORATION WITH                             #",
    "#                                _ _ _ _ _ _ _ _                               #",
    "#                              /                |                              #",
    "#                             |   ----    ----  |                              #",
    "#                             |  |       |____  |                              #",
    "#                             |  |     & |      |                              #",
    "#                             |   ----    ----  |                              #",
    "#                             |      GAMES      |                              #",
    "#                             |_ _ _ _ _ _ _ _ /                               #",
    "#                                                                              #",
    "#                                                                              #",
    "#                                                                              #",
    "#                                                                              #",
    "#**This game does not mean offense to any of the names and/or situations       #",
    "#  mentioned in the game.                                                      #",
    "#***The abuse of this product may cause health issues.                         #",
    "#****Remember this game is just for fun.                                       #",
    "#                                                                              #",
    "#------------------------------------------------------------------------------#",
    "#                                                                              #",
    "#                                    ENJOY!                                    #",
    "#                                                                              #",
    "################################################################################",
  }  ;
  for (int iRowIndex = 0; iRowIndex < 37; ++iRowIndex)
  {
      cout << setw(10);
    
    for (int iColIndex = 0; iColIndex < 81; ++iColIndex)
    {
      
      cout << "\x1b[37m" << cMatAbout[iRowIndex][iColIndex];
      
    }
    
    cout << endl;
  }

  cin.ignore();
  pressToReturnToMenu();
}
/*  
showHit
Function that displays in case that the player/computer hits the ship
Parameters: If the player/computer hits the ship
Return: nothing
*/
void showHit(bool bIsPlayer)
{
  cleanScreen();

  int iIndenting = 60;

  cout << "\x1b[31m";
  cout << setw(iIndenting) << "**   **   **   ******   ** " << endl;
  cout << setw(iIndenting) << "**   **   **   ******   ** " << endl;
  cout << setw(iIndenting) << "*******   **     **     ** " << endl;
  cout << setw(iIndenting) << "*******   **     **     ** " << endl;
  cout << setw(iIndenting) << "**   **   **     **        " << endl;
  cout << setw(iIndenting) << "**   **   **     **     ** " << endl;
  cout << "\x1b[37m";

  cout << endl << endl;

  if (bIsPlayer)
  {
    cout << setw(iIndenting + 7) << "Admiral, we've hit one of the enemy ships!" << endl;
    cin.ignore();
  }
  else
  {
    cout << setw(iIndenting + 9) << "Admiral, The enemy has hit one of your ships!" << endl;
  }

  for (int iCounter = 0; iCounter < 7; ++iCounter)
  {
    cout << endl;
  }


  pressToContinue();
}
/*  
showComputerTurn
Function that displays the sign that is the computer's turn
Parameters: none
Return: nothing
*/
void showComputerTurn()
{
  cleanScreen();

  int iIndenting = 75;

  cout << "\x1b[5;31m";
  cout << setw(iIndenting) << " ******   **   **   ******   **        **  **  **   ** " << endl;
  cout << setw(iIndenting) << " **       ***  **   **       ***      ***   ****    ** " << endl;
  cout << setw(iIndenting) << " ******   **** **   ******   ****    ****    **     ** " << endl;
  cout << setw(iIndenting) << " **       ** ****   **       ** **  ** **    **     ** " << endl;
  cout << setw(iIndenting) << " **       **  ***   **       **  ****  **    **        " << endl;
  cout << setw(iIndenting) << " ******   **   **   ******   **   **   **    **     ** " << endl;
  cout << "\x1b[25;37m";

  cout << endl << endl;

  cout << setw(iIndenting + 2) << "It's the enemy's turn to strike! Brace yourself for impact!" << endl;  

  for (int iCounter = 0; iCounter < 7; ++iCounter)
  {
    cout << endl;
  }

  pressToContinue();
}
/*  
showBegingGame
Function that displays the start of the fight once the setup is complete
Parameters:none
Return: nothing
*/
void showBeginGame()
{
  cleanScreen();

  int iIndenting = 70;

  cout << "\x1b[5;36m"; 
  cout << setw(iIndenting) << " ******   **      *****    **   **   ******   ** " << endl;
  cout << setw(iIndenting) << " **       **    **         **   **   ******   ** " << endl;
  cout << setw(iIndenting) << " ******   **   **          *******     **     ** " << endl;
  cout << setw(iIndenting) << " **       **   **   ****   *******     **     ** " << endl;
  cout << setw(iIndenting) << " **       **    **    **   **   **     **        " << endl;
  cout << setw(iIndenting) << " **       **      ****     **   **     **     ** " << endl;
  cout << "\x1b[25;37m";

  cout << endl << endl;

  cout << setw(iIndenting - 1) << "Let the battle begin! Show the enemy no mercy!" << endl << endl;
  cout << setw(iIndenting + 1) << "Remember, the objective of the game is to sink all" << endl;
  cout << setw(iIndenting - 3) <<"enemy ships in the least amount of turns" << endl;  

  for (int iCounter = 0; iCounter < 7; ++iCounter)
  {
    cout << endl;
  }

  cin.ignore();

  pressToContinue();
}
 /*  
showMiss
Function that displays in case that the player/computer misses the ship
Parameters: If the player/computer misses the ship
Return: nothing
*/ 
void showMiss(bool bIsPlayer)
{
  cleanScreen();

  int iIndenting = 65;

  cout << "\x1b[36m";
  cout << setw(iIndenting) << "**        **   **    *****    *****   ** " << endl;
  cout << setw(iIndenting) << "***      ***   **   **       **       ** " << endl;
  cout << setw(iIndenting) << "****    ****   **   ****     ****     ** " << endl;
  cout << setw(iIndenting) << "** **  ** **   **     ****     ****   ** " << endl;
  cout << setw(iIndenting) << "**  ****  **   **       **       **      " << endl;
  cout << setw(iIndenting) << "**   **   **   **    *****    *****   ** " << endl;
  cout << "\x1b[37m";

  cout << endl << endl;

  if (bIsPlayer)
  {
    cout << setw(iIndenting + 0) << "Admiral, we've miss the shot, a tragedy!" << endl;
    cin.ignore();
  }
  else
  {
    cout << setw(iIndenting + 19) << "Admiral, The enemy has missed the shot, but our luck might run out soon!" << endl;
  }

  for (int iCounter = 0; iCounter < 7; ++iCounter)
  {
    cout << endl;
  }

  pressToContinue();

}
 /*  
showSank
Function that displays in case that the player/computer has sunk the ship
Parameters: If the player/computerhas hit the ship and the string of the ship if it has been sunk
Return: nothing
*/ 
void showSank(bool bIsPlayer, string sShip)
{
  cleanScreen();

  int iIndenting = 75;

  cout << "\x1b[31m";
  cout << setw(iIndenting) << "  *****   **    **   **   **    **  **   ** " << endl;
  cout << setw(iIndenting) << " **       **    **   ***  **    ** **    ** " << endl;
  cout << setw(iIndenting) << " ****     **    **   **** **    ***      ** " << endl;
  cout << setw(iIndenting) << "   ****   **    **   ** ****    ****     ** " << endl;
  cout << setw(iIndenting) << "     **   **    **   **  ***    ** **       " << endl;
  cout << setw(iIndenting) << "  *****     ****     **   **    **  **   ** " << endl;
  cout << "\x1b[37m";

  cout << endl << endl;

  if (bIsPlayer)
  {
    cout << setw(iIndenting - 21) << "You have sank the enemy " << "\x1b[36m" << sShip << "\x1b[37m" << "!";
  }
  else
  {
    cout << setw(iIndenting - 21) << "The enemy has sank our " << "\x1b[36m" << sShip << "\x1b[37m" << "! A black day!";
  }

  for (int iCounter = 0; iCounter < 7; ++iCounter)
  {
    cout << endl;
  }

  pressToContinue();
}
 /*  
showResult
Function that displays the final status of the user
Parameters: The name of the user, the team it chose, whether it is a winner or not, and the total score of the game
Return: nothing
*/
void showResult(string sPlayerName, char cTeam, bool bIsWinner, int iScore)
{
  cleanScreen();

  int iIndenting = 70;

  if (bIsWinner)
  {
    cout << "\x1b[36m";
    cout << setw(iIndenting) << " **  **      ****      **    **  " << endl;
    cout << setw(iIndenting) << "  ****     **    **    **    **  " << endl;
    cout << setw(iIndenting) << "   **     **      **   **    **  " << endl;
    cout << setw(iIndenting) << "   **     **      **   **    **  " << endl;
    cout << setw(iIndenting) << "   **      **    **     **  **   " << endl;
    cout << setw(iIndenting) << "   **        ****        ****    " << endl;

    cout << endl << endl;

    cout << setw(iIndenting + 6) << " **   **   **      ****      **   **   ** " << endl;
    cout << setw(iIndenting + 6) << " **  ****  **    **    **    ***  **   ** " << endl;
    cout << setw(iIndenting + 6) << " ** **  ** **   **      **   **** **   ** " << endl;
    cout << setw(iIndenting + 6) << " ****    ****   **      **   ** ****   ** " << endl;
    cout << setw(iIndenting + 6) << " ***      ***    **    **    **  ***      " << endl;
    cout << setw(iIndenting + 6) << " **        **      ****      **   **   ** " << endl;
    cout << "\x1b[37m";

    cout << endl << endl;

    if (cTeam == 'J' || cTeam == 'j')
    {
      cout << setw(iIndenting - 28) << "Admiral " << sPlayerName << "-San, " << "we have defeated the enemy! " << endl;
      cout << setw(iIndenting + 5) << "Japan shall rule the seas for eternity!" << endl;
    }
    else
    {
      cout << setw(iIndenting - 28) << "Admiral " << sPlayerName << ", we have defeated the enemy! " << endl;
      cout << setw(iIndenting + 17) << "The United States shall rule the Pacific for centuries to come!" << endl;
    }
  }
  else
  {
    cout << "\x1b[36m";
    cout << setw(iIndenting) << " **  **      ****      **    **  " << endl;
    cout << setw(iIndenting) << "  ****     **    **    **    **  " << endl;
    cout << setw(iIndenting) << "   **     **      **   **    **  " << endl;
    cout << setw(iIndenting) << "   **     **      **   **    **  " << endl;
    cout << setw(iIndenting) << "   **      **    **     **  **   " << endl;
    cout << setw(iIndenting) << "   **        ****        ****    " << endl;

    cout << endl << endl;

    cout << setw(iIndenting + 6) << " **         ****       *****   ******   **" << endl;
    cout << setw(iIndenting + 6) << " **       **    **    **       ******   **" << endl;
    cout << setw(iIndenting + 6) << " **      **      **   ****       **     **" << endl;
    cout << setw(iIndenting + 6) << " **      **      **    ****      **     **" << endl;
    cout << setw(iIndenting + 6) << " **       **    **       **      **       " << endl;
    cout << setw(iIndenting + 6) << " *****      ****      *****      **     **" << endl;
    cout << "\x1b[37m";

    cout << endl << endl;

    if (cTeam == 'J' || cTeam == 'j')
    {
      cout << setw(iIndenting - 28) << "Admiral " << sPlayerName << "-San, " << "the enemy is victorious! " << endl;
      cout << setw(iIndenting + 10) << "Dishonor for our families and generations to come!" << endl;
    }
    else
    {
      cout << setw(iIndenting - 28  ) << "Admiral " << sPlayerName << ", the enemy has defeated us! " << endl;
      cout << setw(iIndenting + 6) << "The founding fathers shall be ashamed of us!" << endl;
    }
  }

  cout << setw(iIndenting - 33) << "\x1b[36mYou had a score of: " << iScore;

  for (int iCounter = 0; iCounter < 7; ++iCounter)
  {
    cout << endl;
  }

  pressToReturnToMenu();
}

 /*  
showComputerThinking
Function that displays the status of the game while the computer is "thinking."
Parameters: none
Return: nothing
*/ 
void showComputerThinking()
{
  cout << setw(20) << "THE ENEMY IS THINKING THEIR NEXT MOVE..." << endl;

  for (int iCounter = 0; iCounter < 10; ++iCounter)
  {
    cout << endl;
  }
}


/*
-------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------
    SETUP FUNCTIONS
-------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------
*/

/*
getPlayerName
Function to let the user input a name to use
Paramenters: none
Return: a string with the name
*/
string getPlayerName(char cTeam)
{
  string sName;
  cleanScreen();

  cout << "\x1b[36m";
  cout << setw(70) << "**   **        **      ****     ****  ******    ******  " << endl;
  cout << setw(70) << "***  **       ****     *****   *****  **            **  " << endl;
  cout << setw(70) << "** * **      **  **    **  ** **  **  ******        **  " << endl;
  cout << setw(70) << "**  ***     ********   **   ****  **  **        ******  " << endl;
  cout << setw(70) << "**   **    **      **  **         **  **        **      " << endl;
  cout << setw(70) << "**   **   **        ** **         **  ******    *       " << endl;
  cout << "\x1b[37m";

  for (int iCounter = 0; iCounter < 7; ++iCounter)
  {
    cout << endl;
  }

  if (cTeam == 'j' || cTeam == 'J')
  {
    cout << "Admiral, I am your senior advisor Takuya-San, the Americans are gettig ready for battle and so should we," << endl << endl;
  }
  else
  {
    cout << "Admiral, I am your senior advisor Thomas Charles, the japanese are gettig ready for battle and so should we," << endl << endl;
  }

  cin.ignore();
  cout << "but first, what is your name? --> ";

  getline(cin, sName);

  cout << endl;  

  return sName;
}

/*
chooseTeam
Function to let the user choose a team through a char
Paramenters: none
Return: a char representing a team
*/
char chooseTeam()
{
  char cTeam;

  cout << "Choose your side!" << endl;
  cout << "Do you want to play as Japan (J) or the United States (U)?" << endl;
  cin >> cTeam;

  while (cTeam != 'J' && cTeam != 'U' && cTeam != 'j' && cTeam != 'u')
  {
    cout << "\x1b[31mInvalid team, please enter 'J' for Japan or 'U' for the USA\x1b[37m" << endl;
    cin >> cTeam;
  }

  return cTeam;
}

int getDifficulty()
{
  char cDifficulty;
  int iDifficulty;

  cleanScreen();

  cout << "Choose your game difficulty! Easy (E) or Normal (N):" << endl << "--> ";
  cin >> cDifficulty;

  while (cDifficulty != 'N' && cDifficulty != 'n' && cDifficulty != 'e' && cDifficulty != 'E')
  {
    cout << "\x1b[31mInvalid letter, please enter N for normal or E for easy\x1b[37m" << endl;
    cin >> cDifficulty;
  }

  if (cDifficulty == 'N' || cDifficulty == 'n')
  {
    iDifficulty = 2;
  }
  else
  {
    iDifficulty = 1;
  }

  cleanScreen();

  return iDifficulty;
}


/*
eraseBoard
Function to fill a board with zeroes (empty board)
Paramenters: a Matrix board
Return: nothing
*/
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

/*
printSetupBoard
Function to print the player or computer board in the console
Parameters: The board to print
Return: nothing
*/
void printSetupBoard(int iMatBoard[10][10])
{
  int iIndenting = 7;
  cout << setw(33+iIndenting) << "\x1b[37mYOUR BOARD" << endl << endl;
  cout << setw(41+iIndenting) <<"A   B   C   D   E   F   G   H   I   J" << endl;
  cout << setw(43+iIndenting) << "_______________________________________ " << endl;

  for (int iRowIndex = 0; iRowIndex < 10; ++iRowIndex)
  {
    cout << setw(43+iIndenting) << "|   |   |   |   |   |   |   |   |   |   |" << endl;
    cout << setw(1+iIndenting) << iRowIndex << " ";

    for (int iColIndex = 0; iColIndex < 10; ++iColIndex)
    {
      if (iMatBoard[iRowIndex][iColIndex])
      {
        cout << "|\x1b[32m O \x1b[37m";
      }
      else
      {
        cout << "|\x1b[34m . \x1b[37m";
      }
    }
    cout << "|" << endl;
    cout << setw(43+iIndenting) << "|___|___|___|___|___|___|___|___|___|___|" << endl;    
  }
  cout << endl << endl;
}


/*
writeUserInput
Function to write the ship position on the board
Parameters: The board, a boolean to validate the position, the first position, and the second position, and an array to store the location
Return: nothing
*/
void writeUserInput(int iMatBoard[10][10], bool &bIsWrongInput, string sFirstPosition, string sSecondPosition, int iArrShipPosition[],
        int iShipSize)
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
        //First value in iArrShipPosition indicates orientation, 1 means horizontal, 0 means vertical
    iArrShipPosition[0] = 0;

    int iColIndex = iFirstLetterCoordinate;

    //Second value in iArrShipPosition indicates the column index
    iArrShipPosition[1] = iColIndex;

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

    int iLoopInitiator = iRowIndexStart;

    for (iRowIndexStart; iRowIndexStart <= iRowIndexEnd; ++iRowIndexStart)
    {
      if (iMatBoard[iRowIndexStart][iColIndex])
      {  
        cout << "\x1b[31mInvalid coordinates. Space already occupied by another ship\x1b[37m" << endl;
        bIsWrongInput = true;
        break;
      }
    }

    if (!bIsWrongInput)
    {
      int iCounter = 2;
      for (iRowIndexStart = iLoopInitiator; iRowIndexStart <= iRowIndexEnd; ++iRowIndexStart, ++iCounter)
      {
        iArrShipPosition[iCounter] = iRowIndexStart;
        iMatBoard[iRowIndexStart][iColIndex] = 1;
      }
    }
  }

  //For horizontal positioning
  else
  {
    //First value in iArrShipPosition indicates orientation, 1 means horizontal, 0 means vertical
    iArrShipPosition[0] = 1;

    int iRowIndex = iFirstNumberCoordinate;

    //Second value in iArrShipPosition indicates the row index
    iArrShipPosition[1] = iRowIndex;

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

    int iLoopInitiator = iColIndexStart;

    for (iColIndexStart; iColIndexStart <= iColIndexEnd; ++iColIndexStart)
    {
      if (iMatBoard[iRowIndex][iColIndexStart])
      {
        cout << "\x1b[31mInvalid coordinates. Space already occupied by another ship\x1b[37m" << endl;
        bIsWrongInput = true;
        break;
      }
    }

    if (!bIsWrongInput)
    {
      int iCounter = 2;  
      for (iColIndexStart = iLoopInitiator; iColIndexStart <= iColIndexEnd; ++iColIndexStart, ++iCounter)
      {
        iArrShipPosition[iCounter] = iColIndexStart;
        iMatBoard[iRowIndex][iColIndexStart] = 1;
      }
    }
  }
}

/*
readUserPositions
Function to let the user input coordinates
Parameters: The player board, the size of the ship to input, and an array storing the location
Return: nothing
*/
void readUserPositions(int iMatBoard[10][10], int iShipSize, int iArrShipPosition[])
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
      cout << "\x1b[31mInvalid coordinates. Please enter two characters per coordinate\x1b[37m" << endl;
    }
    else
    {
      //Check if the first character is a letter in valid range
      if (sFirstPosition[0] < 65 || sFirstPosition[0] > 74)
      {
        cout << "\x1b[31mInvalid coordinates. Please enter letters from A to J capitalized\x1b[37m" << endl;
      }
      else
      {
        //Check if the second character is a number in valid range
        if (sFirstPosition[1] < 48 || sSecondPosition[1] > 57)
        {
          cout << "\x1b[31mInvalid coordinates. Please enter a digit as second parameter\x1b[37m" << endl;
        }
        else
        {
          //Check if the coordinates are valid positions
          if (sFirstPosition[0] != sSecondPosition[0] &&
                   sFirstPosition[1] != sSecondPosition[1])
          {
            cout << "\x1b[31mInvalid coordinates. Please place ships horizontally or vertically\x1b[37m" << endl;
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
              cout << "\x1b[31mInvalid coordinates. Please make sure the coordinates are for a ship of size ";
              cout << iShipSize << "\x1b[37m" <<endl;
            }
            else
            {
              writeUserInput(iMatBoard, bIsWrongInput, sFirstPosition, sSecondPosition, iArrShipPosition, iShipSize);
            }
          }
        }
      }
    }
  }
}

/*
getPlayerPositions
Function to ask the user for the ship positions 
Parameters: The Player board, the name, the char of the team, and an array for each ship to store location
Retrun nothing
*/
void getPlayerPositions(int iMatPlayerBoard[10][10], string sPlayerName, char cTeam, int iArrPlayerCarrierPosition[7],
                        int iArrPlayerBattleshipPosition[6], int iArrPlayerCruiserPosition[5],
               int iArrPlayerSubmarinePosition[5], int iArrPlayerDestroyerPosition[4])
{
  int iShipSize;

  if (cTeam == 'J' || cTeam == 'j')
  {
    printSetupBoard(iMatPlayerBoard);

    //Carrier
    iShipSize = 5;

    cout << "Admiral " << sPlayerName << "-San, enter the starting and ending coordinates of your "  << "\x1b[36m" << sJapaneseCarrier;
    cout << "\x1b[37m" << " (" << iShipSize << " spaces)" << endl; 
      cout << "Example : A1 E1 (Separated by spaces)" << endl << "-->";

    readUserPositions(iMatPlayerBoard, iShipSize, iArrPlayerCarrierPosition);

    cleanScreen();

    printSetupBoard(iMatPlayerBoard);

    //Battleship
    iShipSize = 4;

    cout << "Admiral " << sPlayerName << "-San, enter the starting and ending coordinates of your "  << "\x1b[36m" << sJapaneseBattleship;
    cout << "\x1b[37m" << " (" << iShipSize << " spaces)" << endl;
    cout << "Example : A1 E1 (Separated by spaces)" << endl << "-->";

    readUserPositions(iMatPlayerBoard, iShipSize, iArrPlayerBattleshipPosition);  

    cleanScreen();

    printSetupBoard(iMatPlayerBoard);

    //Cruiser
    iShipSize = 3;

    cout << "Admiral " << sPlayerName << "-San, enter the starting and ending coordinates of your "  << "\x1b[36m" << sJapaneseCruiser;
    cout << "\x1b[37m" << " (" << iShipSize << " spaces)" << endl;
    cout << "Example : A1 E1 (Separated by spaces)" << endl << "-->";

    readUserPositions(iMatPlayerBoard, iShipSize, iArrPlayerCruiserPosition);

    cleanScreen();

    printSetupBoard(iMatPlayerBoard);

    //Submarine
    cout << "Admiral " << sPlayerName << "-San, enter the starting and ending coordinates of your "  << "\x1b[36m" << sJapaneseSubmarine;
    cout << "\x1b[37m" << " (" << iShipSize << " spaces)" << endl;
    cout << "Example : A1 E1 (Separated by spaces)" << endl << "-->";

    readUserPositions(iMatPlayerBoard, iShipSize, iArrPlayerSubmarinePosition);

    cleanScreen();

    printSetupBoard(iMatPlayerBoard);

    //Destroyer
    int iShipSize = 2;

    cout << "Admiral " << sPlayerName << "-San, enter the starting and ending coordinates of your "  << "\x1b[36m" << sJapaneseDestroyer;
    cout << "\x1b[37m" << " (" << iShipSize << " spaces)" << endl;
     cout << "Example : A1 E1 (Separated by spaces)" << endl << "-->";

    readUserPositions(iMatPlayerBoard, iShipSize, iArrPlayerDestroyerPosition);

    cleanScreen();

    printSetupBoard(iMatPlayerBoard);

  }
  else
  {
    printSetupBoard(iMatPlayerBoard);

    //Carrier
    iShipSize = 5;

    cout << "Admiral " << sPlayerName << ", enter the starting and ending coordinates of your " << "\x1b[36m" << sAmericanCarrier;
    cout << "\x1b[37m" << " (" << iShipSize << " spaces)" << endl;
    cout << "Example : A1 E1 (Separated by spaces)" << endl << "-->";

    readUserPositions(iMatPlayerBoard, iShipSize, iArrPlayerCarrierPosition);

    cleanScreen();

    printSetupBoard(iMatPlayerBoard);

    //Battleship
    iShipSize = 4;

    cout << "Admiral " << sPlayerName << ", enter the starting and ending coordinates of your " << "\x1b[36m" << sAmericanBattleship;
    cout << "\x1b[37m" << " (" << iShipSize << " spaces)" << endl;
    cout << "Example : A1 E1 (Separated by spaces)" << endl << "-->";

    readUserPositions(iMatPlayerBoard, iShipSize, iArrPlayerBattleshipPosition);

    cleanScreen();

    printSetupBoard(iMatPlayerBoard);

    //Cruiser
    iShipSize = 3;

    cout << "Admiral " << sPlayerName << ", enter the starting and ending coordinates of your "  << "\x1b[36m" << sAmericanCruiser;
    cout << "\x1b[37m" << " (" << iShipSize << " spaces)" << endl;
    cout << "Example : A1 E1 (Separated by spaces)" << endl << "-->";

    readUserPositions(iMatPlayerBoard, iShipSize, iArrPlayerCruiserPosition);

    cleanScreen();

    printSetupBoard(iMatPlayerBoard);

    //Submarine
    cout << "Admiral " << sPlayerName << ", enter the starting and ending coordinates of your "  << "\x1b[36m" << sAmericanSubmarine;
    cout << "\x1b[37m" << " (" << iShipSize << " spaces)" << endl;
    cout << "Example : A1 E1 (Separated by spaces)" << endl << "-->";

    readUserPositions(iMatPlayerBoard, iShipSize, iArrPlayerSubmarinePosition);

    cleanScreen();

    printSetupBoard(iMatPlayerBoard);

    //Destroyer
    int iShipSize = 2;

    cout << "Admiral " << sPlayerName << ", enter the starting and ending coordinates of your "  << "\x1b[36m" << sAmericanDestroyer;
    cout << "\x1b[37m" << " (" << iShipSize << " spaces)" << endl;
    cout << "Example : A1 E1 (Separated by spaces)" << endl << "-->";

    readUserPositions(iMatPlayerBoard, iShipSize, iArrPlayerDestroyerPosition);

    cleanScreen();

    printSetupBoard(iMatPlayerBoard);

  }
}

/*
writeComputerInput
Function to write the ship position on the board given random generated data
Parameters: The board, a boolean to validate the position, and the array with the position
Return: nothing
*/
void writeComputerInput(int iMatBoard[10][10], int iArrShipPosition[], int iShipSize, bool &bIsOverlapped)
{
  bIsOverlapped = false;

  //Horizontal positioning
  if (iArrShipPosition[0])
  {
    int iRowIndex = iArrShipPosition[1];

    for (int iColIndex = iArrShipPosition[2]; iColIndex <= iArrShipPosition[iShipSize+1]; ++iColIndex)
    {
      if (iMatBoard[iRowIndex][iColIndex])
      {
        bIsOverlapped = true;
        break;
      }
    }

    if (!bIsOverlapped)
    {
      for (int iColIndex = iArrShipPosition[2]; iColIndex <= iArrShipPosition[iShipSize+1]; ++iColIndex)
      {
        iMatBoard[iRowIndex][iColIndex] = 1;
      }
    }
  }

  //Vertical Positioning
  else
  {
    int iColIndex = iArrShipPosition[1];

    for (int iRowIndex = iArrShipPosition[2]; iRowIndex <= iArrShipPosition[iShipSize+1]; ++iRowIndex)
    {
      if (iMatBoard[iRowIndex][iColIndex])
      {
        bIsOverlapped = true;
        break;
      }
    }

    if (!bIsOverlapped)
    {
      for (int iRowIndex = iArrShipPosition[2]; iRowIndex <= iArrShipPosition[iShipSize+1]; ++iRowIndex)
      {
        iMatBoard[iRowIndex][iColIndex] = 1;
      }
    }
  }
}

/*
writeComputerInput
Function to generate a random ship position, validate it, and to write it in the board
Parameters: The board, the array with the position, and the ship size
Return: nothing
*/
void generateRandomPosition(int iMatBoard[10][10], int iArrShipPosition[], int iShipSize)
{
  srand(time(NULL));

  bool bIsOverlapped = true;

  while(bIsOverlapped)
  {
    iArrShipPosition[0] = rand() % 2;

    iArrShipPosition[1] = rand() % 10;

    iArrShipPosition[2] = rand() % (10-iShipSize);

    int iExternalCounter = 1;

    for (int iCounter = 3; iCounter < iShipSize + 2 ; ++iCounter)
    {
      iArrShipPosition[iCounter] = iArrShipPosition[2] + iExternalCounter++;
    }

    writeComputerInput(iMatBoard, iArrShipPosition, iShipSize, bIsOverlapped);
  }
  
}


/*
getComputerPositions
Function to generate a random board for the computer
Parameters: The board, and a set of arrays for the ship positions
Return: nothing
*/
void getComputerPositions(int iMatBoard[10][10], int iArrComputerCarrierPosition[], int iArrComputerBattleshipPosition[],
                     int iArrComputerCruiserPosition[], int iArrComputerSubmarinePosition[], int iArrComputerDestroyerPosition[])
{
  //Computer Carrier
  int iShipSize = 5;
  generateRandomPosition(iMatBoard, iArrComputerCarrierPosition, iShipSize);

  //Computer Battleship
  iShipSize = 4;

  generateRandomPosition(iMatBoard, iArrComputerBattleshipPosition, iShipSize);

  //Computer Cruiser
  iShipSize = 3;

  generateRandomPosition(iMatBoard, iArrComputerCruiserPosition, iShipSize);

  //Computer Submarine
  iShipSize = 3;

  generateRandomPosition(iMatBoard, iArrComputerSubmarinePosition, iShipSize);

  //Computer Destroyer
  iShipSize = 2;

  generateRandomPosition(iMatBoard, iArrComputerDestroyerPosition, iShipSize);
}

/*
setupGame
Function to set the boards and ships for a new game
Parameters: Player and computer boards, the player name, the team, a set of arrays to store player ship locations
and a set of arrays to store computer ship locations
Return: nothing
*/
void setupGame(int iMatPlayerBoard[10][10], int iMatComputerBoard[10][10], string &sPlayerName, char &cTeam,
               int iArrPlayerCarrierPosition[7], int iArrPlayerBattleshipPosition[6], int iArrPlayerCruiserPosition[5],
         int iArrPlayerSubmarinePosition[5], int iArrPlayerDestroyerPosition[4], int iArrComputerCarrierPosition[7],
         int iArrComputerBattleshipPosition[6], int iArrComputerCruiserPosition[5], int iArrComputerSubmarinePosition[5],
         int iArrComputerDestroyerPosition[4], int &iDifficulty)  
{
  eraseBoard(iMatPlayerBoard);
  eraseBoard(iMatComputerBoard);

  iDifficulty = getDifficulty();

  cleanScreen();

  cTeam = chooseTeam();

  cleanScreen();

  sPlayerName = getPlayerName(cTeam);

  cleanScreen();

  getPlayerPositions(iMatPlayerBoard, sPlayerName, cTeam, iArrPlayerCarrierPosition, iArrPlayerBattleshipPosition,
                 iArrPlayerCruiserPosition, iArrPlayerSubmarinePosition, iArrPlayerDestroyerPosition);

  getComputerPositions(iMatComputerBoard, iArrComputerCarrierPosition, iArrComputerBattleshipPosition, iArrComputerCruiserPosition,
             iArrComputerSubmarinePosition, iArrComputerDestroyerPosition);
}

/*
-------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------
    RUNGAME FUNCTIONS
-------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------
*/

/*
printRunningBoard
Function that displays the board of both, the player and the computer, 
Parameters: The users boards with the position of the ship, the computer board without the ships and the socre that the user has. It is constantly refreshing.
Return: nothing
*/
void printRunningBoard(int iMatPlayerBoard[10][10], int iMatComputerBoard[10][10], int iScore)
{
  cleanScreen();

  cout << "           Legend: \x1b[34m . \x1b[37m = Water |\x1b[32m O \x1b[37m = Your ships |\x1b[31m X \x1b[37m= Part of ship sunken ";  
  cout << "|\x1b[31m # \x1b[37m = Ship sunken |\x1b[37m @ \x1b[37m = Missed Shot" << endl << endl; 
  cout << "\x1b[37m                           YOUR BOARD                                                  ENEMY BOARD" << endl << endl;
  cout << "              A   B   C   D   E   F   G   H   I   J                      A   B   C   D   E   F   G   H   I   J " << endl;
  cout << "             _______________________________________                    _______________________________________" << endl;

  for (int iRowIndex = 0; iRowIndex < 10; ++iRowIndex)
  {
    cout << "            |   |   |   |   |   |   |   |   |   |   |                  |   |   |   |   |   |   |   |   |   |   |" << endl;
    cout << "          " << iRowIndex << " ";

      for (int iColIndex = 0; iColIndex < 10; ++iColIndex)
      {
        if (iMatPlayerBoard[iRowIndex][iColIndex] == 1)
        {
          cout << "|\x1b[32m O \x1b[37m";
        }
        else
        {
          if (iMatPlayerBoard[iRowIndex][iColIndex] == 2)
          {
            cout << "|\x1b[31m X \x1b[37m";
          }
          else
          {
            if (iMatPlayerBoard[iRowIndex][iColIndex] == 4)
            {
              cout << "|\x1b[31m # \x1b[37m";
            }
            else
            {
              if (iMatPlayerBoard[iRowIndex][iColIndex] == 3)
              {
                cout << "|\x1b[37m @ \x1b[37m";          
              }
              else
              {
                cout << "|\x1b[34m . \x1b[37m";
              }
            }
          }
        }
      }
    cout << "|" << "                " << iRowIndex << " ";

    for (int iColIndex = 0; iColIndex < 10; ++iColIndex)
    {
      if (iMatComputerBoard[iRowIndex][iColIndex] == 1)
      {
        cout << "|\x1b[34m . \x1b[37m";
      }
      else
      {
        if (iMatComputerBoard[iRowIndex][iColIndex] == 2)
        {
          cout << "|\x1b[31m X \x1b[37m";
        }
        else
        {
          if (iMatComputerBoard[iRowIndex][iColIndex] == 4)
          {
            cout << "|\x1b[31m # \x1b[37m";
          }
          else
          {
            if (iMatComputerBoard[iRowIndex][iColIndex] == 3)
            {
              cout << "|\x1b[37m @ \x1b[37m";          
            }
            else
            {
              cout << "|\x1b[34m . \x1b[37m";
            }
          }
        }
      }
    }
    cout << "|" << endl;

    cout << "            |___|___|___|___|___|___|___|___|___|___|                  |___|___|___|___|___|___|___|___|___|___|" << endl;    
  }
  cout << "\x1b[37m" << endl << endl;
  cout << setw(68) << "\x1b[36mScore: " << iScore << "\x1b[37m" << endl << endl;
}

/*
checkIfWinner
Function that checks every turn if there is a winner in the game
Parameters: Receives the board and may stop the game if there is a winner.
Return: Usually false until there is a winner which return true
*/
bool checkIfWinner(int iMatBoard[10][10], bool &bGameIsRunning)
{
  bool bIsWinner = true;

  for (int iRowIndex = 0; iRowIndex < 10; ++iRowIndex)
  {
    for (int iColIndex = 0; iColIndex < 10; ++iColIndex)
    {
      if (iMatBoard[iRowIndex][iColIndex] == 1)
      {
        bIsWinner = false;
      }
    }
  }

  if (bIsWinner)
  {
    bGameIsRunning = false;
  }

  return bIsWinner;
}

/*
checkComputerIndividualShip
Function that check the placement of any ship of the computer
Parameters: The board of the computer, the array with the position of the ship, the ship size and the team of the computer
Return: nothing
*/
void checkComputerIndividualShip(int iMatComputerBoard[10][10], int iArrShipPosition[], int iShipSize, char cTeam, int iCounter)
{
  bool bIsSunken = true;
  string sArrShips[10] = {sAmericanCarrier, sJapaneseCarrier, sAmericanBattleship, sJapaneseBattleship, sAmericanCruiser,
              sJapaneseCruiser, sAmericanSubmarine, sJapaneseSubmarine, sAmericanDestroyer, sJapaneseDestroyer};

  //Check for horizontal positioning
  if (iArrShipPosition[0])
  {
    int iRowIndex = iArrShipPosition[1];

    for (int iColIndex = iArrShipPosition[2]; iColIndex <= iArrShipPosition[iShipSize + 1]; ++iColIndex)
    {
      if (iMatComputerBoard[iRowIndex][iColIndex] != 2)
      {
        bIsSunken = false;
      }
    }

    if (bIsSunken)
    {

      if (cTeam == 'J' || cTeam == 'j')
      {
        showSank(1, sArrShips[iCounter]);
      }
      else
      {
        showSank(1, sArrShips[iCounter + 1]);
      }

      for (int iColIndex = iArrShipPosition[2]; iColIndex <= iArrShipPosition[iShipSize + 1]; ++iColIndex)
      {
        iMatComputerBoard[iRowIndex][iColIndex] = 4;
      }
    }
  }

  //Check for vertical positioning
  else
  {
    int iColIndex = iArrShipPosition[1];

    for (int iRowIndex = iArrShipPosition[2]; iRowIndex <= iArrShipPosition[iShipSize + 1]; ++iRowIndex)
    {
      if (iMatComputerBoard[iRowIndex][iColIndex] != 2)
      {
        bIsSunken = false;
      }
    }

    if (bIsSunken)
    {
      if (cTeam == 'J' || cTeam == 'j')
      {
        showSank(1, sArrShips[iCounter]);
      }
      else
      {
        showSank(1, sArrShips[iCounter + 1]);
      }

      for (int iRowIndex = iArrShipPosition[2]; iRowIndex <= iArrShipPosition[iShipSize + 1]; ++iRowIndex)
      {
        iMatComputerBoard[iRowIndex][iColIndex] = 4;
      }
    }
  }
}

/*
checkComputerShips
Function that check the status of ships of the computer
Parameters: The board of the computer, the array with the board of the computer,the position of all the ships, the ship size and the team of the computer.
Return: nothing
*/
void checkComputerShips(int iMatComputerBoard[10][10], char cTeam, int iArrComputerCarrierPosition[], int iArrComputerBattleshipPosition[], 
                int iArrComputerCruiserPosition[], int iArrComputerSubmarinePosition[], int iArrComputerDestroyerPosition[])
{
  int iShipSize;
  int iCounter = 0;

  //Check Carrier status
  iShipSize = 5;
  checkComputerIndividualShip(iMatComputerBoard, iArrComputerCarrierPosition, iShipSize, cTeam, iCounter);

  iCounter += 2;

  //Check Battleship status
  iShipSize = 4;
  checkComputerIndividualShip(iMatComputerBoard, iArrComputerBattleshipPosition, iShipSize, cTeam, iCounter);

  iCounter += 2;

  //Check Cruiser status
  iShipSize = 3;
  checkComputerIndividualShip(iMatComputerBoard, iArrComputerCruiserPosition, iShipSize, cTeam, iCounter);

  iCounter += 2;

  //Check Submarine status
  iShipSize = 3;
  checkComputerIndividualShip(iMatComputerBoard, iArrComputerSubmarinePosition, iShipSize, cTeam, iCounter);

  iCounter += 2;

  //Check Destroyer status
  iShipSize = 2;
  checkComputerIndividualShip(iMatComputerBoard, iArrComputerDestroyerPosition, iShipSize, cTeam, iCounter);

}

/*
playerExecuteShot
Function that check the status of ships of the computer
Parameters: The board of the computer, the x and y coordinate of the missile, and check if the hit is a ship or not
*/
void playerExecuteShot(int iMatComputerBoard[10][10], int iXCoordinate, int iYCoordinate, bool &bIsWrongInput, bool &bPlayerHasHit)
{
  if (iMatComputerBoard[iYCoordinate][iXCoordinate] == 0)
  {  
    showMiss(1);
    iMatComputerBoard[iYCoordinate][iXCoordinate] = 3;  
    bIsWrongInput = false;
  }
  else
  {
    if (iMatComputerBoard[iYCoordinate][iXCoordinate] == 1)
    {
      showHit(1);
      iMatComputerBoard[iYCoordinate][iXCoordinate] = 2;
      bIsWrongInput = false;
      bPlayerHasHit = true;
    }
    else
    {
      if (iMatComputerBoard[iYCoordinate][iXCoordinate] == 2 || iMatComputerBoard[iYCoordinate][iXCoordinate] == 4)
      {
        cout << "\x1b[31mInvalid coordinate, you've already hit that spot\x1b[37m" << endl;
      }
      else
      {
        if (iMatComputerBoard[iYCoordinate][iXCoordinate] == 3)
        {
          cout << "\x1b[31mInvalid coordinate, you've already hit that spot\x1b[37m" << endl;
        }
      }
    }
  }
}

/*
getPlayerCoordinate
Function to let the user input a coordinate to strike
Parameters: A matrix with the player board, the computer board, the player name, the team
and a bool if the player has hit a ship
Return: nothing
*/
void getPlayerCoordinate(int iMatPlayerBoard[10][10], int iMatComputerBoard[10][10], string sPlayerName, char cTeam, bool &bPlayerHasHit)
{
  string sHitCoordinate;

  bool bIsWrongInput = true;

  cout << "Admiral " << sPlayerName;

  if (cTeam == 'J' || cTeam == 'j')
  {
    cout << "-San";
  }

  cout << ",  enter the coordinates where you want to strike!" << endl;
  cout << "--> ";

  while (bIsWrongInput)
  {
    cin >> sHitCoordinate;

    //Check if the coordinates are two characters long
    if (sHitCoordinate.length() != 2)
    {
      cout << "\x1b[31mInvalid coordinate. Please enter two characters as coordinate\x1b[37m" << endl;
    }
    else
    {
      //Check if the first character is a letter in valid range
      if (sHitCoordinate[0] < 65 || sHitCoordinate[0] > 74)
      {
        cout << "\x1b[31mInvalid coordinate. Please enter letters from A to J capitalized\x1b[37m" << endl;
      }
      else
      {
        //Check if the second character is a number in valid range
        if (sHitCoordinate[1] < 48 || sHitCoordinate[1] > 57)
        {
          cout << "\x1b[31mInvalid coordinate. Please enter a digit as second parameter\x1b[37m" << endl;
        }
        else
        {
          int iXCoordinate = sHitCoordinate[0] - 65;
          int iYCoordinate = sHitCoordinate[1] - 48;
          playerExecuteShot(iMatComputerBoard, iXCoordinate, iYCoordinate, bIsWrongInput, bPlayerHasHit);
        }
      }
    }
  }
}

/*
playerTurn
Function for the player turn and let the user input a coordinate
Parameters: A matrix with the player board, the computer board, a set of arrays with the positions of the
computer ships, the player name, a char with the player team, and a bool if the player has hit a ship
Return: nothing
*/
void playerTurn(int iMatPlayerBoard[10][10], int iMatComputerBoard[10][10], string sPlayerName, char cTeam, 
              int iArrComputerCarrierPosition[], int iArrComputerBattleshipPosition[], int iArrComputerCruiserPosition[], 
        int iArrComputerSubmarinePosition[], int iArrComputerDestroyerPosition[], bool &bPlayerHasHit)
{
  getPlayerCoordinate(iMatPlayerBoard, iMatComputerBoard, sPlayerName, cTeam, bPlayerHasHit);

  checkComputerShips(iMatComputerBoard, cTeam, iArrComputerCarrierPosition, iArrComputerBattleshipPosition, iArrComputerCruiserPosition,
             iArrComputerSubmarinePosition, iArrComputerDestroyerPosition);
}

/*
checkPlayerShips
Function to check an individual array of a ship to see if it is sunk
Parameters: A matrix with the player board, an array with the ship position, the ship size, the team
and a counter to display the apropiate ship that is sunk
the player name, a char with the player team.
Return: nothing
*/
void checkPlayerIndividualShip(int iMatPlayerBoard[10][10], int iArrShipPosition[10], int iShipSize, char cTeam, int iCounter)
{
  bool bIsSunken = true;
  string sArrShips[10] = {sAmericanCarrier, sJapaneseCarrier, sAmericanBattleship, sJapaneseBattleship, sAmericanCruiser,
              sJapaneseCruiser, sAmericanSubmarine, sJapaneseSubmarine, sAmericanDestroyer, sJapaneseDestroyer};
 
  //Check for horizontal positioning
  if (iArrShipPosition[0])
  {
    int iRowIndex = iArrShipPosition[1];

    for (int iColIndex = iArrShipPosition[2]; iColIndex <= iArrShipPosition[iShipSize + 1]; ++iColIndex)
    {
      if (iMatPlayerBoard[iRowIndex][iColIndex] != 2)
      {
        bIsSunken = false;
      }
    }

    if (bIsSunken)
    {

      if (cTeam == 'J' || cTeam == 'j')
      {
        showSank(0, sArrShips[iCounter + 1]);
      }
      else
      {
        showSank(0, sArrShips[iCounter]);
      }

      for (int iColIndex = iArrShipPosition[2]; iColIndex <= iArrShipPosition[iShipSize + 1]; ++iColIndex)
      {
        iMatPlayerBoard[iRowIndex][iColIndex] = 4;
      }
    }
  }

  //Check for vertical positioning
  else
  {
    int iColIndex = iArrShipPosition[1];

    for (int iRowIndex = iArrShipPosition[2]; iRowIndex <= iArrShipPosition[iShipSize + 1]; ++iRowIndex)
    {
      if (iMatPlayerBoard[iRowIndex][iColIndex] != 2)
      {
        bIsSunken = false;
      }
    }

    if (bIsSunken)
    {

      if (cTeam == 'J' || cTeam == 'j')
      {
        showSank(0, sArrShips[iCounter + 1]);
      }
      else
      {
        showSank(0, sArrShips[iCounter]);
      }

      for (int iRowIndex = iArrShipPosition[2]; iRowIndex <= iArrShipPosition[iShipSize + 1]; ++iRowIndex)
      {
        iMatPlayerBoard[iRowIndex][iColIndex] = 4;
      }
    }
  }
}

/*
checkPlayerShips
Function to check if any of the player ships has been sank
Parameters: A matrix with the player board, a set of arrays with the positions of the player ships, 
the player name, a char with the player team
Return: nothing
*/
void checkPlayerShips(int iMatPlayerBoard[10][10], int iMatComputerBoard[10][10], string sPlayerName, char cTeam, 
            int iArrPlayerCarrierPosition[7], int iArrPlayerBattleshipPosition[6], int iArrPlayerCruiserPosition[5], 
            int iArrPlayerSubmarinePosition[5], int iArrPlayerDestroyerPosition[4])
{
  int iShipSize;
  int iCounter = 0;

  //Check Carrier status
  iShipSize = 5;
  checkPlayerIndividualShip(iMatPlayerBoard, iArrPlayerCarrierPosition, iShipSize, cTeam, iCounter);

  iCounter += 2;

  //Check Battleship status
  iShipSize = 4;
  checkPlayerIndividualShip(iMatPlayerBoard, iArrPlayerBattleshipPosition, iShipSize, cTeam, iCounter);

  iCounter += 2;

  //Check Cruiser status
  iShipSize = 3;
  checkPlayerIndividualShip(iMatPlayerBoard, iArrPlayerCruiserPosition, iShipSize, cTeam, iCounter);

  iCounter += 2;

  //Check Submarine status
  iShipSize = 3;
  checkPlayerIndividualShip(iMatPlayerBoard, iArrPlayerSubmarinePosition, iShipSize, cTeam, iCounter);

  iCounter += 2;

  //Check Destroyer status
  iShipSize = 2;
  checkPlayerIndividualShip(iMatPlayerBoard, iArrPlayerDestroyerPosition, iShipSize, cTeam, iCounter);
}

/*
computerHitIndividualShip
Function to scan an individual array of a ship position to see if the coordinate hit contains the ship
if so, stores the value of the array into a new array iArrShipHit[]
Parameters: An array with the ship position to check, the ship size, the new array to store the data if the
ship is found there, the x coordinate, the y coordinate, a bool if the ship is found
Return: nothing
*/
void checkHitIndividualShip(int iArrPlayerShipPosition[], int iShipSize, int iArrShipHit[], int iXCoordinate, int iYCoordinate,
              bool &bIsShip)
{
  bIsShip = false;

  if (iArrPlayerShipPosition[0])
  {
    if (iArrPlayerShipPosition[1] == iYCoordinate)
    {
      for (int iCounter = 0; iCounter < 7; ++iCounter)
      {
        if (iArrPlayerShipPosition[iCounter] == iXCoordinate)
        {
          bIsShip = true;
        }
      }

      if (bIsShip)
      {
        for (int iCounter = 0; iCounter < iShipSize + 2; ++iCounter)
        {
          iArrShipHit[iCounter] = iArrPlayerShipPosition[iCounter];
        }
      }
    }
  }
  else
  {
    if (iArrPlayerShipPosition[1] == iXCoordinate)
    {
      for (int iCounter = 0; iCounter < 7; ++iCounter)
      {
        if (iArrPlayerShipPosition[iCounter] == iYCoordinate)
        {
          bIsShip = true;
        }
      }

      if (bIsShip)
      {
        for (int iCounter = 0; iCounter < iShipSize + 2; ++iCounter)
        {
          iArrShipHit[iCounter] = iArrPlayerShipPosition[iCounter];
        }
      }
    }
  }
}

/*
computerSinkShip
Function to check which ship has been hit by the computer and stores it in an array iArrShipHit[]
Parameters: a matrix with the player board, a set of arrays with the positions of the player ships
an array with the ship to sink, the ship size to sink 
Return: nothing
*/
void checkHitShip(int iMatPlayerBoard[10][10], int iXCoordinate, int iYCoordinate, int iArrPlayerCarrierPosition[7], 
          int iArrPlayerBattleshipPosition[6], int iArrPlayerCruiserPosition[5], int iArrPlayerSubmarinePosition[5],
          int iArrPlayerDestroyerPosition[4], int iArrShipHit[7], int &iShipSize)
{
  bool bIsShip;

  iShipSize = 5;
  checkHitIndividualShip(iArrPlayerCarrierPosition, iShipSize, iArrShipHit, iXCoordinate, iYCoordinate, bIsShip);

  if (!bIsShip)
  {
    iShipSize = 4;
    checkHitIndividualShip(iArrPlayerBattleshipPosition, iShipSize, iArrShipHit, iXCoordinate, iYCoordinate,
                 bIsShip);

    if (!bIsShip)
    {
      iShipSize = 3;
      checkHitIndividualShip(iArrPlayerCruiserPosition, iShipSize, iArrShipHit, iXCoordinate, iYCoordinate,
                   bIsShip);

      if (!bIsShip)
      {
        iShipSize = 3;
        checkHitIndividualShip(iArrPlayerSubmarinePosition, iShipSize, iArrShipHit, iXCoordinate, iYCoordinate,
                     bIsShip);

        if (!bIsShip)
        {
          
          iShipSize = 2;
          checkHitIndividualShip(iArrPlayerDestroyerPosition, iShipSize, iArrShipHit, iXCoordinate, iYCoordinate,
                               bIsShip);
        }
      }
    }
  }
}


/*
computerSinkShip
Function to hit all coordinates in a ship once the computer has found the ship
Parameters: a matrix with the player board, an array with the ship to sink, the size of the ship, 
a bool if has hit the shipo, a bool if has hit adyacect to prev shot, a bool if coordinate is valid
Return: nothing
*/
void computerSinkShip(int iMatPlayerBoard[10][10], int iArrShipHit[], int iShipSize, bool &bHasHitShip, bool &bHasHitAdyacent,
            bool &bIsWrongCoordinate)
{
  showComputerThinking();

  srand(time(NULL));

  int iDirection = rand() % 2;

  bool bIsSunken = true;

  if (iDirection)
  {
    if (iArrShipHit[0])
    {
      int iRowIndex = iArrShipHit[1];

      for (int iColIndex = iArrShipHit[2]; iColIndex <= iArrShipHit[iShipSize + 1]; ++iColIndex)
      {
        if (iMatPlayerBoard[iRowIndex][iColIndex] == 1)
        {
          showHit(0);
          iMatPlayerBoard[iRowIndex][iColIndex] = 2;
          bIsWrongCoordinate = false;
          bIsSunken = false;
          break;
        }
      }
    }
    else
    {
      int iColIndex = iArrShipHit[1];

      for (int iRowIndex = iArrShipHit[2]; iRowIndex <= iArrShipHit[iShipSize + 1]; ++iRowIndex)
      {
        if (iMatPlayerBoard[iRowIndex][iColIndex] == 1)
        {
          showHit(0);
          iMatPlayerBoard[iRowIndex][iColIndex] = 2;
          bIsWrongCoordinate = false;
          bIsSunken = false;
          break;
        }
      }
    }
  }
  else
  {
    if (iArrShipHit[0])
    {
      int iRowIndex = iArrShipHit[1];

      for (int iColIndex = iArrShipHit[iShipSize + 1] ; iColIndex >= iArrShipHit[2]; --iColIndex)
      {
        if (iMatPlayerBoard[iRowIndex][iColIndex] == 1)
        {
          showHit(0);
          iMatPlayerBoard[iRowIndex][iColIndex] = 2;
          bIsWrongCoordinate = false;
          bIsSunken = false;
          break;
        }
      }
    }
    else
    {
      int iColIndex = iArrShipHit[1];

      for (int iRowIndex = iArrShipHit[iShipSize + 1]; iRowIndex >= iArrShipHit[2]; --iRowIndex)
      {
        if (iMatPlayerBoard[iRowIndex][iColIndex] == 1)
        {
          showHit(0);
          iMatPlayerBoard[iRowIndex][iColIndex] = 2;
          bIsWrongCoordinate = false;
          bIsSunken = false;
          break;
        }
      }
    }
  }

  if (bIsSunken)
  {
    bHasHitShip = false;
    bHasHitAdyacent = false;

  }
}

/*
computerExecuteRandomAdyacentShot
Function to execute a random shot in normal difficulty
Parameters: a matrix with the player board, a set of arrays for the player ship positions,
an array with the position of the ship to sink, a bool to indicate hitShip, a bool if the coordinate is valid,
an int with the  x coordinate, an int with the  Y coordinate, and an int with the ship size
Return: nothing
*/
void computerExecuteRandomShot(int iMatPlayerBoard[10][10], int iXCoordinate, int iYCoordinate, bool &bIsWrongCoordinate,
                   bool &bHasHitShip, int iArrPlayerCarrierPosition[7], int iArrPlayerBattleshipPosition[6],
                   int iArrPlayerCruiserPosition[5], int iArrPlayerSubmarinePosition[5], int iArrPlayerDestroyerPosition[4],
                   int iArrPlayerShipPosition[], int &iShipSize)
{
  showComputerThinking();

  int iXRemainder = iXCoordinate % 2;
  int iYRemainder = iYCoordinate % 2;

  if(iXRemainder == iYRemainder)
  {
    if (iMatPlayerBoard[iYCoordinate][iXCoordinate] == 1)
    {
      showHit(0);

      iMatPlayerBoard[iYCoordinate][iXCoordinate] = 2;

      bIsWrongCoordinate = false;
      bHasHitShip = true;

      //Check which ship has been hit
      checkHitShip(iMatPlayerBoard, iXCoordinate, iYCoordinate, iArrPlayerCarrierPosition,
             iArrPlayerBattleshipPosition, iArrPlayerCruiserPosition, iArrPlayerSubmarinePosition,
             iArrPlayerDestroyerPosition, iArrPlayerShipPosition, iShipSize);

    }
    else

    {
      if (iMatPlayerBoard[iYCoordinate][iXCoordinate] == 0)
      {  
        showMiss(0);

        iMatPlayerBoard[iYCoordinate][iXCoordinate] = 3;
        bIsWrongCoordinate = false;

        bHasHitShip = false;
      }
    }
  }
  else
  {
    bIsWrongCoordinate = true;
  }
}

/*
computerExecuteRandomEasyShot
Function to execute a completely random shot
Parameters: a matrix with the player board, the x coordinate, the y coordinate, a bool if wrong coordinate 
Return: nothing
*/
void computerExecuteRandomEasyShot(int iMatPlayerBoard[10][10], int iXCoordinate, int iYCoordinate, bool &bIsWrongCoordinate)
{
  showComputerThinking();

  if (iMatPlayerBoard[iYCoordinate][iXCoordinate] == 1)
  {
    iMatPlayerBoard[iYCoordinate][iXCoordinate] = 2;

    bIsWrongCoordinate = false;

    showHit(0);

  }
  else

  {
    if (iMatPlayerBoard[iYCoordinate][iXCoordinate] == 0)
    {
      showMiss(0);

      iMatPlayerBoard[iYCoordinate][iXCoordinate] = 3;
      bIsWrongCoordinate = false;
    }
  }
}

/*
computerExecuteRandomAdyacentShot
Function to execute a shot adyacent to the previous shot randomly
Parameters: a matrix with the player board, a set of arrays for the player ship positions,
an array with the position of the ship to sink, a bool to indicate hitShip, a bool if hitAdyacent,
an int with the  x coordinate, an int with the  Y coordinate, and an int with the ship size
Return: nothing
*/
void computerExecuteRandomAdyacentShot(int iMatPlayerBoard[10][10], int &iXCoordinate, int &iYCoordinate, int iPrevXCoor,
                     int iPrevYCoor, bool &bIsWrongCoordinate, bool &bHasHitAdyacent, bool &bHasHitShip,
                     int iArrShipHit[], int iShipSize)
{
  showComputerThinking();

  srand(time(NULL));

  iXCoordinate = iPrevXCoor; 
  iYCoordinate = iPrevYCoor;

  int iWillSum = rand() % 2;
  int iOrientation = rand() % 2;
  
  if (iOrientation)
  {
    if (iWillSum)
    {
      if (iPrevXCoor != 9)
      {
        iXCoordinate = iPrevXCoor + 1;
      }
    }
    else
    {
      if (iPrevXCoor != 0)
      {
        iXCoordinate = iPrevXCoor - 1;
      }
    }
  }
  else
  {
    if (iWillSum)
    {
      if (iPrevYCoor != 9)
      {
        iYCoordinate = iPrevYCoor + 1;
      }
    }
    else
    {
      if (iPrevYCoor != 0)
      {
        iYCoordinate = iPrevYCoor - 1;
      }
    }
  }

  if (iMatPlayerBoard[iYCoordinate][iXCoordinate] == 1)
  {
    showHit(0);

    iMatPlayerBoard[iYCoordinate][iXCoordinate] = 2;

    bIsWrongCoordinate = false;
    bHasHitAdyacent = true;

    if (iShipSize == 2)
    {
      bHasHitShip = false;
      bHasHitAdyacent = false;
    }
  }
  else
  {
    if (iMatPlayerBoard[iYCoordinate][iXCoordinate] == 0)
    {
      showMiss(0);
      iMatPlayerBoard[iYCoordinate][iXCoordinate] = 3;

      bIsWrongCoordinate = false;
      bHasHitAdyacent = false;
    }
    else
    {
      bIsWrongCoordinate = true;
      bHasHitAdyacent = false;
    }
  }
}


void generateRandomCoordinate(int &iXCoordinate, int &iYCoordinate)
{
  srand(time(NULL));

  iXCoordinate = rand() % 10;
  iYCoordinate = rand() % 10;
}

/*
runGame
Function to execute the computer turn
Parameters: two matrices for the player and the computer, a set of arrays for the player ship positions,
an array with the position of the ship to sink, a string with the player name, a char with the team,
a bool to indicate hitShip, a bool if hitAdyacent, an int with the previous x coordinate, an int with the
previous Y coordinate, and int with the ship size, and an int with the difficulty
Return: nothing
*/
void computerTurn(int iMatPlayerBoard[10][10], int iMatComputerBoard[10][10], string sPlayerName, char cTeam, 
          int iArrPlayerCarrierPosition[7], int iArrPlayerBattleshipPosition[6], int iArrPlayerCruiserPosition[5], 
          int iArrPlayerSubmarinePosition[5], int iArrPlayerDestroyerPosition[4],int iArrShipHit[], 
          bool &bHasHitShip, bool &bHasHitAdyacent, int &iPrevXCoor, int &iPrevYCoor, int &iShipSize, int &iDifficulty)
{

  int iXCoordinate = 0, iYCoordinate = 0;
  int iProbabilityHit;

  bool bIsWrongCoordinate = true;

  while (bIsWrongCoordinate)
  {
    if (iDifficulty == 2)
    {
      //Normal Mode
      if (bHasHitShip)
      {
        if (bHasHitAdyacent)
        {
          computerSinkShip(iMatPlayerBoard, iArrShipHit, iShipSize, bHasHitShip, bHasHitAdyacent, bIsWrongCoordinate);
        }
        else
        {
          computerExecuteRandomAdyacentShot(iMatPlayerBoard, iXCoordinate, iYCoordinate, iPrevXCoor, 
                          iPrevYCoor, bIsWrongCoordinate, bHasHitAdyacent, bHasHitShip, 
                          iArrShipHit, iShipSize);
        }
      }
      else
      {
        generateRandomCoordinate(iXCoordinate, iYCoordinate);

        computerExecuteRandomShot(iMatPlayerBoard, iXCoordinate, iYCoordinate, bIsWrongCoordinate, bHasHitShip,
                                iArrPlayerCarrierPosition, iArrPlayerBattleshipPosition, iArrPlayerCruiserPosition,
                                iArrPlayerSubmarinePosition, iArrPlayerDestroyerPosition, iArrShipHit, iShipSize);

        iPrevXCoor = iXCoordinate;
          iPrevYCoor = iYCoordinate;
      }
    }
    else
    {
      //Easy mode
      generateRandomCoordinate(iXCoordinate, iYCoordinate);

      computerExecuteRandomEasyShot(iMatPlayerBoard, iXCoordinate, iYCoordinate, bIsWrongCoordinate);
    }
  }

  checkPlayerShips(iMatPlayerBoard, iMatComputerBoard, sPlayerName, cTeam, iArrPlayerCarrierPosition, iArrPlayerBattleshipPosition,
                iArrPlayerCruiserPosition, iArrPlayerSubmarinePosition, iArrPlayerDestroyerPosition);
}

/*
runGame
Function to start running the game
Parameters: two matrices for the player and the computer, a set of arrays for the computer ship positions, and another
for the player ship positionsm, a string with the player name, a char with the team, and and int with the difficulty.
Return: nothing
*/
void runGame(int iMatPlayerBoard[10][10], int iMatComputerBoard[10][10], string sPlayerName, char cTeam,
             int iArrPlayerCarrierPosition[7], int iArrPlayerBattleshipPosition[6], int iArrPlayerCruiserPosition[5],
         int iArrPlayerSubmarinePosition[5], int iArrPlayerDestroyerPosition[4], int iArrComputerCarrierPosition[7],
         int iArrComputerBattleshipPosition[6], int iArrComputerCruiserPosition[5], int iArrComputerSubmarinePosition[5],
         int iArrComputerDestroyerPosition[4], int &iDifficulty)
{
  bool bGameIsRunning = true;
  bool bPlayerHasHit = false;
  bool bIsWinner = false;
  bool bComputerHitShip = false;
  bool bComputerHitAdyacent = false;

  int iComputerPrevXCoor = 0;
  int iComputerPrevYCoor = 0;
  int iPlayerScore = 0;
  int iScoreAmountToSum = 500;
  int iTurnPenalty = 0;
  int iShipToSinkSize = 0;

  cleanScreen();

  int iArrShipHit[7];

  showBeginGame();

  while (bGameIsRunning)
  {

    printRunningBoard(iMatPlayerBoard, iMatComputerBoard, iPlayerScore);

    playerTurn(iMatPlayerBoard, iMatComputerBoard, sPlayerName, cTeam, iArrComputerCarrierPosition, iArrComputerBattleshipPosition,
               iArrComputerCruiserPosition, iArrComputerSubmarinePosition, iArrComputerDestroyerPosition, bPlayerHasHit);
    
    if (bPlayerHasHit)
    {
      if (iTurnPenalty < 500)
      {
        iPlayerScore += iScoreAmountToSum - iTurnPenalty;
      }
      else
      {
        iPlayerScore += iScoreAmountToSum - 490;
      }

    }
    else
    {
      iTurnPenalty += 10;
    }

    bPlayerHasHit = false;
    
    printRunningBoard(iMatPlayerBoard, iMatComputerBoard, iPlayerScore);

    bIsWinner = checkIfWinner(iMatComputerBoard, bGameIsRunning);

    if (!bGameIsRunning)
    {
      break;
    }

    pressToContinue();

    showComputerTurn();

    computerTurn(iMatPlayerBoard, iMatComputerBoard, sPlayerName, cTeam, iArrPlayerCarrierPosition, 
           iArrPlayerBattleshipPosition, iArrPlayerCruiserPosition, iArrPlayerSubmarinePosition,
           iArrPlayerDestroyerPosition, iArrShipHit, bComputerHitShip, bComputerHitAdyacent,
           iComputerPrevXCoor, iComputerPrevYCoor, iShipToSinkSize, iDifficulty);

    bIsWinner = !checkIfWinner(iMatPlayerBoard, bGameIsRunning);
  }

  showResult(sPlayerName, cTeam, bIsWinner, iPlayerScore);
}

/*
main
Function to call other functions
Parameters: none
Return: 0
*/
int main()
{
  //boolean to let the game run
  bool bRunGame = true;

  showMenu();  

  while (bRunGame)
  {
    int iMatPlayerBoard[10][10], iMatComputerBoard[10][10];

    int iArrPlayerCarrierPosition[7];
    int iArrPlayerBattleshipPosition[6];
    int iArrPlayerCruiserPosition[5];
    int iArrPlayerSubmarinePosition[5];
    int iArrPlayerDestroyerPosition[4];

    int iArrComputerCarrierPosition[7];
    int iArrComputerBattleshipPosition[6];
    int iArrComputerCruiserPosition[5];
    int iArrComputerSubmarinePosition[5];
    int iArrComputerDestroyerPosition[4];

    int iDifficulty;   

    string sPlayerName;

    char cTeam;

    char cInput = getMenuInput();

    switch(cInput)
    {  
      //Start game
      case 'P':
      case 'p':
        showIntro(30);

        setupGame(iMatPlayerBoard, iMatComputerBoard, sPlayerName, cTeam, iArrPlayerCarrierPosition,
              iArrPlayerBattleshipPosition, iArrPlayerCruiserPosition, iArrPlayerSubmarinePosition,
              iArrPlayerDestroyerPosition, iArrComputerCarrierPosition, iArrComputerBattleshipPosition,
              iArrComputerCruiserPosition, iArrComputerSubmarinePosition, iArrComputerDestroyerPosition,
              iDifficulty);

        runGame(iMatPlayerBoard, iMatComputerBoard, sPlayerName, cTeam, iArrPlayerCarrierPosition,
            iArrPlayerBattleshipPosition, iArrPlayerCruiserPosition, iArrPlayerSubmarinePosition,
            iArrPlayerDestroyerPosition, iArrComputerCarrierPosition, iArrComputerBattleshipPosition,
            iArrComputerCruiserPosition, iArrComputerSubmarinePosition, iArrComputerDestroyerPosition,
            iDifficulty);

        break;

      //Show instructions
      case 'I':
      case 'i':
        displayInstructions();
        break;

      //Show about information  
      case 'A':
      case 'a':
        displayAbout();
        break;

      //Exit game
      case 'E':
      case 'e':
        bRunGame = false;
        break;

      //Case when a wrong letter is introduced
      default:
        showMenu();
        cout << "\x1b[31mInvalid option" << endl;
        break;
    }

    showMenu();
  }

  return 0;    
}
