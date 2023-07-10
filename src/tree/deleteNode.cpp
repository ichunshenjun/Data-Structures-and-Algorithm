#include <iostream>
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
TreeNode* deleteNode(TreeNode* root, int key);
TreeNode* deserialBinaryTree(vector<int>& data);
TreeNode* traverse(TreeNode* root, int key);
void destroy(TreeNode* root);
int main() {
    vector<int> data = {5, 3, 6, 2, 4, null, 7};
    auto root = deserialBinaryTree(data);
    int key = 3;
    deleteNode(root, key);
    destroy(root);
    return 0;
}
TreeNode* deleteNode(TreeNode* root, int key) {
    root = traverse(root, key);
    return root;
}
TreeNode* traverse(TreeNode* root, int key) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->val == key) {
        auto right = root->right;
        auto left = root->left;
        if (left == nullptr && right == nullptr) {
            delete root;
            return nullptr;
        } else if (left && right == nullptr) {
            delete root;
            return left;
        } else if (right && left == nullptr) {
            delete root;
            return right;
        } else {
            auto p = root->right;
            while (p->left) {
                p = p->left;
            }
            p->left = left;
            delete root;
            return right;
        }
    } else if (root->val > key) {
        root->left = traverse(root->left, key);
    } else if (root->val < key) {
        root->right = traverse(root->right, key);
    }
    return root;
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