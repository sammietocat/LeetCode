#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int countSubstrings(string s) {
        if(0==s.length()) {
            return 0;
        }

        vector<vector<int>> idx;

        idx.push_back({0});
        for (int i = 1; i < s.length(); ++i) {
            idx.push_back({i});
            if (s[i] == s[i - 1]) {
                idx.back().push_back(i - 1);
            }

            for (const auto &j:idx[i - 1]) {
                if ((j > 0) && (s[j - 1] == s[i])) {
                    idx.back().push_back(j - 1);
                }
            }
        }

        int nP = 0;
        for (const auto &row:idx) {
            nP += row.size();
        }

        return nP;
    }
};

int main() {
    string s = "abc";
    //string s = "aaa";
    //string s = "a";

    cout << Solution::countSubstrings(s) << endl;

    return 0;
}