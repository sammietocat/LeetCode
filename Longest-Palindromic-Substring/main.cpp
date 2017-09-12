#include <iostream>

using namespace std;

class Solution {
public:
    static string longestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }

        int lo = 0, hi = 1;
        for (int i = 0; i < s.length(); ++i) {
            int j, k;
            // s[i] as the middle for an odd-length palindrome string
            for (j = i - 1, k = i + 1; (j >= 0) && (k < s.length()); --j, ++k) {
                if (s[j] != s[k]) {
                    break;
                }
            }
            // update the range
            {
                ++j;
                //--k;
                if (hi - lo < k - j) {
                    lo = j;
                    hi = k;
                }
            }

            // s[i] as the middle left for an even-length palindrome string
            for (j = i, k = i + 1; (j >= 0) && (k < s.length()); --j, ++k) {
                if (s[j] != s[k]) {
                    break;
                }
            }
            {
                ++j;
                //--k;
                if (hi - lo < k - j) {
                    lo = j;
                    hi = k;
                }
            }
        }

        return s.substr(lo, hi - lo);
    }
};

int main() {
    const int N = 3;
    string strs[] = {
            "babad",
            "cbbd",
            "bb",
            "b"
    };
    for (const auto &s:strs) {
        cout << s << ": " << Solution::longestPalindrome(s) << endl;
    }
    //string s = "babad";
    //string s = "cbbd";
    //string s = "bb";


    return 0;
}