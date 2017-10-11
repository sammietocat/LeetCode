#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool PredictTheWinner(vector<int> &nums) {
        int nums_size = nums.size();

        vector<vector<int>> delta(nums_size, vector<int>(nums_size));

        for (int i = 0; i < nums_size; ++i) {
            delta[i][i] = nums[i];
        }

        for (int d = 1; d < nums_size; ++d) {
            for (int i = 0, j = i + d; j < nums_size; ++i, ++j) {
                delta[i][j] = std::max(nums[j] - delta[i][j - 1], nums[i] - delta[i + 1][j]);
            }
        }

        return (delta[0].back() >= 0);
    }
};

int main() {
    //vector<int> nums{1,5,2};
    vector<int> nums{1, 5, 233, 7};

    cout << Solution::PredictTheWinner(nums) << endl;

    return 0;
}