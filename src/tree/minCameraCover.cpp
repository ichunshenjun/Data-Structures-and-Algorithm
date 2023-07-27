// 968
#include <cstdint>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>
#define null -1
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
struct Status {
    int a, b, c;
};
TreeNode* deserialBinaryTree(vector<int>& data);
int minCameraCover(TreeNode* root);
Status traverse(TreeNode* root);
int dp(vector<int>& level, int i);
void destroy(TreeNode* root);
int main() {
    vector<int> data = {0, null, 0, null, 0, null, 0};
    auto root = deserialBinaryTree(data);
    cout << minCameraCover(root) << endl;
    destroy(root);
    return 0;
}
int minCameraCover(TreeNode* root) {
    auto [a, b, c] = traverse(root);
    return b;
}
Status traverse(TreeNode* root) {
    if (root == nullptr) {
        return {INT32_MAX / 2, 0, 0};
    }
    auto [la, lb, lc] = traverse(root->left);
    auto [ra, rb, rc] = traverse(root->right);
    int a = lc + rc + 1;
    int b = min(a, min(la + rb, ra + lb));
    int c = min(a, lb + rb);
    return {a, b, c};
}
TreeNode* deserialBinaryTree(vector<int>& data) {
    if (data.size() == 0) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(data[0]);
    queue<TreeNode*> queue;
    queue.emplace(root);
    for (int i = 1; i < (int)data.size(); i++) {
        TreeNode* front = queue.front();
        queue.pop();
        if (data[i] != null) {
            TreeNode* left = new TreeNode(data[i]);
            front->left = left;
            queue.emplace(left);
        }
        i++;
        if (i < (int)data.size() && data[i] != null) {
            TreeNode* right = new TreeNode(data[i]);
            front->right = right;
            queue.emplace(right);
        }
    }
    return root;
}
void destroy(TreeNode* root) {
    if (root == nullptr) return;
    destroy(root->left);
    destroy(root->right);
    // cout << root->val << " ";
    delete root;
    root = nullptr;
}