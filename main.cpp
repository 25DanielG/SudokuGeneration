#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int boardSize; // Must be a multiple of 3

bool numberInColumn(vector<vector<int> > board, int c, int n) { // checks if a number is in the column
    for(int r = 0; r < boardSize; ++r) {
        if(board[r][c] == n) return true;
    }
    return false;
}

bool numberInRow(vector<vector<int> > board, int r, int n) { // checks if a number is in the row
    for(int c = 0; c < boardSize; ++c) {
        if(board[r][c] == n) return true;
    }
    return false;
}

bool numberInBox(vector<vector<int> > board, int startR, int startC, int n) {
    for(int r = startR; r < startR + 3; ++r) {
        for(int c = startC; c < startC + 3; ++c) {
            if(board[r][c] == n) return true;
        }
    }
    return false;
}

bool solveSudoku(vector<vector<int> > board) { // Board includes sudoku puzzle with 0's in place of empty spots

}

int main() {
    cin >> boardSize;
    if(boardSize % 3 != 0) {
        cout << "Board size must be a multiple of three" << endl;
        cin >> boardSize;
    }
}