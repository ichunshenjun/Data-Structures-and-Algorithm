#include <iostream>
#include <vector>
using namespace std;
bool equationsPossible(vector<string>& equations);
class UF {
private:
    int count;
    int* parent;

public:
    UF(int n) {
        this->count = n;
        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    ~UF() { delete[] parent; }
    void union_(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;
        parent[rootQ] = rootP;
        count--;
    }
    bool connected(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }
    int count_() { return count; }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
};
int main() {
    vector<string> equations = {"a==b", "b==c", "a==c"};
    cout << equationsPossible(equations);
    return 0;
}
bool equationsPossible(vector<string>& equations) {
    vector<vector<int>> graph;
    graph = vector<vector<int>>(equations.size());
    UF uf(26);
    for (auto edge : equations) {
        if (edge[1] == '=') {
            // graph[edge[0]].emplace_back(edge[3]);
            // graph[edge[3]].emplace_back(edge[0]);
            uf.union_(edge[0] - 'a', edge[3] - 'a');
        }
    }
    for (auto edge : equations) {
        if (edge[1] == '!') {
            if (uf.connected(edge[0] - 'a', edge[3] - 'a')) {
                return false;
            }
        }
    }
    return true;
}