// 51
#include <iostream>
#include <vector>
using namespace std;
vector<vector<string>> res;
vector<vector<string>> solveNQueens(int n);
void backtrace(vector<string>& board, int n, int row);
bool isValid(vector<string>& board, int row, int col);
int main() {
    int n = 4;
    solveNQueens(n);
    return 0;
}
vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    backtrace(board, n, 0);
    return res;
}
void backtrace(vector<string>& board, int n, int row) {
    if (row == (int)board.size()) {
        res.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (!isValid(board, row, col)) {
            continue;
        }
        board[row][col] = 'Q';
        backtrace(board, n, row + 1);
        board[row][col] = '.';
    }
}
bool isValid(vector<string>& board, int row, int col) {
    int n = board.size();
    for (int i = 0; i < n; i++) {
        if (board[i][col] == 'Q') return false;
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }
    return true;
}