#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int> &nums) {
        if (3 == nums.size()) {
            return nums[0] * nums[1] * nums[2];
        }

        // a is the index set of positives
        // b is the index set of non-positives
        vector<int> a, b;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= 0) {
                b.push_back(i);
            } else {
                a.push_back(i);
            }
        }

        if (0 == a.size()) {
            // find the 3 smallest non-positives indexed by i, j, k in ascending order
            int i, j, k;
            if (nums[b[0]] < nums[b[1]]) {
                i = b[0];
                j = b[1];
            } else {
                i = b[1];
                j = b[0];
            }
            if (nums[b[2]] < nums[i]) {
                k = j;
                j = i;
                i = b[2];
            } else if (nums[b[2]] < nums[j]) {
                k = j;
                j = b[2];
            } else {
                k = b[2];
            }

            for (int l = 3; l < b.size(); ++l) {
                if (nums[b[l]] > nums[i]) {
                    if (nums[b[l]] <= nums[j]) {
                        i = b[l];
                    } else if (nums[b[l]] <= nums[k]) {
                        i = j;
                        j = b[l];
                    } else {
                        i = j;
                        j = k;
                        k = b[l];
                    }
                }
            }

            return nums[i] * nums[j] * nums[k];
        } else if (a.size() == 1) {
            return a[0] * findMax2Prod(nums, b);
        } else if (a.size() == 2) {
            // note here: at least 2 non-positives left
            return (a[0] >= a[1] ? (a[0] * findMax2Prod(nums, b)) : (a[1] * findMax2Prod(nums, b)));
        } else {

        }

        return 0;
    }

    int findMax2Prod(const vector<int> &nums, const vector<int> &indices, const int exceptIdx = -1) {
        int i, j;
        if (nums[indices[0]] <= nums[indices[1]]) {
            i = indices[0];
            j = indices[1];
        } else {
            i = indices[1];
            j = indices[0];
        }

        if (nums[indices[0]] <= 0) {
            for (int k = 2; k < indices.size(); ++k) {
                if (exceptIdx == k) {
                    continue;
                }
                if (nums[indices[k]] < nums[i]) {
                    j = i;
                    i = indices[k];
                } else if (nums[indices[k]] < nums[j]) {
                    j = indices[k];
                }
            }
        } else {
            for (int k = 2; k < indices.size(); ++k) {
                if (exceptIdx == k) {
                    continue;
                }
                if (nums[indices[k]] > nums[j]) {
                    i = j;
                    j = indices[k];
                } else if (nums[indices[k]] > nums[i]) {
                    i = indices[k];
                }
            }
        }

        return nums[i] * nums[j];
    }
};

int main() {
    vector<int> nums = {1, 2};
    cout << Solution::maximumProduct(nums) << endl;

    return 0;
}