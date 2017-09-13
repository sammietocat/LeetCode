#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> getRow(int rowIndex) {
        int rowSize = rowIndex+1;
        vector<int> rowk(rowSize, 1);
        if (rowSize <= 2) {
            return rowk;
        }

        vector<int> cache(rowSize, 1);
        for (int i = 2; i < rowSize; ++i) {
            // update cache
            for (int m = 1; m < i; ++m) {
                cache[m] = rowk[m];
            }

            for (int m = 1, n = i - 1; m <= n; ++m, --n) {
                rowk[n] = rowk[m] = cache[m - 1] + cache[m];
            }
        }

        return rowk;
    }
};

int main() {
    for (int i =0; i <= 6; ++i) {
        const auto &row = Solution::getRow(i);
        for (const auto &cell:row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}