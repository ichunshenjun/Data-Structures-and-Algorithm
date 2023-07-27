#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
vector<int> geturl(unordered_map<int, int>& urls);
class LRU {
public:
    struct Node {
        int start, end, key;
        bool operator<(const Node& b) const {
            if (end == b.end) return start > b.start;
            return end > b.end;
        }
    };
    unordered_set<int> set_;
    priority_queue<Node> pq_;
    int capacity_;
    int time_;
    LRU(int capacity) : capacity_(capacity) { time_ = 0; }
    void put(int key, int start, int end) {
        int sz = set_.size();
        if (sz >= capacity_) {
            set_.erase(pq_.top().key);
            pq_.pop();
        }
        pq_.push({start, end, key});
        set_.insert(key);
    }
    int get(int key) {
        while (!pq_.empty() && time_ == pq_.top().end) {
            set_.erase(pq_.top().key);
            pq_.pop();
        }
        int address = 1;
        if (set_.count(key)) {
            address = 0;
        }
        time_++;
        return address;
    }
};
int main() {
    int n, x, y;
    cin >> n >> x;
    LRU* lru = new LRU(n);
    unordered_map<int, int> tls;
    vector<int> urls;
    vector<int> res;
    for (int i = 0; i < x; i++) {
        int url;
        cin >> url;
        urls.push_back(url);
    }
    cin >> y;
    for (int i = 0; i < y; i++) {
        int url, ttl;
        cin >> url >> ttl;
        tls[url] = ttl;
    }
    int time = 0;
    for (auto url : urls) {
        int ttl;
        int address = lru->get(url);
        if (address) {
            ttl = 5;
            if (tls.count(url)) {
                ttl = tls[url];
            }
            lru->put(url, time, ttl + time);
        }
        res.push_back(address);
        time++;
    }
    for (int i = 0; i < x; i++) {
        cout << res[i] << " \n"[i + 1 == x];
    }
    return 0;
}
