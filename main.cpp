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
using namespace std::chrono;

const int boardSize = 9; // typical size for sudoku
vector<vector<int> > bestBoard;

void generateSudoku(const int boardSize, int solutionCount, vector<vector<int> > &board, int &maxRemovedElements) {
    if(maxRemovedElements >= 51) return;
    for(int i = 0; i < boardSize; ++i) {
        for(int j = 0; j < boardSize; ++j) {
            std::random_device ranDevice; // generates the random numbers to constantly make a different sudoku
            std::mt19937 gen2(ranDevice());
            std::uniform_int_distribution<int> boardDist(0, boardSize - 1);
            int ranRowIndex = boardDist(gen2);
            int ranColIndex = boardDist(gen2);
            int tmp = board[ranRowIndex][ranColIndex];
            board[ranRowIndex][ranColIndex] = 0;
            auto start = high_resolution_clock::now();
            int tmpSolutions = sudoSolver::isOneSolution(i, j, board, 0, boardSize);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start);
            cout << "Search for solution: " << duration.count() << " milliseconds" << endl;
            if(tmpSolutions == 1) {
                solutionCount = 0;
                int numUnfilled = sudoSolver::countUnassignedSlots(board);
                if(numUnfilled > maxRemovedElements) {
                    maxRemovedElements = numUnfilled;
                    bestBoard = board;
                    cout << "Number of zeros: " << numUnfilled << endl;
                }
                generateSudoku(boardSize, solutionCount, board, maxRemovedElements);
            }
            board[ranRowIndex][ranColIndex] = tmp;
        }
    }
}
int main() {
    vector<vector<int> > board(boardSize, vector<int>(boardSize, 0));
    vector<int> allowedNums(boardSize);
    for(int i = 1; i <= boardSize; ++i) {
        allowedNums.push_back(i);
    }
    int solutionCount = 0, numUnassigned = 0;
    auto start = high_resolution_clock::now();
    sudoSolver::solveSudoku(boardSize, board, allowedNums);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Search for solution: " << duration.count() << " milliseconds" << endl;
    generateSudoku(boardSize, solutionCount, board, numUnassigned);
    cout << endl << "Printed sudoku" << endl << "-----------------" << endl;
    for(int i = 0; i < boardSize; ++i) {
        for(int j = 0; j < boardSize; ++j) {
            cout << bestBoard[i][j] << " ";
        }
        cout << endl;
    }
}