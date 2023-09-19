#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    int x, y;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        if (s[x - 1] == 'H') {
            if (s[y - 1] == 'L')
                cout << "liar" << endl;
            else
                cout << "honester" << endl;
        } else {
            if (s[y - 1] == 'L')
                cout << "honester" << endl;
            else
                cout << "liar" << endl;
        }
    }
    return 0;
}