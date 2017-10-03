#include <iostream>

using namespace std;

class Solution {
public:
    static bool isSubsequence(string s, string t) {
        auto i = std::begin(t);
        auto tEnd = std::end(t);

        for (const auto &c:s) {
            while ((i != tEnd) && (*i != c)) { ++i; }

            if (i == tEnd) { return false; }
            ++i;
        }

        return true;
    }
};

int main() {
    string s[] = {"abc", "axc", ""};
    string t[] = {"ahbgdc", "ahbfdc", "a"};

    for (int i = 0; i < 3; ++i) {
        cout << Solution::isSubsequence(s[i], t[i]) << endl;
    }

    return 0;
}