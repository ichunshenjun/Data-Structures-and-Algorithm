// 855
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
static int num;
class ExamRoom {
public:
    int N;
    struct cmp {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            int distA = (a[1] - a[0]) / 2;
            if (a[0] == -1) distA = a[1];
            if (a[1] == num) distA = num - 1 - a[0];
            int distB = (b[1] - b[0]) / 2;
            if (b[0] == -1) distB = b[1];
            if (b[1] == num) distB = num - 1 - b[0];
            return distA > distB || (distA == distB && a[0] < b[0]);
        };
    };
    unordered_map<int, vector<int>> startMap;
    unordered_map<int, vector<int>> endMap;
    set<vector<int>, cmp> pq;
    void addInterval(vector<int> intv) {
        pq.insert(intv);
        startMap[intv[0]] = intv;
        endMap[intv[1]] = intv;
    }
    void removeInterval(vector<int> intv) {
        pq.erase(intv);
        startMap.erase(intv[0]);
        endMap.erase(intv[1]);
    }
    ExamRoom(int n) : N(n) {
        num = N;
        addInterval(vector<int>{-1, N});
    }
    int seat() {
        auto longest = *pq.begin();
        int x = longest[0];
        int y = longest[1];
        int seat;
        if (x == -1) {
            seat = 0;
        } else if (y == N) {
            seat = N - 1;
        } else {
            seat = (y - x) / 2 + x;
        }
        vector<int> left = vector<int>{x, seat};
        vector<int> right = vector<int>{seat, y};
        removeInterval(longest);
        addInterval(left);
        addInterval(right);
        return seat;
    }

    void leave(int p) {
        auto right = startMap[p];
        auto left = endMap[p];
        auto merge = vector<int>{left[0], right[1]};
        removeInterval(left);
        removeInterval(right);
        addInterval(merge);
    }
};
int main() {
    ExamRoom* room = new ExamRoom(10);
    cout << room->seat() << endl;
    cout << room->seat() << endl;
    cout << room->seat() << endl;
    cout << room->seat() << endl;
    room->leave(4);
    cout << room->seat() << endl;
    return 0;
}
