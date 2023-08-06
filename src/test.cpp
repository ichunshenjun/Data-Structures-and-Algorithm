#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
// int main() {
//     std::vector<int> nums = {3, 1, 2};
//     auto cmp = [](int a, int b) { return a < b; };
//     sort(nums.begin(), nums.end(), cmp);
//     for (auto num : nums) {
//         //输出：1 2 3
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;
//     std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);
//     pq.push(3);
//     pq.push(1);
//     pq.push(2);

//     while (!pq.empty()) {
//         int top = pq.top();
//         pq.pop();
//         // 输出：3 2 1
//         std::cout << top << " ";
//     }
//     std::cout << std::endl;
//     return 0;
// }
// int main() {
//     list<pair<int, int>> list;
//     unordered_map<int, std::list<pair<int, int>>::iterator> map;
//     list.emplace_front(1, 2);
//     map[1] = list.begin();
//     // list.pop_front();
//     list.emplace_front(3, 4);
//     cout << list.begin()->first << endl;
//     cout << map[1]->first << endl;
//     string test = "abcd";
//     cout << test.substr(0, 1) << endl;

//     vector<string> res[1001];
//     cout << res[0].empty() << endl;

//     return 0;
// }
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> split(const string& s, char delimiter) {  //分割字符串代码
    vector<string> tokens;
    string token;
    size_t start = 0;
    size_t end = s.find(delimiter, start);
    while (end != string::npos) {
        token = s.substr(start, end - start);
        tokens.push_back(token);
        start = end + 1;
        end = s.find(delimiter, start);
    }
    token = s.substr(start, end);
    tokens.push_back(token);
    return tokens;
}

int sift(const vector<vector<int>>& arr, int id1, int id2) {
    const vector<int>& ls1 = arr[id1];
    const vector<int>& ls2 = arr[id2];
    if (ls1[0] - ls2[0] < 10 && ls1[1] == ls2[1]) {  //如果小于10ms且相同
        return 1;
    } else if (ls1[0] - ls2[0] < 100 && ls1[2] == ls2[2]) {  //如果小于100ms且相似
        return 2;
    } else if (ls1[0] - ls2[0] >= 100) {  //如果大于等于100ms
        return 0;
    } else {  //其他情况
        return -1;
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<vector<int>> arr;
    std::vector<string> str;
    const int seed = 133;    //哈希种子
    const int hs = 1e7 + 7;  //模
    string line;
    for (int i = 0; i < n; i++) {
        cin >> line;
        str.push_back(line);
        vector<string> parts = split(line, ':');
        int a = stoi(parts[0]);  // a是时间
        int b = 0;               // b是冒号后的字符串哈希
        int c = 0;               // c是冒号后的去除数字的字符串哈希
        const string& ls = parts[1];
        for (char ch : ls) {
            if ('a' <= ch && ch <= 'z') {
                c = (c * seed + ch) % hs;
            }
            b = (b * seed + ch) % hs;
        }
        arr.push_back({a, b, c});  //将关键信息存入arr
    }

    vector<int> ans1;  //存储非抑制日志
    vector<int> ans2;  //存储抑制日志
    for (int i = 0; i < n; i++) {
        bool f = true;
        int cnt = 0;
        for (int j = ans1.size() - 1; j >= 0; j--) {  //对于日志i,我们需要从后往前找非抑制日志,查看是否冲突
            int tar = sift(arr, i, ans1[j]);
            if (tar == 1 || (tar == 2 && cnt == 8)) {  //如果冲突
                f = false;
                break;
            } else if (tar == 2) {  //不冲突但是相似
                cnt++;
            } else if (tar == 0) {  //和前面的日志时间相差超过100ms,就不需要再枚举
                break;
            }
        }
        if (f) {
            ans1.push_back(i);
        } else {
            ans2.push_back(i);
        }
    }

    for (int i : ans2) {
        cout << str[i] << std::endl;
    }

    return 0;
}