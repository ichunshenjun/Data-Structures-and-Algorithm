#include <cstdlib>
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Cache {
public:
    int L[100010], R[100010];
    int used[100010];
    int remain = 0;
    int begin, end;
    int left, right;
    Cache(int l, int r) {
        for (int i = l; i <= r; i++) {
            L[i] = i - 1;
            R[i] = i + 1;
        }
        remain = r - l + 1;
        begin = l;
        end = r;
        left = l;
        right = r;
    }
    void operation(int op, int arg) {
        switch (op) {
            case 1: {
                if (remain < arg) {
                    return;
                }
                while (arg--) {
                    R[L[begin]] = R[begin];
                    L[R[begin]] = L[begin];
                    used[begin] = 1;
                    remain--;
                    begin = R[begin];
                }
                break;
            }
            case 2: {
                if (arg < left || arg > right || used[arg]) return;
                R[L[arg]] = R[arg];
                L[R[arg]] = L[arg];
                if (arg == begin)
                    begin = R[arg];
                else if (arg == end)
                    end = L[arg];
                used[arg] = 1;
                remain--;
                break;
            }
            case 3: {
                if (arg < left || arg > right || !used[arg]) return;
                if (remain == 0) {
                    begin = arg;
                    end = arg;
                } else {
                    R[end] = arg;
                    L[arg] = end;
                    end = arg;
                }
                used[arg] = 0;
                remain++;
                break;
            }
        }
    }
    int front() { return begin; }
};
int main() {
    int l, r, t;
    cin >> l >> r >> t;
    int op, arg;
    auto cache = new Cache(l, r);
    for (int i = 0; i < t; i++) {
        cin >> op >> arg;
        cache->operation(op, arg);
    }
    cout << cache->front() << endl;
    delete (cache);
    return 0;
}