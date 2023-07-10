#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
TreeNode* constructMaximumBinaryTree(vector<int>& nums);
TreeNode* construct(vector<int>& nums, int left, int right);
void destroy(TreeNode* root);
int main() {
    vector<int> nums = {3, 2, 1, 6, 0, 5};
    auto root = constructMaximumBinaryTree(nums);
    destroy(root);
    return 0;
}
TreeNode* constructMaximumBinaryTree(vector<int>& nums) { return construct(nums, 0, nums.size() - 1); }
TreeNode* construct(vector<int>& nums, int left, int right) {
    if (left > right) return nullptr;
    auto itr = max_element(nums.begin() + left, nums.begin() + right + 1);
    int index = itr - nums.begin();
    int rootVal = *itr;
    cout << index << " " << rootVal << endl;
    TreeNode* root = new TreeNode(rootVal);
    root->left = construct(nums, left, index - 1);
    root->right = construct(nums, index + 1, right);
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