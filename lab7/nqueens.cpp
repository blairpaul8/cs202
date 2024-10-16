/* Lab 7:  N-queens using backtracking 
 * Name: Paul Blair
 * Net ID: VBQ669
 * Description: this is the optimized version of the nqueens problem that 
 * checks if it is a valid board for every combination possible.
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

int solutions = 0;

void print_board(vector<int>& board) {
  for (size_t i = 0; i < board.size(); i++) {
    printf("%d", board[i]);
    if (i < (board.size() - 1)) {
      printf(", ");
    }
  }
  printf("\n");
}

bool check(vector<int>& board) {
  // check horizontal
  for (size_t i = 0; i < board.size(); i++) {
    for (size_t j = i + 1; j < board.size(); j++) {
      if (board[i] == board[j]) {
        return false;
      }
    }
  }
  //check diagonal
  for (size_t i = 0; i < board.size() - 1; i++) {
    for (size_t j = i + 1; j < board.size(); j++) {
      if ((max(i,j) - min(i,j))  == abs(board[i] - board[j])) {
        return false;
      }
    }
  }
  return true;
}

void nqueens(vector<int>& board, int pos) {
  if (pos == board.size()) {
    if (check(board)) {
      print_board(board);
    } 
  }

  else {
    for (size_t i = 0; i < board.size(); i++) {
      board[pos] = i;
      nqueens(board, pos + 1);
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


  //printf("solutions: %d\n", solutions);

  return 0;

}

