#include <iostream>
#include <vector>
using namespace std;
vector<vector<bool>> visited;
void solve(vector<vector<char>>& board);
void DFS(vector<vector<char>>& board, int x, int y);
bool judge(vector<vector<char>>& board, int x, int y);
int main() {
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    int m = board.size();
    int n = board[0].size();
    solve(board);
    for (int i = 0; i <= m - 1; i++) {
        for (int j = 0; j <= n - 1; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    visited = vector<vector<bool>>(m, vector<bool>(n));
    for (int i = 0; i <= m - 1; i++) {
        DFS(board, i, 0);
        DFS(board, i, n - 1);
    }
    for (int j = 0; j <= n - 1; j++) {
        DFS(board, 0, j);
        DFS(board, m - 1, j);
    }
    for (int i = 0; i <= m - 1; i++)
        for (int j = 0; j <= n - 1; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    for (int i = 0; i <= m - 1; i++)
        for (int j = 0; j <= n - 1; j++) {
            if (board[i][j] == 'N') {
                board[i][j] = 'O';
            }
        }
}
void DFS(vector<vector<char>>& board, int x, int y) {
    if (visited[x][y]) {
        return;
    }
    visited[x][y] = true;
    if (board[x][y] == 'X') return;
    if (board[x][y] == 'O') board[x][y] = 'N';
    if (judge(board, x + 1, y) && !visited[x + 1][y]) DFS(board, x + 1, y);
    if (judge(board, x - 1, y) && !visited[x - 1][y]) DFS(board, x - 1, y);
    if (judge(board, x, y + 1) && !visited[x][y + 1]) DFS(board, x, y + 1);
    if (judge(board, x, y - 1) && !visited[x][y - 1]) DFS(board, x, y - 1);
}
bool judge(vector<vector<char>>& board, int x, int y) {
    int m = board.size();
    int n = board[0].size();
    if (x <= m - 1 && x >= 0 && y <= n - 1 && y >= 0) return true;
    return false;
}