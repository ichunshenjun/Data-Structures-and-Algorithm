// 1254
#include <iostream>
#include <vector>
using namespace std;
int closedIsland(vector<vector<int>>& grid);
void DFS(vector<vector<int>>& grid, int i, int j);
int main() {
    vector<vector<int>> grid = {{1, 1, 1, 1, 1, 1, 1, 0},
                                {1, 0, 0, 0, 0, 1, 1, 0},
                                {1, 0, 1, 0, 1, 1, 1, 0},
                                {1, 0, 0, 0, 0, 1, 0, 1},
                                {1, 1, 1, 1, 1, 1, 1, 0}};
    cout << closedIsland(grid) << endl;
    return 0;
}
int closedIsland(vector<vector<int>>& grid) {
    int res = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int j = 0; j < n; j++) {
        if (grid[0][j] == 0) DFS(grid, 0, j);
        if (grid[m - 1][j] == 0) DFS(grid, m - 1, j);
    }
    for (int i = 0; i < m; i++) {
        if (grid[i][0] == 0) DFS(grid, i, 0);
        if (grid[i][n - 1] == 0) DFS(grid, i, n - 1);
    }
    for (int i = 1; i < m - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (grid[i][j] == 0) {
                res++;
                DFS(grid, i, j);
            }
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
    if (grid[i][j] == 1) return;
    grid[i][j] = 1;
    DFS(grid, i - 1, j);
    DFS(grid, i + 1, j);
    DFS(grid, i, j - 1);
    DFS(grid, i, j + 1);
}