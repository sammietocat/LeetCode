#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int findNumberOfLIS(vector<int> &nums) {
        if (0 == nums.size()) {
            return 0;
        }

        vector<int> L(nums.size());
        vector<int> nC(nums.size());
        int Lm = -1;

        for (int i = 0; i < nums.size(); ++i) {
            L[i] = 1;
            nC[i] = 1;
            for (int j = i - 1; j >= 0; --j) {
                /*
                if ((nums[j] < nums[i]) && (L[i] < L[j] + 1)) {
                    L[i] = L[j] + 1;
                }
                 */

                if (nums[j] < nums[i]) {
                    int tmp = L[j] + 1;
                    if (L[i] < tmp) {
                        L[i] = tmp;
                        nC[i] = nC[j];
                    } else if (L[i] == tmp) {
                        nC[i] += nC[j];
                    }
                }
            }

            if (Lm < L[i]) {
                Lm = L[i];
            }
        }

        int LmCnt = 0;
        for (int i = 0; i < L.size(); ++i) {
            if (L[i] == Lm) {
                LmCnt += nC[i];
            }
        }

        return LmCnt;
    }
};

int main() {
    //vector<int> nums = {1, 3, 5, 4, 7};
    //vector<int> nums = {1, 1, 1, 1, 1};
    vector<int> nums = {1, 2, 4, 3, 5, 4, 7, 2};

    cout << Solution::findNumberOfLIS(nums) << endl;

    return 0;
}