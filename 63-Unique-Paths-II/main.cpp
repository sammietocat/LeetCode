#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        vector<vector<int>> mat{obstacleGrid.size(), vector<int>(obstacleGrid.front().size(), 0)};

        // handle 1st row
        for (int j = 0; j < obstacleGrid[0].size(); ++j) {
            if (0 == obstacleGrid[0][j]) {
                mat[0][j] = 1;
            } else {
                break;
            }
        }
        // handle 1st column
        for (int i = 0; i < obstacleGrid.size(); ++i) {
            if (0 == obstacleGrid[i][0]) {
                mat[i][0] = 1;
            } else {
                break;
            }
        }

        // other rows and columns
        for (int i = 1; i < mat.size(); ++i) {
            for (int j = 1; j < mat[i].size(); ++j) {
                if (1 == obstacleGrid[i][j]) {
                    continue;
                }
                mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
            }
        }

        return mat.back().back();
    }
};

int main() {
    vector<vector<int>> obstacleGrid = {
            /*
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
             */
            {1},
            {0}
    };
    cout << Solution::uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}
