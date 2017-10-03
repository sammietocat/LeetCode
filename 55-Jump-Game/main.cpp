#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool canJump(vector<int> &nums) {
        if (nums.size() < 2) { return true; }

        int i = nums.size() - 1;
        bool isOk;
        while (i > 0) {
            isOk = false;
            for (int j = i - 1; j >= 0; --j) {
                if (j + nums[j] >= i) {
                    i = j;
                    isOk = true;
                    break;
                }
            }
            if (!isOk) { break; }
        }

        return isOk;
    }
};

int main() {
    vector<vector<int>> A{
            {2, 3, 1, 1, 4},
            {3, 2, 1, 0, 4},
            {0, 1},
            {1, 1}
    };

    for (auto &a:A) {
        cout << std::boolalpha << Solution::canJump(a) << endl;
    }


    return 0;
}