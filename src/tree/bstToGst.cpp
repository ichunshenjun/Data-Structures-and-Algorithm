#include <cstdio>
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
long sum = 0;
TreeNode* bstToGst(TreeNode* root);
void traverse(TreeNode* root);
TreeNode* deserialBinaryTree(vector<int>& data);
void destroy(TreeNode* root);
int main() {
    vector<int> data = {4, 1, 6, 0, 2, 5, 7, null, null, null, 3, null, null, null, 8};
    auto root = deserialBinaryTree(data);
    bstToGst(root);
    destroy(root);
    return 0;
}
TreeNode* bstToGst(TreeNode* root) {
    traverse(root);
    return nullptr;
}
void traverse(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    traverse(root->right);
    sum += root->val;
    root->val = sum;
    traverse(root->left);
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
    cout << root->val << " ";
    delete root;
    root = nullptr;
}