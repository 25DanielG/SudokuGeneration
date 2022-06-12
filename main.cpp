#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::pair;

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

pair<int, int> findUnassignedSlots(vector<vector<int> > board) {
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

bool solveSudoku(vector<vector<int> > &board) { // Board includes sudoku puzzle with 0's in place of empty spots
    pair<int, int> check = findUnassignedSlots(board);
    if(check.first == -1 && check.second == -1) return false; // Sudoku is filled
    for(int n = 1; n <= 9; ++n) { // Loop through possible numbers
        if(!numberInColumn(board, check.second, n) && !numberInRow(board, check.first, n) && !numberInBox(board, (check.first - check.first % 3), (check.second - check.second % 3), n)) {
            board[check.first][check.second] = n;
            if(solveSudoku(board)) return true;
            board[check.first][check.second] = 0;
        }
    }
    return false;
}

int main() {
    cin >> boardSize;
    if(boardSize % 3 != 0) {
        cout << "Board size must be a multiple of three" << endl;
        cin >> boardSize;
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
    /*{3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 1, 0, 0, 8, 0},
    {9, 0, 0, 8, 6, 3, 0, 0, 5},
    {0, 5, 0, 0, 9, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0}*/
    if(solveSudoku(board)) {
        cout << "Inside if statement" << endl;
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
}