#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int m, n;
int startx, starty;
vector<vector<int>> h;
vector<vector<int>> o;
vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
struct Node {
    int x;
    int y;
    int speed;
};
bool isLeagal(int x, int y);
int main() {
    scanf("%d,%d", &m, &n);
    scanf("%d,%d", &startx, &starty);
    h = vector<vector<int>>(m, vector<int>(n, 0));
    o = vector<vector<int>>(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int temp;
            if (j < n - 1)
                scanf("%d,", &temp);
            else
                scanf("%d ", &temp);
            h[i][j] = temp;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int temp;
            if (j < n - 1)
                scanf("%d,", &temp);
            else
                scanf("%d ", &temp);
            o[i][j] = temp;
        }
    }
    int res = 0;
    queue<Node> q;
    unordered_map<int, unordered_set<int>> vis;
    vis[startx * n + starty].insert(1);
    q.push({startx, starty, 1});
    while (!q.empty()) {
        Node front = q.front();
        q.pop();
        for (auto d : dirs) {
            int nextx = front.x + d[0];
            int nexty = front.y + d[1];
            if (isLeagal(nextx, nexty)) {
                int speed = front.speed + (h[front.x][front.y] - h[nextx][nexty] - o[nextx][nexty]);
                if (speed > 0 && vis[nextx * n + nexty].count(speed) == 0) {
                    q.push({nextx, nexty, speed});
                    vis[nextx * n + nexty].insert(speed);
                    if (speed == 1) {
                        res++;
                    }
                }
            }
        }
    }
    cout << res;
    return 0;
}
bool isLeagal(int x, int y) {
    if (x < 0 || x > m - 1 || y < 0 || y > n - 1) return false;
    return true;
}