#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> findErrorNums(vector<int> &nums) {
        // 1st is the one occurring twice, and the 2nd is the missing one
        vector<int> twiceAndMissing(2);
        vector<bool> seen(nums.size() + 1, 0);

        int fakeSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            fakeSum += nums[i];
            if (seen[nums[i]]) {
                twiceAndMissing[0] = nums[i];
            }
            seen[nums[i]] = true;
        }

        twiceAndMissing[1] = twiceAndMissing[0] + ((1 + nums.size()) * nums.size() / 2 - fakeSum);

        return twiceAndMissing;
    }
};

int main() {
    //vector<int> nums = {1, 2, 2, 4};
    vector<int> nums = {2,2};

    vector<int> twiceAndMissing = Solution::findErrorNums(nums);
    cout << twiceAndMissing[0] << "-" << twiceAndMissing[1] << endl;

    return 0;
}