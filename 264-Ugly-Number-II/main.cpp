#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int nthUglyNumber(int n) {
        vector<int> vec(n);

        vec[0] = 1;

        int xIdx{}, yIdx{}, zIdx{};

        int x = vec[xIdx] * 2;
        int y = vec[yIdx] * 3;
        int z = vec[zIdx] * 5;

        for (int i = 1; i < n; ++i) {
            while (x <= vec[i - 1]) {
                x = vec[++xIdx] * 2;
            }
            while (y <= vec[i - 1]) {
                y = vec[++yIdx] * 3;
            }
            while (z <= vec[i - 1]) {
                z = vec[++zIdx] * 5;
            }

            if ((x <= y) && (x <= z)) {
                vec[i] = x;
                x = vec[++xIdx] * 2;
            } else if ((y <= x) && (y <= z)) {
                vec[i] = y;
                y = vec[++yIdx] * 3;
            } else if ((z <= x) && (z <= y)) {
                vec[i] = z;
                z = vec[++zIdx] * 5;
            }
        }

        return vec.back();
    }
};

int main() {
    for (int n = 1; n < 20; ++n) {
        cout << Solution::nthUglyNumber(n) << endl;
    }
    return 0;
}