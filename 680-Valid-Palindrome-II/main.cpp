#include <iostream>

using namespace std;

class Solution {
public:
    static bool validPalindrome(string s) {
        for (int i = s.length(); i >= 0; --i) {
            bool ok = true;
            for (int j = 0, k = s.length() - 1; j < k; ++j, --k) {
                if (j == i) {
                    ++j;
                }
                if (k == i) {
                    --k;
                }
                if (j >= k) {
                    break;
                }

                if (s[j] != s[k]) {
                    ok = false;
                    cout << i << "-" << j << endl;
                    break;
                }
            }
            if (ok) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    string s = "aba";

    cout << Solution::validPalindrome(s) << endl;

    return 0;
}