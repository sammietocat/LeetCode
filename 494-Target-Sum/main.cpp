#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    static int findTargetSumWays(vector<int> &nums, int S) {
        vector<int> sum_max(nums.size()), sum_min(nums.size());

        sum_max.back() = 0;
        sum_min.back() = 0;
        for (int i = nums.size() - 2; i >= 0; --i) {
            sum_max[i] = sum_max[i + 1] + nums[i + 1];
            sum_min[i] = sum_min[i + 1] - nums[i + 1];
        }

        /*
        for (int i = 0; i < nums.size(); ++i) {
            cout << sum_max[i] << " - " << sum_min[i] << endl;
        }
         */

        stack<pair<int, int>> dfs;
        pair<int,int> pr;
        int num_ways{};

        dfs.emplace(nums[0], 0);
        dfs.emplace(-nums[0], 0);
        while (!dfs.empty()) {
            pr.first = dfs.top().first;
            pr.second = dfs.top().second;
            dfs.pop();

            cout << pr.first << ", " << pr.second << ", " << nums.size() << endl;

            if ((nums.size() == pr.second + 1) && (S == pr.first)) {
                ++num_ways;
                continue;
            }

            if ((pr.first + sum_max[pr.second] < S) ||
                (pr.first + sum_min[pr.second] > S)) {
                continue;
            }

            // plus next value
            dfs.emplace(pr.first + nums[pr.second + 1], pr.second + 1);
            // minus next value
            dfs.emplace(pr.first - nums[pr.second + 1], pr.second + 1);
        }

        return num_ways;
    }
};

int main() {
    vector<int> nums{1, 1, 1, 1, 1};
    const int S{3};

    cout << Solution::findTargetSumWays(nums, S) << endl;

    return 0;
}