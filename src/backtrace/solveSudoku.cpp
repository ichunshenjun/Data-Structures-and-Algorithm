// 37
#include <iostream>
#include <vector>
using namespace std;
void solveSudoku(vector<vector<char>>& board);
bool backtrace(vector<vector<char>>& board, int row, int col);
bool isValid(vector<vector<char>>& board, int row, int col);
int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solveSudoku(board);
    return 0;
}
void solveSudoku(vector<vector<char>>& board) { backtrace(board, 0, 0); }
bool backtrace(vector<vector<char>>& board, int row, int col) {
    if (col == 9) {
        return backtrace(board, row + 1, 0);
    }
    if (row == 9) {
        return true;
    }
    if (board[row][col] != '.') {
        return backtrace(board, row, col + 1);
    }
    for (int i = 1; i <= 9; i++) {
        if (board[row][col] == '.') {
            board[row][col] = '0' + i;
            if (!isValid(board, row, col)) {
                if (backtrace(board, row, col + 1)) return true;
            }
            board[row][col] = '.';
        }
    }
    return false;
}
bool isValid(vector<vector<char>>& board, int row, int col) {
    for (int i = 0; i <= 8; i++) {
        if (i != row && board[row][col] == board[i][col]) return true;
        if (i != col && board[row][col] == board[row][i]) return true;
    }
    int row_start = (row + 1) % 3 == 0 ? ((row + 1) / 3 - 1) * 3 : (row + 1) / 3 * 3;
    int row_end = row_start + 2;
    int col_start = (col + 1) % 3 == 0 ? ((col + 1) / 3 - 1) * 3 : (col + 1) / 3 * 3;
    int col_end = col_start + 2;
    for (int i = row_start; i <= row_end; i++) {
        for (int j = col_start; j <= col_end; j++) {
            if (i == row && j == col) {
                continue;
            }
            if (board[i][j] == board[row][col]) {
                return true;
            }
        }
    }
    return false;
}