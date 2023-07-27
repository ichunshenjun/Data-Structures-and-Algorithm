// 337
#include <iostream>
#include <queue>
#include <unordered_map>
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
unordered_map<TreeNode*, int> memo;
int rob(TreeNode* root);
int dp(TreeNode* root);
TreeNode* deserialBinaryTree(vector<int>& data);
void destroy(TreeNode* root);
int main() {
    vector<int> data = {3, 4, 5, 1, 3, null, 1};
    auto root = deserialBinaryTree(data);
    cout << rob(root) << endl;
    destroy(root);
    return 0;
}
int rob(TreeNode* root) { return dp(root); }
int dp(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    if (memo.count(root)) {
        return memo[root];
    }
    TreeNode* ll = nullptr;
    TreeNode* lr = nullptr;
    TreeNode* rl = nullptr;
    TreeNode* rr = nullptr;
    if (root->left) {
        ll = root->left->left;
        lr = root->left->right;
    }
    if (root->right) {
        rl = root->right->left;
        rr = root->right->right;
    }
    auto res = max(root->val + dp(ll) + dp(lr) + dp(rl) + dp(rr), dp(root->left) + dp(root->right));
    memo[root] = res;
    return res;
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
    delete root;
    root = nullptr;
}