#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int wiggleMaxLength(vector<int> &nums) {
        if (nums.size() < 2) { return nums.size(); }

        vector<int> maxLen(nums.size(), 1);
        //vector<size_t> prevIdx(nums.size(), 0);
        // flag indicating the sign of previous difference
        vector<bool> a(nums.size(), false);

        maxLen[0] = 1;
        //prevIdx[0] = 0;

        for (size_t i = 1; i < nums.size(); ++i) {
            //prevIdx[i] = i;
            for (size_t j = i - 1; j >= 0; --j) {
                if (nums[i] == nums[j]) {
                    maxLen[i] = maxLen[j];
                    //prevIdx[i] = prevIdx[j];
                    a[i] = a[j];
                    break;
                } else if (1 == maxLen[j]) {
                    maxLen[i] = maxLen[j] + 1;
                    //prevIdx[i] = j;
                    a[i] = (nums[i] > nums[j]);
                    break;
                } else if (((nums[i] < nums[j]) && a[j])
                           || ((nums[i] > nums[j]) && !a[j])) {
                    maxLen[i] = maxLen[j] + 1;
                    //prevIdx[i] = prevIdx[j];
                    a[i] = !a[j];
                    break;
                }
            }

            if (maxLen[i] < maxLen[i - 1]) {
                maxLen[i] = maxLen[i - 1];
                //prevIdx[i] = prevIdx[i - 1];
                a[i] = !a[i - 1];
            }
        }

        //return (2 == maxLen.back() ? 1 : maxLen.back());
        return maxLen.back();
    }
};

int main() {
    vector<vector<int>> nums{
            {1, 7,  4, 9,  2,  5},
            {1, 17, 5, 10, 13, 15, 10, 5, 16, 8},
            {1,2,3,4,5,6,7,8,9}};

    for (auto &vec:nums) {
        cout << Solution::wiggleMaxLength(vec) << endl;
    }

    return 0;
}