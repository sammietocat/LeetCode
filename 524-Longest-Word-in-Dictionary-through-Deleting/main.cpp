#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static string findLongestWord(string s, vector<string> &d) {
        std::sort(std::begin(d), std::end(d),
                  [](const string &word1, const string &word2) {
                      return (word1.length() > word2.length()) ||
                             ((word1.length() == word2.length()) && (word1 < word2));
                  });

        for (const auto &word : d) {
            int i = 0;
            bool ok{true};
            for (const auto &c : word) {
                while ((i < s.size()) && (s[i] != c)) { ++i; }
                if (s.size() == i) {
                    ok = false;
                    break;
                }
                ++i;
            }

            if (ok) { return word; }
        }

        return "";
    }
};

int main() {
    const string s = "abpcplea";
    vector<string> dict{"ale", "apple", "monkey", "plea"};
    //vector<string> dict{"a", "b", "c"};


    cout << Solution::findLongestWord(s, dict) << endl;


    return 0;
}