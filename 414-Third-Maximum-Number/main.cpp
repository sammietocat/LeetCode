#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static const long long MINUS_INF = -9223372036854775808;

    static int thirdMax(vector<int> &nums) {
        long long max[3];
        max[0] = max[1] = max[2] = MINUS_INF;

        bool seen;
        for (const auto &n:nums) {
            // check for duplicated
            seen = false;
            for (int i = 0; i < 3; ++i) {
                if (n == max[i]) {
                    seen = true;
                }
            }
            if (seen) {
                continue;
            }

            if (n > max[2]) {
                max[0] = max[1];
                max[1] = max[2];
                max[2] = n;
            } else if (n > max[1]) {
                max[0] = max[1];
                max[1] = n;
            } else if (n > max[0]) {
                max[0] = n;
            }
        }

        if ((MINUS_INF == max[0]) || (MINUS_INF == max[1])) {
            return max[2];
        }

        return max[0];
    }
};

int main() {
    //vector<int> nums{3, 2, 1};
    //vector<int> nums{2, 2, 3, 1};
    vector<int> nums{1, 2, -2147483648};

    cout << Solution::thirdMax(nums) << endl;

    return 0;
}