#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.empty()) { return 0; }
        else if (1 == nums.size()) { return nums[0]; }

        int prev1, prev2;
        int withFirst{0}, withLast{0};
        // without the last one
        {
            prev1 = prev2 = 0;
            for (size_t i{}; i < nums.size() - 1; ++i) {
                withFirst = std::max(prev1, prev2 + nums[i]);
                prev2 = prev1;
                prev1 = withFirst;
            }
        }
        // without the first one
        {
            prev1 = prev2 = 0;
            for (size_t i = 1; i < nums.size(); ++i) {
                withLast = std::max(prev1, prev2 + nums[i]);

                prev2 = prev1;
                prev1 = withLast;
            }
        }

        return std::max(withFirst, withLast);
    }

};

int main() {
    return 0;
}