#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int findSubstringInWraproundString(string p) {
        if (p.empty()) { return 0; }

        int num_unique_substr{};
        int substr_len_max[26]{0};
        int prev_substr_len_max;

        substr_len_max[p[0] - 'a'] = 1;
        prev_substr_len_max = 1;
        num_unique_substr = 1;
        for (int i = 1; i < p.size(); ++i) {
            if ((p[i - 1] + 1 == p[i]) || (('z' == p[i - 1]) && ('a' == p[i]))) {
                if (prev_substr_len_max + 1 > substr_len_max[p[i] - 'a']) {
                    num_unique_substr += prev_substr_len_max + 1 - substr_len_max[p[i] - 'a'];
                    substr_len_max[p[i] - 'a'] = prev_substr_len_max + 1;
                }
                ++prev_substr_len_max;
            } else {
                if (substr_len_max[p[i] - 'a'] < 1) {
                    substr_len_max[p[i] - 'a'] = 1;
                    ++num_unique_substr;
                }
                prev_substr_len_max = 1;
            }
        }

        return num_unique_substr;
    }
};

int main() {
    vector<string> p_vec{"a", "cac", "zab", "abaab"};

    for (int i = 3; i < p_vec.size(); ++i) {
        cout << Solution::findSubstringInWraproundString(p_vec[i]) << endl;
    }

    return 0;
}