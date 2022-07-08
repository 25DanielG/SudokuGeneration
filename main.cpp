#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "./src/sudosolver.h"
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::pair;

/** 
 * Compiling commands:
 * cd src
 * g++ lib_sudosolver.cc main.cpp -o sudoSolver (compile command)
 * ./sudoSolver (exec command)
 */

int boardSize = 9; // typical size for sudoku

/*void generateSudoku(const int boardSize, int solutionCount, vector<vector<int> > &board) {
    
    //cout << "insertedNumber: " << insertedNumber << endl;
    cout << "BET" << endl;
    if(!sudoSolver::numberInRow(boardSize, board, ranRowIndex, insertedNumber)
    && !sudoSolver::numberInColumn(boardSize, board, ranColIndex, insertedNumber)
    && !sudoSolver::numberInBox(board, (ranRowIndex - ranRowIndex % 3), (ranColIndex - ranColIndex % 3), insertedNumber)) {
        board[ranRowIndex][ranColIndex] = insertedNumber;
        for(int i = 0; i < boardSize; ++i) {
            for(int j = 0; j < boardSize; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        sudoSolver::isOneSolution(boardSize, board, solutionCount);
        if(solutionCount == 0)
            board[ranRowIndex][ranColIndex] = 0; // reset slot if there are no solutioms
    }
    cout << "solutionCount: " << solutionCount << endl;
    generateSudoku(boardSize, 0, board);
}*/
int main() {
    vector<vector<int> > board(boardSize, vector<int>(boardSize, 0));
    vector<int> allowedNums;
    for(int i = 1; i < boardSize; ++i) {
        allowedNums.push_back(i);
    }
    for(int i = 0; i < boardSize; ++i) {
        cout << allowedNums[i] << " ";
    }
    int solutionCount = 0;
    sudoSolver::solveSudoku(boardSize, board, allowedNums);
    /*std::random_device ranDevice; // generates the random numbers to constantly make a different sudoku
    std::mt19937 gen2(ranDevice());
    std::uniform_int_distribution<int> boardDist(0, boardSize - 1);
    std::uniform_int_distribution<int> insertDist(1, 9);
    int ranRowIndex = boardDist(gen2);
    int ranColIndex = boardDist(gen2);
    int insertedNumber = insertDist(gen2);*/
    cout << "Printed sudoku" << endl << "-----------------" << endl;
    for(int i = 0; i < boardSize; ++i) {
        for(int j = 0; j < boardSize; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}