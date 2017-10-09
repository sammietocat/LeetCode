#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool checkSubarraySum(vector<int> &nums, int k) {
        vector<int> sub_sums{std::begin(nums), std::end(nums)};
        bool yes{false};

        if (0 == k) {
            for (int i = 1; i < nums.size(); ++i) {
                if ((0 == nums[i - 1]) && (0 == nums[i])) {
                    yes = true;
                    break;
                }
            }
        } else {
            for (int i = 0; i < nums.size(); ++i) {
                sub_sums[i] %= k;
                for (int j = i - 1; j >= 0; --j) {
                    sub_sums[j] = (sub_sums[j + 1] + nums[j]) % k;

                    if (0 == sub_sums[j]) {
                        yes = true;
                        break;
                    }
                }
                if (yes) { break; }
            }
        }

        return yes;
    }
};

int main() {
    //vector<int> nums{23, 2, 4, 6, 7};
    vector<int> nums{23, 2, 6, 4, 7};
    //const int k = 6;
    const int k = 0;

    cout << Solution::checkSubarraySum(nums, k) << endl;

    return 0;
}