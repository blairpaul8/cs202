/* Lab 7:  N-queens using backtracking 
 * Name: Paul Blair
 * Net ID: VBQ669
 * Description: this is the optimized version of the nqueens problem that 
 * check if it is a valid board with each iteration of the for loop 
 * stopping the recursion if it isnt a valid board and continuing to the
 * next one.
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

void print_board(vector<int>& board) {
  for (size_t i = 0; i < board.size(); i++) {
    printf("%d", board[i]);
    if (i != (board.size() - 1)) {
      printf(", ");
    }
  }
  printf("\n");
}

bool check(vector<int>& board, int col) {
  // check horizontal
  for (int i = 0; i < col; i++) {
    for (int j = 0; j < col; j++) {
      //This case the values at board[i] and board[j] will always be equal
      //so it needs to be skipped.
      if (i == j) {
        continue;
      }
      if (board[i] == board[j]) {
        return false;
      }
    }
  }
  //check diagonal
  for (int i = 0; i < col; i++) {
    for (int j = 0; j < col; j++) {
      if (i == j) {
        continue;
      }
      if ((max(i,j) - min(i,j))  == abs(board[i] - board[j])) {
        return false;
      }
    }
  }
  return true;
}

void nqueens(vector<int>& board, int pos) {
  if (pos == (int)board.size()) {
    print_board(board);
  }
  else {
    for (size_t i = 0; i < board.size(); i++) {
      board[pos] = i;
      if (check(board, pos + 1)) {
        nqueens(board, pos + 1);
      }

    }
  }
}

void num_queens(int n) {
  vector<int> board;
  int pos = 0;
  board.resize(n);
  nqueens(board, pos);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cerr << "./nqueens nqueens" << endl;
  }
  int n = atoi(argv[1]);
  num_queens(n);
  return 0;
}
