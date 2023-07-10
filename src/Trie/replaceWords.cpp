#include <cstdint>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>
using namespace std;
string replaceWords(vector<string>& dictionary, string sentence);
int main() {
    vector<string> dictionary = {"catt", "cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";
    cout << replaceWords(dictionary, sentence) << endl;
    return 0;
}
string replaceWords(vector<string>& dictionary, string sentence) {
    stringstream ss(sentence);
    vector<string> vec;
    string res;
    string temp = "";
    while (ss >> temp) vec.push_back(temp);
    unordered_set<string> dictionarySet;
    for (auto str : dictionary) {
        dictionarySet.emplace(str);
    }
    for (auto& word : vec) {
        for (int j = 0; j < (int)word.size(); j++) {
            if (dictionarySet.count(word.substr(0, 1 + j))) {
                word = word.substr(0, 1 + j);
                break;
            }
        }
    }
    for (auto word : vec) {
        res += word;
        res += " ";
    }
    res.pop_back();
    return res;
}