#include <iostream>
#include <vector>
using namespace std;
int main() {
    int H, V, M;
    cin >> H >> V >> M;
    int n;
    vector<vector<int>> nums(V, vector<int>(H, 0));
    int cnt = 0;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < H; j++) {
            nums[i][j] = cnt++;
        }
    }
    int row, col, up, down, left, right;
    for (int i = 0; i < M; i++) {
        cin >> n;
        row = n / H;
        col = n % H;
        if (row - 1 < 0) {
            up = nums[V - 1][col];
        } else {
            up = nums[row - 1][col];
        }
        if (col - 1 < 0) {
            left = -1;
        } else {
            left = nums[row][col - 1];
        }
        if (row + 1 > V - 1) {
            down = nums[0][col];
        } else {
            down = nums[row + 1][col];
        }
        if (col + 1 > H - 1) {
            right = -1;
        } else {
            right = nums[row][col + 1];
        }
        cout << up << " ";
        if (left != -1) cout << left << " ";
        cout << down << " ";
        if (right != -1) cout << right << " ";
        cout << nums[row][col];
        cout << endl;
    }
    return 0;
}