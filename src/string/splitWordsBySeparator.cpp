// 6921
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
vector<string> splitWordsBySeparator(vector<string>& words, char separator);
int main() {
    vector<string> words = {"one.two.three", "four.five", "six"};
    char separator = '.';
    auto res = splitWordsBySeparator(words, separator);
    for (auto str : res) {
        cout << str << endl;
    }
    return 0;
}
// vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
//     vector<string> res;
//     for (auto word : words) {
//         const char* c = word.c_str();
//         const char* delim = &separator;
//         char* p = strtok(const_cast<char*>(c), delim);
//         while (p) {
//             res.push_back(p);
//             p = strtok(nullptr, delim);
//         }
//     }
//     return res;
// }
// 法2(但是分隔符只能是char)
vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
    vector<string> result;
    for (auto word : words) {
        string token;
        stringstream ss(word);

        while (getline(ss, token, separator)) {
            if (!token.empty()) {
                result.push_back(token);
            }
        }
    }
    return result;
}