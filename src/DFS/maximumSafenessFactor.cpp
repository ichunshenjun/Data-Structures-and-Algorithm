#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> dis;
int visited[500][500];
int maximumSafenessFactor(vector<vector<int>>& grid);
bool DFS(vector<vector<int>>& grid, int x, int y, int minDist);
bool isValid(vector<vector<int>>& grid, int nx, int ny);
int main() {
    // vector<vector<int>> grid={{0,0,0,1},{0,0,0,0},{0,0,0,0},{1,0,0,0}};
    vector<vector<int>> grid = {{0, 1, 1}, {0, 0, 0}, {0, 0, 0}};
    cout << maximumSafenessFactor(grid);
    return 0;
}
int maximumSafenessFactor(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    dis = vector<vector<int>>(m, vector<int>(n, -1));
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                if (i == 0 && j == 0) {
                    return 0;
                }
                if (i == n - 1 && j == n - 1) {
                    return 0;
                }
                q.push({i, j});
                dis[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            auto front = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = dx[i] + front.first;
                int ny = dy[i] + front.second;
                if (isValid(grid, nx, ny) && dis[nx][ny] == -1) {
                    dis[nx][ny] = dis[front.first][front.second] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    int left = 0, right = 2 * n;
    int res;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        memset(visited, 0, sizeof(visited));
        visited[0][0] = 1;
        if (DFS(grid, 0, 0, mid) && dis[0][0] >= mid) {
            res = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return res;
}
bool DFS(vector<vector<int>>& grid, int x, int y, int minDist) {
    int n = grid.size();
    if (x == n - 1 && y == n - 1) {
        return true;
    }
    for (int i = 0; i < 4; i++) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (isValid(grid, nx, ny) && !visited[nx][ny] && dis[nx][ny] >= minDist) {
            visited[nx][ny] = 1;
            if (DFS(grid, nx, ny, minDist)) return true;
        }
    }
    return false;
}
bool isValid(vector<vector<int>>& grid, int nx, int ny) {
    int m = grid.size();
    int n = grid[0].size();
    if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
        return false;
    }
    return true;
}