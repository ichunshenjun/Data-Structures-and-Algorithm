// 143
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
void reorderList(ListNode* head);
ListNode* buildList(vector<int>& nums);
ListNode* reverseList(ListNode* head);
void destoryList(ListNode* head);
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    auto head = buildList(nums);
    ListNode* temp = head;
    reorderList(head);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    destoryList(temp);
    return 0;
}
void reorderList(ListNode* head) {
    ListNode* cur = head;
    while (cur) {
        cur->next = reverseList(cur->next);
        cur = cur->next;
    }
}
ListNode* reverseList(ListNode* head) {
    if (head == nullptr) {
        return head;
    }
    ListNode* cur = head->next;
    ListNode* pre = head;
    while (cur) {
        ListNode* temp = cur->next;
        pre->next = cur->next;
        cur->next = head;
        head = cur;
        cur = temp;
    }
    return head;
}
ListNode* buildList(vector<int>& nums) {
    ListNode dummy;
    ListNode* node = nullptr;
    ListNode* cur = &dummy;
    for (auto num : nums) {
        node = new ListNode(num);
        cur->next = node;
        cur = cur->next;
    }
    return dummy.next;
}
void destoryList(ListNode* head) {
    auto cur = head;
    while (cur) {
        auto del = cur;
        cur = cur->next;
        delete del;
        del = nullptr;
    }
}