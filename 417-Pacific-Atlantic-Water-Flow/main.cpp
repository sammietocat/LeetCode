#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<pair<int, int>> pacificAtlantic(vector<vector<int>> &matrix) {
        vector<pair<int, int>> grids;
        if (matrix.empty() || matrix.back().empty()) {
            return grids;
        }

        int m = matrix.size();
        int n = matrix.back().size();

        vector<vector<bool>> reachable_to_pacific(m, vector<bool>(n));
        // from Pacific top-left to bottom-right
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((0 == i) || (0 == j)) {
                    reachable_to_pacific[i][j] = true;
                    continue;
                }

                reachable_to_pacific[i][j] = (reachable_to_pacific[i - 1][j] && (matrix[i][j] >= matrix[i - 1][j]));
                reachable_to_pacific[i][j] = (reachable_to_pacific[i][j] ||
                                              (reachable_to_pacific[i][j - 1] && (matrix[i][j] >= matrix[i][j - 1])));
            }
        }
        // from Pacific bottom-right to top-left
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (reachable_to_pacific[i][j]) { continue; }

                if ((j < n - 1) && reachable_to_pacific[i][j + 1] &&
                    (matrix[i][j] >= matrix[i][j + 1])) {
                    reachable_to_pacific[i][j] = true;
                }

                if (!reachable_to_pacific[i][j] && (i < m - 1) && reachable_to_pacific[i + 1][j] &&
                    (matrix[i][j] >= matrix[i + 1][j])) {
                    reachable_to_pacific[i][j] = true;
                }
            }
        }

        /*
        for (const auto &row : reachable_to_pacific) {
            for (const auto &cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
        cout << "***" << endl;
         */

        vector<vector<bool>> reachable_to_atlantic(m, vector<bool>(n));
        // from Atlantic bottom-right to top-left
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if ((m - 1 == i) || (n - 1 == j)) {
                    reachable_to_atlantic[i][j] = true;
                    continue;
                }

                reachable_to_atlantic[i][j] = (reachable_to_atlantic[i + 1][j] && (matrix[i][j] >= matrix[i + 1][j]));
                reachable_to_atlantic[i][j] = (reachable_to_atlantic[i][j] ||
                                               (reachable_to_atlantic[i][j + 1] && (matrix[i][j] >= matrix[i][j + 1])));
            }
        }
        /*
        for (const auto &row : reachable_to_atlantic) {
            for (const auto &cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
        cout << "***" << endl;
         */
        // from Atlantic top-left to bottom-right
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (reachable_to_atlantic[i][j]) { continue; }

                if ((j > 0) && reachable_to_atlantic[i][j - 1] &&
                    (matrix[i][j] >= matrix[i][j - 1])) {
                    reachable_to_atlantic[i][j] = true;
                }

                if (!reachable_to_atlantic[i][j] && (i > 0) && reachable_to_atlantic[i - 1][j] &&
                    (matrix[i][j] >= matrix[i - 1][j])) {
                    reachable_to_atlantic[i][j] = true;
                }
            }
        }
        /*
        for (const auto &row : reachable_to_atlantic) {
            for (const auto &cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
        cout << "***" << endl;
         */

        // final round
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (reachable_to_pacific[i][j] && reachable_to_atlantic[i][j]) {
                    grids.emplace_back(i, j);
                }
            }
        }

        return grids;
    }
};

int main() {
    /*
    vector<vector<int>> matrix{
            {1, 2, 2, 3, 5},
            {3, 2, 3, 4, 4},
            {2, 4, 5, 3, 1},
            {6, 7, 1, 4, 5},
            {5, 1, 1, 2, 4},
    };
     */
    /*
    vector<vector<int>> matrix{
            {1, 2, 3},
            {8, 9, 4},
            {7, 6, 5},
    };
     */
    vector<vector<int>> matrix{
            {1,  2,  3,  4},
            {12, 13, 14, 5},
            {11, 16, 15, 6},
            {10, 9,  8,  7},
    };

    auto grids = Solution::pacificAtlantic(matrix);
    for (const auto &grid:grids) {
        cout << "[" << grid.first << ", " << grid.second << "]" << endl;
    }

    return 0;
}