// 773
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
struct Board {
    string str;
    int pos;
};
int slidingPuzzle(vector<vector<int>>& board);
int main() {
    vector<vector<int>> board = {{1, 2, 3}, {5, 4, 0}};
    cout << slidingPuzzle(board) << endl;
    return 0;
}
int slidingPuzzle(vector<vector<int>>& board) {
    int res = 0;
    unordered_set<string> visited;
    queue<Board> q;
    string str;
    int pos = 0;
    int find = 0;
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 2; j++) {
            if (board[i][j] != 0 && !find) pos++;
            if (board[i][j] == 0) find = 1;
            str += to_string(board[i][j]);
        }
    }
    q.push(Board{str, pos});
    visited.insert(q.back().str);
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            Board b = q.front();
            q.pop();
            if (b.str == "123450") {
                return res;
            }
            Board temp = b;
            int index = b.pos >= 3 ? b.pos - 3 : b.pos + 3;
            swap(temp.str[b.pos], temp.str[index]);
            if (!visited.count(temp.str)) {
                q.push(Board{temp.str, index});
                visited.insert(q.back().str);
            }
            if (b.pos == 0 || b.pos == 2) {
                temp = b;
                index = 1;
                swap(temp.str[b.pos], temp.str[index]);
                if (!visited.count(temp.str)) {
                    q.push(Board{temp.str, index});
                    visited.insert(q.back().str);
                }
            } else if (b.pos == 3 || b.pos == 5) {
                temp = b;
                index = 4;
                swap(temp.str[b.pos], temp.str[index]);
                if (!visited.count(temp.str)) {
                    q.push(Board{temp.str, index});
                    visited.insert(q.back().str);
                }
            } else {
                temp = b;
                index = b.pos + 1;
                swap(temp.str[b.pos], temp.str[index]);
                if (!visited.count(temp.str)) {
                    q.push(Board{temp.str, index});
                    visited.insert(q.back().str);
                }
                temp = b;
                index = b.pos - 1;
                swap(temp.str[b.pos], temp.str[index]);
                if (!visited.count(temp.str)) {
                    q.push(Board{temp.str, index});
                    visited.insert(q.back().str);
                }
            }
        }
        res++;
    }
    return -1;
}