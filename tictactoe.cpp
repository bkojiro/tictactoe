//Kojiro, Brandon
//11 September 2024
//P3 Galbraith - C++/Data Structures
//TicTacToe for two players

#include <iostream>

using namespace std;

void gridOut(int grid[][3]);
bool CheckTie(int grid[][3]);
bool CheckWin(int grid[][3], int playerMove);
const int BLANK = 0;
const int X_MOVE = 1;
const int O_MOVE = 2;

int main() {
  bool playAgain = true;
  bool stillPlaying = true;
  int playerMove = X_MOVE;
  char playerChar = 'X';
  
  while (playAgain) {

    //keep going until tie/player win
    int grid[3][3] = {{0,0,0},
                      {0,0,0},
                      {0,0,0}};
    gridOut(grid);
    
    while (stillPlaying) {

      //move entering
      cout << "Enter a letter then a number (no spaces)" << endl << "> ";
      char input[2];
      cin.get(input, 3);
      cin.get();
      int xTemp;
      int yTemp;
      xTemp = (int)input[1] - 49;
      if (input[0] == 'a' || input[0] == 'A') {
	yTemp = 0;
      } else if (input[0] == 'b' || input[0] == 'B') {
	yTemp = 1;
      } else if (input[0] == 'c' || input[0] == 'C') {
	yTemp = 2;
      }
      if (grid[xTemp][yTemp] == 0) {
	grid[xTemp][yTemp] = playerMove;
	gridOut(grid);
	if (CheckWin(grid, playerMove)) {
	  //player has won
	  cout << playerChar << " Player has won!" << endl;
	  stillPlaying = false;
	} else if (CheckTie(grid)) {
	  //players have tied
	  cout << "Players have tied!" << endl;
	  stillPlaying = false;
	} else {
	  if (playerMove == X_MOVE) {
	    playerMove = O_MOVE;
	    playerChar = 'O';
	  } else {
	    playerMove = X_MOVE;
	    playerChar = 'X';
	  }
	}
      } else {
	cout << "This spot is already taken!" << endl;
      }
    }
    
    //play again
    cout << "Play Again? y/n" << endl << "> ";
    char answer;
    cin >> answer;
    if (answer == 'n') {
      cout << "Bye bye!";
      playAgain = false;
    } else if (answer == 'y') {
      stillPlaying = true;
    }
  }
}

void gridOut(int grid[][3]) {
  //display grid
  cout << "  1 2 3" << endl;
  for (int y = 0; y < 3; y++) {
    cout << char(97 + y) << " ";
    for (int x = 0; x < 3; x++) {
      if (grid[x][y] == 0) {
	cout << "  ";
      } else if (grid[x][y] == 1) {
        cout << "X ";
      } else if (grid[x][y] == 2) {
	cout << "O ";
      }
    }
    cout << endl;
  }
}

bool CheckWin(int grid[][3], int playerMove) {
  if ((grid[0][0] == playerMove && grid[0][1] == playerMove && grid[0][2] == playerMove) || //first vertical
      (grid[1][0] == playerMove && grid[1][1] == playerMove && grid[1][2] == playerMove) || //second vertical
      (grid[0][0] == playerMove && grid[0][1] == playerMove && grid[0][2] == playerMove) || //third vertical
      (grid[0][0] == playerMove && grid[1][0] == playerMove && grid[2][0] == playerMove) || //first horizontal
      (grid[0][1] == playerMove && grid[1][1] == playerMove && grid[2][1] == playerMove) || //second horizontal
      (grid[0][2] == playerMove && grid[1][2] == playerMove && grid[2][2] == playerMove) || //third horizontal
      (grid[0][0] == playerMove && grid[1][1] == playerMove && grid[2][2] == playerMove) || //left to right diagonal
      (grid[2][0] == playerMove &&grid[1][1] == playerMove && grid[0][2] == playerMove)) { //right to left diagonal
    return true;
  }
  return false;
}

bool CheckTie(int grid[][3]) {
  int blankCount = 0;
  for (int y = 0; y < 3; y++) {
    for (int x = 0; x < 3; x++) {
      if (grid[x][y] == 0) blankCount++;
    }
  }
  if (blankCount == 0) {
    return true;
  }
  return false;
}
