// 1020
#include <iostream>
#include <vector>
using namespace std;
vector<vector<bool>> visited;
int numEnclaves(vector<vector<int>>& grid);
void DFS(vector<vector<int>>& grid, int i, int j);
int main() {
    vector<vector<int>> grid = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    cout << numEnclaves(grid) << endl;
    return 0;
}
int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int res = 0;
    visited = vector<vector<bool>>(m, vector<bool>(n, false));
    for (int j = 0; j < n; j++) {
        if (grid[0][j] == 1) DFS(grid, 0, j);
        if (grid[m - 1][j] == 1) DFS(grid, m - 1, j);
    }
    for (int i = 0; i < m; i++) {
        if (grid[i][0] == 1) DFS(grid, i, 0);
        if (grid[i][n - 1] == 1) DFS(grid, i, n - 1);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && grid[i][j] == 1) res++;
        }
    }
    return res;
}
void DFS(vector<vector<int>>& grid, int i, int j) {
    int m = grid.size();
    int n = grid[0].size();
    if (i < 0 || j < 0 || i >= m || j >= n) {
        return;
    }
    if (visited[i][j] || grid[i][j] == 0) return;
    visited[i][j] = true;
    DFS(grid, i - 1, j);
    DFS(grid, i + 1, j);
    DFS(grid, i, j - 1);
    DFS(grid, i, j + 1);
}