#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        for (auto itr = nums.cbegin() + 1; itr != nums.cend(); ++itr) {
            nums.front() ^= *itr;
        }


        return nums[0];
    }
};

int main() {
    return 0;
}