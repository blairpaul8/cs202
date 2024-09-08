#include "C4Board.h"
#include <iostream>
#include <cstdlib>
C4Board::C4Board() {
}

void C4Board::play() {
	int turns = 0;
	char player;
	int playerMove;
	int maxMoves = 42;
	int numPlayers;
	
	cout << "Do you want to play one or two players? Enter 1 or 2: ";
	cin >> numPlayers;

	printBoard();
	while (turns < maxMoves) {
		char whoseTurn = (turns % 2) == 0 ? 'X' : 'O';
		player = whoseTurn;
		
		if (numPlayers == 1 && player == 'O') {
			int randMove = randomMove();
			while (board[randMove].getDisk(5) != ' ') {
				randMove = randomMove();
			}
			
			turns += 1;
			addDisk(randMove, player);


		}

		else {
			cout << player << "'s move: ";
			cin >> playerMove;

			if (!(playerMove >= 0) || !(playerMove <= 6)) {
				cout << "Invalid move input a number between 1 and 7." << endl;
				continue;
			}

			if (board[playerMove].getDisk(5) != ' ') {
				cout <<  "That column is full. Choose a different coulmn." << endl;
				continue;
			}
	
			turns += 1;
			addDisk(playerMove, player);

		}

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
		cout << endl;
		printBoard();
	}
}


void C4Board::printBoard() {	
	for (int i = 0; i < 7; i++) {
		cout << " " << i << " ";
		if (i < 6) {
			cout << "|";
		}
	}
	cout << endl;
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

void C4Board::addDisk(int column, char player) {
	for (int i = 0; i < 6; i++) {
		if (board[column].getDisk(i) == ' ') {
			board[column].placeDisk(i, player);
			break;
		}
	}
	
}

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


int C4Board::randomMove() {
	int move = rand() % 7;
	
	return move;
}
