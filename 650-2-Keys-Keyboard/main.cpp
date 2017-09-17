#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // OUT OF MEMORY
    static int minSteps(int n) {
        if (1 == n) {
            return 0;
        }

        vector<vector<int>> M(n);
        for (int i = 0; i < M.size(); ++i) {
            M[i].resize(i + 1, -1);
        }
        /*
        for (const auto &col:M) {
            for (const auto &cell:col) {
                cout << cell << " ";
            }
            cout << endl;
        }
         */

        int minimum;
        M[0][0] = 1;
        for (int i = 1; i < M.size(); ++i) {
            for (int j = i / 2; j >= 0; --j) {
                int k = i - j - 1;
                if ((k < j) || (-1 == M[k][j])) {
                    continue;
                }
                M[i][j] = M[k][j] + 1;
            }

            minimum = M[i][0];
            for (int j = M[i].size() - 1; j > 0; --j) {
                if ((-1 != M[i][j]) && (minimum > M[i][j])) {
                    minimum = M[i][j];
                }
            }
            M[i][i] = minimum + 1;
        }

        for (const auto &col:M) {
            for (const auto &cell:col) {
                cout << cell << " ";
            }
            cout << endl;
        }

        minimum = M.back()[0];
        for (const auto &cell:M.back()) {
            if ((-1 != cell) && (minimum > cell)) {
                minimum = cell;
            }
        }

        return minimum;
    }

};

int main() {
    cout << Solution::minSteps(5) << endl;

    return 0;
}