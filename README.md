# Statistics
Programming Fundamentals final project

PROJECT

Objective	Objective:
Identify and learn how the SWITCH statement works in C++.
Reloj	Estimated time for this assignment: 
4 hours per person
Persona	Collaboration: 
Team of 2 students
Hoja con contenido	
Description:

Rules for BattleShip (a Milton Bradley Game)

Game Objective

The object of Battleship is to try and sink all of the other player's before they sink all of your ships. All of the other player's ships are somewhere on his/her board.  You try and hit them by calling out the coordinates of one of the squares on the board.  The other player also tries to hit your ships by calling out coordinates.  Neither you nor the other player can see the other's board so you must try to guess where they are.  Each board in the physical game has two grids:  the section for the player's ships and the and another one for recording the player's guesses.

Starting a New Game

Each player places the 5 ships somewhere on their board.  The ships can only be placed vertically or horizontally. Diagonal placement is not allowed. No part of a ship may hang off the edge of the board.  Ships may not overlap each other.  No ships may be placed on another ship. 

Once the guessing begins, the players may not move the ships.

The 5 ships are:  Carrier (occupies 5 spaces), Battleship (4), Cruiser (3), Submarine (3), and Destroyer (2).  

Playing the Game

Player's take turns guessing by calling out the coordinates. The opponent responds with "hit" or "miss" as appropriate.  Both players should mark their board with pegs:  red for hit, white for miss. For example, if you call out F6 and your opponent does not have any ship located at F6, your opponent would respond with "miss".  You record the miss F6 by placing a white peg on the lower part of your board at F6.  Your opponent records the miss by placing.

When all of the squares that one your ships occupies have been hit, the ship will be sunk.   You should announce "hit and sunk".  In the physical game, a red peg is placed on the top edge of the vertical board to indicate a sunk ship. 

As soon as all of one player's ships have been sunk, the game ends.
In this project, the other player is the "computer". You need to provide some sort of "intelligence" in order to make every single movement a random one. For example, if the computer got to hit one of your ships, the next shot must be fired next to a recent previous shot, or you can't shoot to the same location more than once. All boards are 10x10.

Interaction: 

It must be clear which player's turn is at every moment. 
A message must be displayed after each shot: Hit! or Missed!
At the end of the game, a message identifying who won the match must be displayed
Do not forget to:

follow coding standards,
provide Analysis.
Mundo	Delivery:

Save your document as a PDF file under the name of: battleship.cpp and submit it through Vocareum before the due date.

Note: Under no circumstances should this activity be accepted out of time [let alone, without your full authorship].
Gráfica de Pie	Evaluation:
[-100 pts] This assignment was not submitted before the due date.
[-100 pts] This file can't be opened for grading (i.e. virus, damaged file, etc).
[-100 final points] Detection of fraud
[20 pts] Coding Standards
[10 pts] Analysis
  

