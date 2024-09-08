#include "C4Board.h"
#include <iostream>

void C4Board::play() {
	int turns = 0;
	char player;
	int playerMove;
	int maxMoves = 42;

	printBoard();
	while (turns < maxMoves) {
		char whoseTurn = (turns % 2) == 0 ? 'X' : 'O';
		player = whoseTurn;

		cout << player << "'s move: ";
		cin >> playerMove;

		//error checking players input
		if (!(playerMove >= 0) || !(playerMove <= 6)) {
			cout << "Invalid move input a number between 1 and 7." << endl;
			continue;
		}

		//confirming the user isn't making a move in a column that is already full.
		if (board[playerMove].getDisk(5) != ' ') {
			cout <<  "That column is full. Choose a different coulmn." << endl;
			continue;
		}
	
		turns += 1;
		addDisk(playerMove, player);
		
		//The following if statements call my check win functions and end the game if the return true.
		if (checkColumn()) {
			printBoard();
			cout << player << " Wins" << endl;
			break;
		}
		if (checkRow()) {
			printBoard();
			cout << player << " Wins" << endl;
			break;
		}
		if (checkDiagonal()) {
			printBoard();
			cout << player << " Wins" << endl;
			break;
		}
    if (turns == maxMoves) {
      printBoard();
      cout << "Tie" << endl;
    }
		cout << endl;
		printBoard();
	}
}


void C4Board::printBoard() {
	//prints the numbers at the top of each column
	for (int i = 0; i < 7; i++) {
		cout << " " << i << " ";
		if (i < 6) {
			cout << "|";
		}
	}
	cout << endl;
	//prints the actual board with spaces and columns separated by |
	for (int i = 5; i >= 0; i--) {
		for (int j = 0; j < 7; j++) {
			cout << ' ' << board[j].getDisk(i);
			if (j < 6) {	
				cout << " |";
			}
		}
		cout << endl;
	}
	cout << endl;
	
}

//adds the disks to the column selected by the user.
void C4Board::addDisk(int column, char player) {
	for (int i = 0; i < 6; i++) {
		if (board[column].getDisk(i) == ' ') {
			board[column].placeDisk(i, player);
			break;
		}
	}
	
}
//Starts from the bottom left corner with a hard coded four cells in a row and
//that is shifted up and over across the board to see if there are four 
//in a row in the columns.
bool C4Board::checkColumn() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i].getDisk(j) == ' ') {
				continue;
			}

			if ((board[i].getDisk(j) == board[i].getDisk(j + 1)) && (board[i].getDisk(j) == board[i].getDisk(j + 2)) &&
					(board[i].getDisk(j) == board[i].getDisk(j + 3))) {
				return true;
			}
		}
		
	}
	return false;
}

//Starts from the bottom left corner with a hard coded four cells in a row and
//that is shifted up and over across the board to see if there are four 
//in a row in the rows.
bool C4Board::checkRow() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i].getDisk(j) == ' ') {
				continue;
			}

			if ((board[i].getDisk(j) == board[i + 1].getDisk(j)) && (board[i].getDisk(j) == board[i + 2].getDisk(j)) &&
							(board[i].getDisk(j) == board[i + 3].getDisk(j))) {
					return true;
			}
		}
	}
	
	return false;
}

//Starts from the bottom left corner with a hard coded four cells in a diagonal row and
//that is shifted up and over across the board to see if there are four 
//in a row in the diagonal cases.
bool C4Board::checkDiagonal() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i].getDisk(j) == ' ') {
				continue;
			}

			if (((board[i].getDisk(j) == board[i + 1].getDisk(j + 1)) && (board[i].getDisk(j) == board[i + 2].getDisk(j + 2)) && 
						(board[i].getDisk(j) == board[i + 3].getDisk(j + 3)))) {
				return true;
			}
		}
	}

	for (int i = 6; i > 2; i--) {
		for (int j = 0; j < 3; j++) {
			if (board[i].getDisk(j) == ' ') {
				continue;
			}
			if (((board[i].getDisk(j) == board[i - 1].getDisk(j + 1)) && (board[i].getDisk(j) == board[i - 2].getDisk(j + 2)) && 
					(board[i].getDisk(j) == board[i - 3].getDisk(j + 3)))) {
				return true;
			}
		}
	}

	return false;
}

//checks to see if the column is full or not.
bool C4Board::isFull(int playerMove) {
	int maxDisks = board[0].getMaxDisks();
	if (board[playerMove].getDisk(maxDisks - 1) != ' ') {
		return true;
	}

	return false;
}

