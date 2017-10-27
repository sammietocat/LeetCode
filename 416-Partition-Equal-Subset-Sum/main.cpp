#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int nums_size = nums.size();
        if (nums_size < 2) { return false; }

        int total{};
        for (const auto &v : nums) {
            total += v;
        }

        // total is odd
        if (total & 1) { return false; }

        auto wanted = total / 2;
        bitset<VAL_MAX * NUM_SIZE_MAX / 2 + 1> subset_sum;
        for (const auto &v : nums) {
            subset_sum |= (subset_sum << v);
            subset_sum.set(v);

            if (subset_sum[wanted]) { break; }
        }

        return subset_sum[wanted];
    }

private:
    const static int VAL_MAX{100};
    const static int NUM_SIZE_MAX{200};
};

int main() {
    Solution solu;

    vector<vector<int>> nums{
            {1, 5, 11, 5},
            {1, 2, 3,  5},
            {3, 3, 3,  4, 5},
    };

    for (int i = 2; i < nums.size(); ++i) {
        cout << solu.canPartition(nums[i]) << endl;
    }

    return 0;
}