#include <iostream>
#include <vector>
#include <queue>

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

        queue<pair<int, int>> cells_reachable;
        vector<vector<bool>> reachable_to_atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            cells_reachable.emplace(i, n - 1);
            reachable_to_atlantic[i][n - 1] = true;
        }
        for (int i = 0; i < n - 1; ++i) {
            cells_reachable.emplace(m - 1, i);
            reachable_to_atlantic[m - 1][i] = true;
        }

        // BFS to find out all cells can flow into the Pacific
        while (!cells_reachable.empty()) {
            const auto &pr = cells_reachable.front();

            int y, x;
            // upper
            y = pr.first - 1;
            x = pr.second;
            if ((y >= 0) && !reachable_to_atlantic[y][x] &&
                (matrix[y][x] >= matrix[pr.first][pr.second])) {
                cells_reachable.emplace(y, x);
                reachable_to_atlantic[y][x] = true;
            }
            // right
            y = pr.first;
            x = pr.second + 1;
            if ((x < n) && !reachable_to_atlantic[y][x] &&
                (matrix[y][x] >= matrix[pr.first][pr.second])) {
                cells_reachable.emplace(y, x);
                reachable_to_atlantic[y][x] = true;
            }
            // bottom
            y = pr.first + 1;
            x = pr.second;
            if ((y < m) && !reachable_to_atlantic[y][x] &&
                (matrix[y][x] >= matrix[pr.first][pr.second])) {
                cells_reachable.emplace(y, x);
                reachable_to_atlantic[y][x] = true;
            }
            // left
            y = pr.first;
            x = pr.second - 1;
            if ((x >= 0) && !reachable_to_atlantic[y][x] &&
                (matrix[y][x] >= matrix[pr.first][pr.second])) {
                cells_reachable.emplace(y, x);
                reachable_to_atlantic[y][x] = true;
            }

            cells_reachable.pop();
        }

        // check for cells which can flow to the Pacific
        vector<vector<bool>> reachable_to_pacific(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            cells_reachable.emplace(i, 0);
            reachable_to_pacific[i][0] = true;
        }
        for (int i = 1; i < n; ++i) {
            cells_reachable.emplace(0, i);
            reachable_to_pacific[0][i] = true;
        }

        while (!cells_reachable.empty()) {
            const auto &pr = cells_reachable.front();

            if (reachable_to_atlantic[pr.first][pr.second]) {
                grids.emplace_back(pr.first, pr.second);
            }
            //cout << "**" << endl;
            //cout << "(" << pr.first << ", " << pr.second << ")" << endl;

            int y, x;
            // upper
            y = pr.first - 1;
            x = pr.second;
            if ((y >= 0) && !reachable_to_pacific[y][x] &&
                (matrix[y][x] >= matrix[pr.first][pr.second])) {
                cells_reachable.emplace(y, x);

                //cout << "\t(" << y << ", " << x << ")" << endl;
                reachable_to_pacific[y][x] = true;
            }
            // right
            y = pr.first;
            x = pr.second + 1;
            if ((x < n) && !reachable_to_pacific[y][x] &&
                (matrix[y][x] >= matrix[pr.first][pr.second])) {
                cells_reachable.emplace(y, x);
                //cout << "\t(" << y << ", " << x << ")" << endl;
                reachable_to_pacific[y][x] = true;
            }
            // bottom
            y = pr.first + 1;
            x = pr.second;
            if ((y < m) && !reachable_to_pacific[y][x] &&
                (matrix[y][x] >= matrix[pr.first][pr.second])) {
                cells_reachable.emplace(y, x);
                //cout << "\t(" << y << ", " << x << ")" << endl;
                reachable_to_pacific[y][x] = true;
            }
            // left
            y = pr.first;
            x = pr.second - 1;
            if ((x >= 0) && !reachable_to_pacific[y][x] &&
                (matrix[y][x] >= matrix[pr.first][pr.second])) {
                cells_reachable.emplace(y, x);
                //cout << "\t(" << y << ", " << x << ")" << endl;
                reachable_to_pacific[y][x] = true;
            }

            cells_reachable.pop();
        }

        return grids;
    }
};

int main() {
    vector<vector<int>> matrix{
            {1, 2, 2, 3, 5},
            {3, 2, 3, 4, 4},
            {2, 4, 5, 3, 1},
            {6, 7, 1, 4, 5},
            {5, 1, 1, 2, 4},
    };
    /*
    vector<vector<int>> matrix{
            {1, 2, 3},
            {8, 9, 4},
            {7, 6, 5},
    };
     */
    /*
    vector<vector<int>> matrix{
            {1,  2,  3,  4},
            {12, 13, 14, 5},
            {11, 16, 15, 6},
            {10, 9,  8,  7},
    };
     */

    auto grids = Solution::pacificAtlantic(matrix);
    for (const auto &grid:grids) {
        cout << "[" << grid.first << ", " << grid.second << "]" << endl;
    }

    return 0;
}