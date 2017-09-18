#include <iostream>

using namespace std;

class Solution {
public:
    static bool validPalindrome(string s) {
        bool ok = true;
        for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
            // find the first mismatch
            if (s[i] != s[j]) {
                // try to delete s[i]
                for (int a = i + 1, b = j; a < b; ++a, --b) {
                    if (s[a] != s[b]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) { break; }

                ok = true;
                // try to delete s[j]
                for (int a = i, b = j - 1; a < b; ++a, --b) {
                    if (s[a] != s[b]) {
                        ok = false;
                        break;
                    }
                }
                break;
            }
        }

        return ok;
    }
};

int main() {
    //string s = "aba";
    //string s = "abca";
    string s = "cbbcc";

    cout << Solution::validPalindrome(s) << endl;

    return 0;
}