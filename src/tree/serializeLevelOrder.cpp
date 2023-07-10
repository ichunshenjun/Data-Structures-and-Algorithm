// 这是按层序遍历写的力扣上内存溢出
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
void destroy(TreeNode* root);
int main() {
    string data = "1,2,3,null,null,4,5";
    auto root = deserialize(data);
    auto res = serialize(root);
    cout << res << endl;
    destroy(root);
    return 0;
}
string serialize(TreeNode* root) {
    if (root == nullptr) return "";
    string data;
    queue<TreeNode*> queue;
    queue.emplace(root);
    data += to_string(root->val);
    data += ",";
    while (!queue.empty()) {
        auto front = queue.front();
        queue.pop();
        if (front->left) {
            queue.emplace(front->left);
            data += to_string(front->left->val);
        } else {
            data += "null";
        }
        data += ",";
        if (front->right) {
            queue.emplace(front->right);
            data += to_string(front->right->val);
        } else {
            data += "null";
        }
        data += ",";
    }
    return data;
}
TreeNode* deserialize(string data) {
    if (data.size() == 0) return nullptr;
    int index = data.find(",");
    int val = stoi(data.substr(0, index));
    data = data.substr(index + 1);
    auto root = new TreeNode(val);
    queue<TreeNode*> queue;
    queue.emplace(root);
    while (data.size() != 0) {
        TreeNode* front = queue.front();
        queue.pop();
        index = data.find(",");
        string subdata = data.substr(0, index);
        if (index == -1) {
            subdata = data;
        }
        if (subdata != "null") {
            int val = stoi(data.substr(0, index));
            auto left = new TreeNode(val);
            front->left = left;
            queue.emplace(left);
        }
        if (index == -1) {
            break;
        }
        data = data.substr(index + 1);
        index = data.find(",");
        subdata = data.substr(0, index);
        if (index == -1) {
            subdata = data;
        }
        if (data != "" && subdata != "null") {
            int val = stoi(data.substr(0, index));
            auto right = new TreeNode(val);
            front->right = right;
            queue.emplace(right);
        }
        if (index == -1) {
            break;
        }
        data = data.substr(index + 1);
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