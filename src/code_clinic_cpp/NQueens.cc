#inlcude "NQueens.h"

using namespace std;

NQueens::NQueens(int nQueens) {
  nQueens_ = nQueens;
  solnCount_ = 0;
  board_ = new int[nQueens];
  lastSoln_ = new int[nQueens];
}

// use printAllSolns to optionally print all solution boards
void NQueens::computeSolns(bool printAllSolns) {
  solveNQ(0, printAllSolns);
  if (!printAllSolns) {
    board_ = lastSoln_;
    printBoard();
  }
  cout << solnCount_ << " solutions found" << endl;
}

// use recursion and backtracking to find solutions
void NQueens::solveNQ(int row, bool printAllSolns) {
  // all queens have been placed, so return true
  if (row >= nQueens_) {
    solnCount_++;
    memcpy(lastSoln_, board_, nQueens_ * sizeof(int));
    if (printAllSolns) {
      printBoard();
    }
    return;
  }

  // test column and try placing a queen in each row
  for (int i = 0; i < nQueens_; i++) {
    if (isSafe(row, i)) {
      board_[row] = i;
      solveNQ(row + 1, printAllSolns);
    }
  }
}

bool NQueens::isSafe(int row, int col) {
  for (int i = 0; i < row; i++) {
    if (board_[i] == col) return false;
    if (board_[i] == col - (row - i)) return false;
    if (board_[row - 1 - i] == col + i + 1) return false;
  }
  return true;
}

void NQueens::printBoard() {
  int row, col = 0;
  cout << endl;
  for (row = 0; row < nQueens_; row++) {
    cout << board_[row];
  }
  cout << endl;

  for (int dash = 0; dash < nQueens_ * 4 + 1; dash++) {
    cout << "-";
  }
  cout << endl;

  for (row = 0; row < nQueens_; row++) {
    cout << "|";
    for (col = 0; col < nQueens_; col++) {
      if (board_[row] == col) {
        cout << " Q |";
      } else {
        cout << "   |";
      }
    }
    cout << endl;
    for (int dash = 0; dash < nQueens_ * 4 + 1; dash++) {
      cout << "-";
    }
    cout << endl;
  }
}

