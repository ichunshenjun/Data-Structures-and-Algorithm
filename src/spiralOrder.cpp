#include <iostream>
#include <vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix);
int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    spiralOrder(matrix);
    return 0;
}
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int left_bound = 0, right_bound = matrix[0].size() - 1, upper_bound = 0, lower_bound = matrix.size() - 1;
    int i = 0, j = 0;
    vector<int> res;
    while (static_cast<int>(res.size()) < m * n) {
        if (upper_bound <= lower_bound) {
            for (j = left_bound; j <= right_bound; j++) {
                res.emplace_back(matrix[upper_bound][j]);
            }
            upper_bound++;
        }
        if (left_bound <= right_bound) {
            for (i = upper_bound; i <= lower_bound; i++) {
                res.emplace_back(matrix[i][right_bound]);
            }
            right_bound--;
        }

        if (upper_bound <= lower_bound) {
            for (j = right_bound; j >= left_bound; j--) {
                res.emplace_back(matrix[lower_bound][j]);
            }
            lower_bound--;
        }

        if (left_bound <= right_bound) {
            for (i = lower_bound; i >= upper_bound; i--) {
                res.emplace_back(matrix[i][left_bound]);
            }
            left_bound++;
        }
    }
    for (i = 0; i < static_cast<int>(res.size()); i++) cout << res[i] << " ";
    cout << endl;
    return res;
}