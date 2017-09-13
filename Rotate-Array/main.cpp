#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static void rotate(vector<int> &nums, int k) {
        k = k%nums.size();
        int tmp;
        for (int i = 0, j = nums.size() - 1; i < j; ++i, --j) {
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
        for (int i = 0, j = k - 1; i < j; ++i, --j) {
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
        for (int i = k, j = nums.size() - 1; i < j; ++i, --j) {
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
};

int main() {
    vector<int> vec{1, 2, 3, 4, 5, 6, 7};
    int k = 11;

    Solution::rotate(vec, k);
    for (const auto &v:vec) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}