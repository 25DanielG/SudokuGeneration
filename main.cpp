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

const int boardSize = 9; // typical size for sudoku

void generateSudoku(const int boardSize, int solutionCount, vector<vector<int> > &board) {
    for(int i = 0; i < boardSize; ++i) {
        for(int j = 0; j < boardSize; ++j) {
            std::random_device ranDevice; // generates the random numbers to constantly make a different sudoku
            std::mt19937 gen2(ranDevice());
            std::uniform_int_distribution<int> boardDist(0, boardSize - 1);
            int ranRowIndex = boardDist(gen2);
            int ranColIndex = boardDist(gen2);
            board[ranRowIndex][ranColIndex] = 0;
            if(sudoSolver::isOneSolution(boardSize, board, solutionCount) && solutionCount == 1) {
                solutionCount = 0;
                generateSudoku(boardSize, solutionCount, board);
            }
            return;
        }
    }
}
int main() {
    vector<vector<int> > board(boardSize, vector<int>(boardSize, 0));
    vector<int> allowedNums(boardSize);
    for(int i = 1; i <= boardSize; ++i) {
        allowedNums.push_back(i);
    }
    int solutionCount = 0;
    sudoSolver::solveSudoku(boardSize, board, allowedNums);
    generateSudoku(boardSize, solutionCount, board);
    cout << endl << "Printed sudoku" << endl << "-----------------" << endl;
    for(int i = 0; i < boardSize; ++i) {
        for(int j = 0; j < boardSize; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}