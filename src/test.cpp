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

// string reverseWords(string s) {
//     if (s.empty()) return "";
//     s += " ";
//     string temp = "";
//     vector<string> res;
//     for (auto ch : s) {
//         if (ch == ' ') {
//             if (!temp.empty()) {
//                 res.push_back(temp);
//                 temp.clear();
//             }
//         } else
//             temp += ch;
//     }
//     s.clear();
//     reverse(res.begin(), res.end());
//     for (auto str : res) s += str + ' ';
//     if (s.size()) s.pop_back();
//     return s;
// }
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
long long n;
long long mod=1e9+7;
vector<long long> odds;
vector<long long> evens;
int main(){
    cin>>n;
    long long res=0;
    for(long long i=0;i<=n/2*9;i++){
        evens.push_back(i%mod);
    }
    for(long long i=1;i<=(n+1)/2*9;i++){
        odds.push_back(i%mod);
    }
    for(auto odd:odds){
        for(auto even:evens){
            res=(res+odd*even%(mod))%(mod);
        }
    }
    cout<<res;
    return 0;
}