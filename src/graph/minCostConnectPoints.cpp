#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int minCostConnectPoints(vector<vector<int>>& points);
class UF {
public:
    UF(int n) {
        parent = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;
        count = n;
    }
    ~UF() { delete[] parent; }
    void union_(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        parent[rootP] = rootQ;
        count--;
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool connected(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }

private:
    int count;
    int* parent;
};
struct Edge {
    int x;
    int y;
    int weight;
};
int main() {
    vector<vector<int>> points = {{3, 12}, {-2, 5}, {-4, 1}};
    cout << minCostConnectPoints(points) << endl;
    return 0;
}
int minCostConnectPoints(vector<vector<int>>& points) {
    int res = 0;
    // vector<vector<int>> edges(points.size(),vector<int>(points.size()));
    vector<Edge> edges;
    for (int i = 0; i < (int)points.size(); i++) {
        for (int j = i + 1; j < (int)points.size(); j++) {
            int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            // edges[i][j]=weight;
            // edges[j][i]=weight;
            edges.emplace_back(Edge{i, j, weight});
        }
    }
    UF uf(points.size());
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.weight < b.weight; });
    for (int i = 0; i < (int)edges.size(); i++) {
        if (!uf.connected(edges[i].x, edges[i].y)) {
            uf.union_(edges[i].x, edges[i].y);
            res += edges[i].weight;
        }
    }
    return res;
}