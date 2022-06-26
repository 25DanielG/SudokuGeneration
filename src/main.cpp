#include <iostream>
#include <vector>
#include <random>
#include "sudosolver.h"
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::pair;
// Compiling commands:
// cd src
// g++ lib_sudosolver.cc main.cpp -o sudoSolver (compile command)
// ./sudoSolver (exec command)
bool solvable(vector<vector<int> > &board, const int boardSize) {
    return (sudoSolver::solveSudoku(boardSize, board));
}
int main() {
    int boardSize; // must be a multiple of 3
    cin >> boardSize;
    if(boardSize % 3 != 0) {
        cout << "Board size must be a multiple of three" << endl;
       return 0;
    }
    vector<vector<int> > board(boardSize, vector<int>(boardSize, 0));
    cout << solvable(board, boardSize) << endl;
    while(!solvable(board, boardSize)) {
        std::random_device ranDevice; // generates the random numbers to constantly make a different sudoku
        std::mt19937 gen(ranDevice());
        std::uniform_int_distribution<int> boardDist(0, boardSize - 1);
        std::uniform_int_distribution<int> insertDist(1, 9);
        int ranRowIndex = boardDist(gen);
        int ranColIndex = boardDist(gen);
        int insertedNumber = insertDist(gen);
        if(!sudoSolver::numberInRow(boardSize, board, ranRowIndex, insertedNumber)
           && !sudoSolver::numberInColumn(boardSize, board, ranColIndex, insertedNumber)
           && !sudoSolver::numberInBox(board, (ranRowIndex - ranRowIndex % 3), (ranColIndex - ranColIndex % 3), insertedNumber)) {
            board[ranRowIndex][ranColIndex] = insertedNumber;
        }
    }
    for(int i = 0; i < boardSize; ++i) {
        for(int j = 0; j < boardSize; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}