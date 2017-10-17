#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int numSquares(int n) {
        if (n <= 0) { return 1; }

        vector<int> num_perfect_square(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            int sr = static_cast<int>(std::sqrt(i));
            if (sr * sr == i) {
                num_perfect_square[i] = 1;
            } else {
                num_perfect_square[i] = num_perfect_square[i - 1] + 1;
                for (int j = i / 2; j < i; ++j) {
                    if (num_perfect_square[i] > num_perfect_square[j] + num_perfect_square[i - j]) {
                        num_perfect_square[i] = num_perfect_square[j] + num_perfect_square[i - j];
                    }
                }
            }
        }

        return num_perfect_square.back();
    }
};

int main() {

    cout << Solution::numSquares(12) << endl;
    cout << Solution::numSquares(13) << endl;
    return 0;
}