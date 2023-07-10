#include <cstddef>
#include <iostream>
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
TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder);
TreeNode* construct(vector<int>& preorder, int preStart, int preEnd, vector<int>& postorder, int postStart,
                    int postEnd);
void destroy(TreeNode* root);
int main() {
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};
    auto root = constructFromPrePost(preorder, postorder);
    destroy(root);
    return 0;
}
TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    return construct(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
}
TreeNode* construct(vector<int>& preorder, int preStart, int preEnd, vector<int>& postorder, int postStart,
                    int postEnd) {
    if (preStart > preEnd) return nullptr;
    if (preStart == preEnd) return new TreeNode(preorder[preStart]);
    int rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);
    int leftVal = preorder[preStart + 1];
    int index = 0;
    for (int i = postStart; i <= postEnd; i++) {
        if (postorder[i] == leftVal) {
            index = i;
            break;
        }
    }
    root->left = construct(preorder, preStart + 1, preStart + index - postStart + 1, postorder, postStart, index);
    root->right = construct(preorder, preStart + index - postStart + 2, preEnd, postorder, index + 1, postEnd - 1);
    return root;
}
void destroy(TreeNode* root) {
    if (root == nullptr) return;
    destroy(root->left);
    destroy(root->right);
    delete (root);
    root = nullptr;
}