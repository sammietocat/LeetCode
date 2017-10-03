#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int jump(vector<int> &nums) {
        if (nums.size() < 2) { return 0; }

        vector<int> minJump(nums.size(), -1);
        minJump[0] = 0;
        for (size_t i{}; i < nums.size(); ++i) {
            if (i + nums[i] >= nums.size() - 1) {
                minJump.back() = minJump[i] + 1;
                break;
            }

            // offset for pruning
            int offset = i;
            for (size_t j = i + nums[i]; j > i; --j) {
                if (-1 == minJump[j]) { minJump[j] = minJump[i] + 1; }
                if (j + nums[j] > offset + nums[offset]) {
                    offset = j;
                }
            }

            i = offset - 1;
        }

        return minJump.back();
    }
};

int main() {
    vector<int> A{2, 3, 1, 1, 4};

    cout << Solution::jump(A) << endl;
    return 0;
}