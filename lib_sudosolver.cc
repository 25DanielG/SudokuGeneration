#include "./sudosolver.h"
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::pair;

bool sudoSolver::numberInColumn(int boardSize, vector<vector<int> > board, int c, int n) { // checks if a number is in the column
    for(int r = 0; r < boardSize; ++r) {
        if(board[r][c] == n) return true;
    }
    return false;
}

bool sudoSolver::numberInRow(int boardSize, vector<vector<int> > board, int r, int n) { // checks if a number is in the row
    for(int c = 0; c < boardSize; ++c) {
        if(board[r][c] == n) return true;
    }
    return false;
}

bool sudoSolver::numberInBox(vector<vector<int> > board, int startR, int startC, int n) { // checks if a number is in the box
    for(int r = startR; r < startR + 3; ++r) {
        for(int c = startC; c < startC + 3; ++c) {
            if(board[r][c] == n) return true;
        }
    }
    return false;
}

pair<int, int> sudoSolver::findUnassignedSlots(vector<vector<int> > board) { // finds empty slots on the board
    pair<int, int> tmp;
    for(int r = 0; r < board.size(); ++r) {
        for(int c = 0; c < board.size(); ++c) {
            if(board[r][c] == 0) {
                tmp.first = r, tmp.second = c;
                return tmp;
            }
        }
    }
    tmp.first = -1, tmp.second = -1;
    return tmp;
}

bool sudoSolver::solveSudoku(int boardSize, vector<vector<int> > &board) { // Board includes sudoku puzzle with 0's in place of empty spots
    pair<int, int> check = findUnassignedSlots(board);
    if(check.first == -1 && check.second == -1) return false; // Sudoku is filled
    for(int n = 1; n <= 9; ++n) { // Loop through possible numbers
        if(!numberInColumn(boardSize, board, check.second, n) && !numberInRow(boardSize, board, check.first, n) && !numberInBox(board, (check.first - check.first % 3), (check.second - check.second % 3), n)) {
            board[check.first][check.second] = n;
            pair<int, int> end = findUnassignedSlots(board);
            if(end.first == -1 && end.second == -1) return true; // Sudoku is solved
            if(solveSudoku(boardSize, board)) return true;
            board[check.first][check.second] = 0;
        }
    }
    return false;
}