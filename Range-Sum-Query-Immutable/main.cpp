#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) {
        if (0!=nums.size()) {
            cache.resize(nums.size());

            cache[0] = nums[0];
            for (int i = 1; i < nums.size(); ++i) {
                cache[i] = cache[i-1] +nums[i];
            }
        }
    }

    int sumRange(int i, int j) {
        return (0==i ? cache[j]:(cache[j]-cache[i-1]));
    }

private:
    vector<int> cache;
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    vector<int> i = {0, 2, 5};
    vector<int> j = {2, 5, 5};

    NumArray na(nums);

    for (int k = 0; k < i.size(); ++k) {
        cout << na.sumRange(i[k], j[k]) << endl;
    }

    return 0;
}