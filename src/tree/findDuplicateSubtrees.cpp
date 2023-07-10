#include <cstddef>
#include <cstdio>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#define null 0
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
vector<TreeNode*> res;
unordered_map<string, int> tree;
void destroy(TreeNode* root);
string serialize(TreeNode* root);
TreeNode* deserialBinaryTree(vector<int>& data);
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root);
int main() {
    vector<int> data = {1, 2, 3, 4, null, 2, 4, null, null, 4};
    auto root = deserialBinaryTree(data);
    destroy(root);
    return 0;
}
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    serialize(root);
    return res;
}
string serialize(TreeNode* root) {
    if (root == nullptr) return "#";
    auto left = serialize(root->left);
    auto right = serialize(root->right);
    std::string str = std::to_string(root->val);
    ;
    string subTree = left + "," + right + "," + str;
    if (tree[subTree] != -1) tree[subTree]++;
    if (tree[subTree] > 1) {
        tree[subTree] = -1;
        res.emplace_back(root);
    }
    return subTree;
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
    if (root == nullptr) {
        return;
    }
    destroy(root->left);
    destroy(root->right);
    delete root;
    root = nullptr;
}