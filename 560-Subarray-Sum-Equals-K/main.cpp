#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int subarraySum(vector<int> &nums, int k) {
        vector<int> sub_sums{std::begin(nums), std::end(nums)};
        int num_sum_k{};

        for (int i = 0; i < nums.size(); ++i) {
            sub_sums[i] = nums[i];
            num_sum_k += (sub_sums[i] == k ? 1 : 0);

            for (int j = i - 1; j >= 0; --j) {
                sub_sums[j] = nums[j] + sub_sums[j + 1];
                num_sum_k += (sub_sums[j] == k ? 1 : 0);
            }
        }

        return num_sum_k;
    }
};

int main() {
    vector<int> nums{1, 1, 1};
    const int k{2};

    cout << Solution::subarraySum(nums, k) << endl;

    return 0;
}