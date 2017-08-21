#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        if (nums.size() <= 1) {
            return false;
        }

        int halfSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            halfSum += nums[i];
        }
        if (0 != halfSum & 1) {
            // return false in case of sum is odd
            return false;
        }
        halfSum/=2;


    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}