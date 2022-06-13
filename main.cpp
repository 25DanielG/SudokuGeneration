#include <iostream>
#include <vector>
#include "sudosolver.h"
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::pair;
// g++ lib_sudosolver.cc main.cpp -o sudoSolver (compile command)
// ./sudoSolver (exec command)
int main() {
    int boardSize; // must be a multiple of 3
    cin >> boardSize;
    if(boardSize % 3 != 0) {
        cout << "Board size must be a multiple of three" << endl;
       return 0;
    }
    vector<vector<int> > board;
    for(int i = 0; i < boardSize; ++i) {
        vector<int> temp;
        for(int j = 0; j < boardSize; ++j) {
            int tmp;
            cin >> tmp;
            temp.push_back(tmp);
        }
        board.push_back(temp);
    }
    if(sudoSolver::solveSudoku(boardSize, board)) {
        cout << "Solved: " << endl;
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Cannot be solved" << endl;
    }
}