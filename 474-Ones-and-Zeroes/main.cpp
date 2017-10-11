#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int findMaxForm(vector<string> &strs, int m, int n) {
        sort(std::begin(strs), std::end(strs),
             [](const string &s1, const string &s2) {
                 if (s1.length() == s2.length()) {
                     return s1 < s2;
                 }

                 return s1.length() < s2.length();
             });

        int num_strs = strs.size();
        vector<vector<int>> nums01(num_strs + 1, vector<int>{0, 0});
        vector<int> num_str_ok_max(num_strs + 1);

        nums01[0][0] = m;
        nums01[0][1] = n;
        num_str_ok_max[0] = 0;

        int nums0, nums1;
        for (int i = 0, j = 1; i < num_strs; ++i, ++j) {
            nums0 = nums1 = 0;
            for (const auto &c:strs[i]) {
                ('0' == c) ? ++nums0 : ++nums1;
            }

            // not compose strs[i]
            num_str_ok_max[j] = num_str_ok_max[i];
            nums01[j][0] = nums01[i][0];
            nums01[j][1] = nums01[i][1];

            // attempt to compose strs[i]
            for (int k = i; k >= 0; --k) {
                if ((nums01[k][0] >= nums0) && (nums01[k][1] >= nums1)) {
                    if (num_str_ok_max[j] <= num_str_ok_max[k] + 1) {
                        num_str_ok_max[j] = num_str_ok_max[k] + 1;
                        nums01[j][0] = nums01[k][0] - nums0;
                        nums01[j][1] = nums01[k][1] - nums1;
                    }
                    break;
                }
            }
        }

        ///*
        for (int i = 0; i <= num_strs; ++i) {
            cout << i << ": " << num_str_ok_max[i] << " " << nums01[i][0] << " " << nums01[i][1] << endl;
        }
        //*/

        return num_str_ok_max.back();
    }
};

int main() {
    ///*
    vector<string> strs{"10", "0001", "111001", "1", "0"};
    const int m = 5, n = 3;
    //*/
    /*
    vector<string> strs{"10", "1", "0"};
    const int m = 1, n = 1;
     */

    /*
    vector<string> strs{"10", "0001", "111001", "1", "0"};
    const int m = 3, n = 4;
     */

    cout << Solution::findMaxForm(strs, m, n) << endl;

    return 0;
}