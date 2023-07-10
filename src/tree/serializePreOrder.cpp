// 这是按前序遍历写的力扣上可以通过，但是data一定要以#结尾，因为反序列化时index可能为-1
#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
string serialize(TreeNode* root);
TreeNode* deserialize(string data);
TreeNode* deserializeHelper(string& data);
void destroy(TreeNode* root);
int main() {
    string data = "1,2,3,#,#,4,5,#,#,#,#";
    auto root = deserialize(data);
    auto res = serialize(root);
    cout << res << endl;
    destroy(root);
    return 0;
}
string serialize(TreeNode* root) {
    if (root == nullptr) return "#";
    string result = to_string(root->val) + ",";
    result += serialize(root->left) + ",";
    result += serialize(root->right);
    return result;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) { return deserializeHelper(data); }
TreeNode* deserializeHelper(string& data) {
    if (data[0] == '#') {
        if (data.size() > 2) data = data.substr(2);
        return nullptr;
    }
    int index = data.find(",");
    int val = stoi(data.substr(0, index));
    auto root = new TreeNode(val);
    data = data.substr(index + 1);
    root->left = deserializeHelper(data);
    root->right = deserializeHelper(data);
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