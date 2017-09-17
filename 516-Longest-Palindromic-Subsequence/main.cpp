#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int longestPalindromeSubseq(string s) {
        if (s.length() <= 1) {
            return s.length();
        }

        const int LEN = s.length();

        vector<vector<int>> M(LEN + 1);
        for (int i = 0; i <= LEN; ++i) {
            M[i].resize(LEN - i + 1, 0);
        }

        // i: length of sequence reading forward
        for (int i = 1; i <= LEN; ++i) {
            // j: length of sequence reading backward
            for (int j = 1; j <= LEN - i; ++j) {
                int k = LEN - j;

                if (s[i - 1] == s[k]) {
                    M[i][j] = M[i - 1][j - 1] + 1;
                } else {
                    M[i][j] = (M[i][j - 1] > M[i - 1][j] ? M[i][j - 1] : M[i - 1][j]);
                }
            }
        }

        /*
        for (const auto &row:M) {
            for (const auto &cell:row) {
                cout << cell << " ";
            }
            cout << endl;
        }
         */

        int Lm = 0;
        for (int i = 0; i <= LEN; ++i) {
            if (Lm < 2 * M[i][LEN - i]) {
                Lm = 2 * M[i][LEN - i];
            }

            if ((i > 0) && (i < LEN)) {
                if (Lm < 2 * M[i - 1][LEN - i] + 1) {
                    Lm = 2 * M[i - 1][LEN - i] + 1;
                }
            }
        }

        return Lm;
    }
};

int main() {
    //string s = "bbbab";
    //string s = "cbbd";
    //string s = "bbabab";
    //string s = "bb";
    string s = "b";

    cout << Solution::longestPalindromeSubseq(s) << endl;

    return 0;
}