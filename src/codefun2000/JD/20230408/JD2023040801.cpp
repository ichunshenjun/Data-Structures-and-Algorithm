#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
    int n;
    unordered_map<int, int> map;
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        map[temp]++;
    }
    int sum = 0;
    for (auto itr = map.begin(); itr != map.end(); itr++) sum += itr->second - 1;
    cout << sum << endl;
    return 0;
}