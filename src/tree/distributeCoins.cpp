// 979
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
int res = 0;
TreeNode* deserialBinaryTree(vector<int>& data);
int traverse(TreeNode* root);
int distributeCoins(TreeNode* root);
void destroy(TreeNode* root);
int main() {
    vector<int> data = {1, 0, 0, null, 3};
    auto root = deserialBinaryTree(data);
    cout << distributeCoins(root) << endl;
    destroy(root);
    return 0;
}
int distributeCoins(TreeNode* root) {
    traverse(root);
    return res;
}
int traverse(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    root->val += traverse(root->left);
    root->val += traverse(root->right);
    res += abs(root->val - 1);
    return root->val - 1;
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