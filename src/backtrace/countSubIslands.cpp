// 1905
#include <iostream>
#include <vector>
using namespace std;
int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2);
void DFS(vector<vector<int>>& grid, int i, int j);
int main() {
    vector<vector<int>> grid1 = {{1, 1, 1, 0, 0}, {0, 1, 1, 1, 1}, {0, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 1, 1}},
                        grid2 = {{1, 1, 1, 0, 0}, {0, 0, 1, 1, 1}, {0, 1, 0, 0, 0}, {1, 0, 1, 1, 0}, {0, 1, 0, 1, 0}};
    cout << countSubIslands(grid1, grid2) << endl;
    return 0;
}
int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int m = grid1.size();
    int n = grid1[0].size();
    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid1[i][j] == 0 && grid2[i][j] == 1) {
                DFS(grid2, i, j);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid2[i][j] == 1) {
                res++;
                DFS(grid2, i, j);
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
    if (grid[i][j] == 0) return;
    grid[i][j] = 0;
    DFS(grid, i - 1, j);
    DFS(grid, i + 1, j);
    DFS(grid, i, j - 1);
    DFS(grid, i, j + 1);
}