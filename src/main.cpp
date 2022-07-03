#include <iostream>
#include <vector>
#include <random>
#include <chrono>
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

int boardSize = 9; // typical size for sudoku
bool solvable(vector<vector<int> > &board, const int boardSize) {
    return (sudoSolver::solveSudoku(boardSize, board));
}
void generateSudoku(const int boardSize, int solutionCount, vector<vector<int> > &board) {
    if(solutionCount == 1) {
        cout << "solutionCount is 1" << endl;
        return;
    }
    std::random_device ranDevice; // generates the random numbers to constantly make a different sudoku
    std::mt19937 gen2(ranDevice());
    std::uniform_int_distribution<int> boardDist(0, boardSize - 1);
    std::uniform_int_distribution<int> insertDist(1, 9);
    int ranRowIndex = boardDist(gen2);
    int ranColIndex = boardDist(gen2);
    int insertedNumber = insertDist(gen2);
    //cout << "insertedNumber: " << insertedNumber << endl;
    if(!sudoSolver::numberInRow(boardSize, board, ranRowIndex, insertedNumber)
    && !sudoSolver::numberInColumn(boardSize, board, ranColIndex, insertedNumber)
    && !sudoSolver::numberInBox(board, (ranRowIndex - ranRowIndex % 3), (ranColIndex - ranColIndex % 3), insertedNumber)) {
        board[ranRowIndex][ranColIndex] = insertedNumber;
        sudoSolver::isOneSolution(boardSize, board, solutionCount);
    }
    cout << "solutionCount: " << solutionCount << endl;
    if(solutionCount > 1 || solutionCount == 0) generateSudoku(boardSize, 0, board);
}
int main() {
    vector<vector<int> > board(boardSize, vector<int>(boardSize, 0));
    int solutionCount = 0;
    generateSudoku(boardSize, solutionCount, board);
    cout << "Printed sudoku" << endl << "-----------------" << endl;
    for(int i = 0; i < boardSize; ++i) {
        for(int j = 0; j < boardSize; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}