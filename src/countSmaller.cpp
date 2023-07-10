#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
struct Pair {
    int val, id;
    Pair() : val(0), id(0){};
    Pair(int val, int id) : val(val), id(id){};
};
vector<Pair*> temp;
vector<int> res;
vector<Pair*> arr;
vector<int> countSmaller(vector<int>& nums);
void sort(vector<Pair*>& nums, int left, int right);
void merge(vector<Pair*>& arr, int left, int mid, int right);
int main() {
    vector<int> nums = {26, 78, 27, 100, 33, 67, 90, 23, 66, 5,  38, 7,  35, 23, 52, 22, 83, 51, 98,  69,
                        81, 32, 78, 28,  94, 13, 2,  97, 3,  76, 99, 51, 9,  21, 84, 66, 65, 36, 100, 41};
    countSmaller(nums);
    for (auto num : res) {
        cout << num << " ";
    }
    cout << endl;
    for (int i = 0; i < (int)nums.size(); i++) delete arr[i];
    return 0;
}
vector<int> countSmaller(vector<int>& nums) {
    arr.resize((nums.size()));
    for (int i = 0; i < (int)nums.size(); i++) {
        arr[i] = new Pair(nums[i], i);
    }
    res.resize(nums.size());
    temp.resize(nums.size());
    sort(arr, 0, nums.size() - 1);
    return res;
}
void sort(vector<Pair*>& arr, int left, int right) {
    if (left == right) {
        return;
    }
    int mid = left + (right - left) / 2;
    sort(arr, left, mid);
    sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
void merge(vector<Pair*>& arr, int left, int mid, int right) {
    for (int i = left; i <= right; i++) {
        temp[i] = arr[i];
    }
    int i = left, j = mid + 1;
    for (int p = left; p <= right; p++) {
        if (i == mid + 1) {
            arr[p] = temp[j++];
        } else if (j == right + 1) {
            arr[p] = temp[i++];
            int index = arr[p]->id;
            res[index] += j - mid - 1;
        } else if (temp[i]->val > temp[j]->val) {
            arr[p] = temp[j++];
        } else {
            arr[p] = temp[i++];
            int index = arr[p]->id;
            res[index] += j - mid - 1;
        }
    }
}