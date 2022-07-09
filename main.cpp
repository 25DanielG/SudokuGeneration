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
vector<vector<int> > bestBoard(boardSize, vector<int>(boardSize, 0));

void generateSudoku(const int boardSize, int solutionCount, vector<vector<int> > &board, int &maxRemovedElements) {
    cout << "MaxRemovedElements: " << maxRemovedElements << endl;
    if(maxRemovedElements >= 50) return;
    for(int i = 0; i < boardSize; ++i) {
        for(int j = 0; j < boardSize; ++j) {
            std::random_device ranDevice; // generates the random numbers to constantly make a different sudok
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
void vectorShuffle(vector<int> &arr, int indexOne, int indexTwo) {
    int tmp = arr[indexOne];
    arr[indexOne] = arr[indexTwo];
    arr[indexTwo] = tmp;
}
int main() {
    vector<vector<int> > board(boardSize, vector<int>(boardSize, 0));
    vector<int> allowedNums(boardSize, 0);
    for(int i = 0; i < boardSize; ++i) {
        allowedNums[i] = i + 1;
    }
    int solutionCount = 0, numUnassigned = INT16_MIN;
    auto start = high_resolution_clock::now();
    sudoSolver::solveSudoku(boardSize, board, allowedNums);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Search for solution: " << duration.count() << " milliseconds" << endl;
    generateSudoku(boardSize, solutionCount, board, numUnassigned);
    cout << endl << "Printed sudoku" << endl << "-----------------" << endl;
    for(int i = 0; i < boardSize; ++i) {
        if(i % 3 == 0) {
            cout << " ____________________________" << endl;
        }
        for(int j = 0; j < boardSize; ++j) {
            if(j % 3 == 0) {
                cout << " | ";
            }
            cout << bestBoard[i][j] << " ";
        }
        cout << " | " << endl;
    }
    cout << " ____________________________ " << endl;
}