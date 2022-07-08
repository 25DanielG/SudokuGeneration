#ifndef SUDOSOLVER_H_
#define SUDOSOLVER_H_
#include <vector>
using std::vector;
namespace sudoSolver {
    bool numberInColumn(int boardSize, vector<vector<int> > board, int c, int n); // checks if a number is in the column
    bool numberInRow(int boardSize, vector<vector<int> > board, int r, int n); // checks if a number is in the row
    bool numberInBox(vector<vector<int> > board, int startR, int startC, int n); // checks if a number is in the box
    std::pair<int, int> findUnassignedSlots(vector<vector<int> > &board); // finds empty slots on the board
    bool solveSudoku(int boardSize, vector<vector<int> > &board, vector<int> allowedNums); // board includes sudoku puzzle with 0's in place of empty spots
    bool isOneSolution(int boardSize, vector<vector<int> > board, int &solutionCount); // checks if there is one solution to a sudoku puzzle
    // vectors are not reference for solvers in order to not break code
}
#endif