#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generateMatrix(int n);
int main() {
    int n = 3;
    auto ans = generateMatrix(n);
    for (size_t i = 0; i < ans.size(); i++) {
        for (size_t j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix{vector<vector<int>>(n, vector<int>(n))};
    int left_bound = 0, upper_bound = 0, right_bound = n - 1, lower_bound = n - 1, cnt = 1;
    while (cnt <= n * n) {
        if (upper_bound <= lower_bound) {
            for (int j = left_bound; j <= right_bound; j++) {
                matrix[upper_bound][j] = cnt;
                cnt++;
            }
            upper_bound++;
        }
        if (left_bound <= right_bound) {
            for (int i = upper_bound; i <= lower_bound; i++) {
                matrix[i][right_bound] = cnt;
                cnt++;
            }
            right_bound--;
        }
        if (upper_bound <= lower_bound) {
            for (int j = right_bound; j >= left_bound; j--) {
                matrix[lower_bound][j] = cnt;
                cnt++;
            }
            lower_bound--;
        }
        if (left_bound <= right_bound) {
            for (int i = lower_bound; i >= upper_bound; i--) {
                matrix[i][left_bound] = cnt;
                cnt++;
            }
            left_bound++;
        }
    }
    return matrix;
}