#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
        if ((1 == M.size()) && (1 == M[0].size())) {
            return M;
        }

        const int ROW = M.size();
        const int COL = M[0].size();
        vector<vector<int>> SM(ROW);
        for (int i = 0; i < ROW; ++i) {
            SM[i].resize(COL);
        }

        // case: 1 row
        if (1 == ROW) {
            // left corner
            SM[0][0] = (M[0][0] + M[0][1]) / 2;
            // right corner
            SM[0][COL - 1] = (M[0][COL - 1] + M[0][COL - 2]) / 2;

            for (int i = 1; i < COL - 1; ++i) {
                SM[0][i] = (M[0][i - 1] + M[0][i] + M[0][i + 1]) / 3;
            }
        } else if (COL == 1) { // case: 1 column
            // upper corner
            SM[0][0] = (M[0][0] + M[1][0]) / 2;
            // bottom corner
            SM[ROW - 1][0] = (M[ROW - 1][0] + M[ROW - 2][0]) / 2;

            for (int i = 1; i < ROW - 1; ++i) {
                SM[i][0] = (M[i - 1][0] + M[i][0] + M[i + 1][0]) / 3;
            }
        } else { // case at least 2 rows*2 columns
            // size of the area
            int nCell = 4;

            // position of the upper-left corner for a area to smooth
            int x, y;
            // upper-left corner
            x = y = 0;
            SM[y][x] = (M[y][x] + M[y][x + 1] + M[y + 1][x + 1] + M[y + 1][x]) / nCell;
            // upper-right corner
            y = 0;
            x = COL - 2;
            SM[y][x + 1] = (M[y][x] + M[y][x + 1] + M[y + 1][x + 1] + M[y + 1][x]) / nCell;
            // bottom-right corner
            y = ROW - 2;
            x = COL - 2;
            SM[y + 1][x + 1] = (M[y][x] + M[y][x + 1] + M[y + 1][x + 1] + M[y + 1][x]) / nCell;
            // bottom-left corner
            y = ROW - 2;
            x = 0;
            SM[y + 1][x] = (M[y][x] + M[y][x + 1] + M[y + 1][x + 1] + M[y + 1][x]) / nCell;


            nCell = 6;
            int prev2Sum[3];
            // 1st row
            {
                // sum of the first 2 columns
                prev2Sum[0] = M[0][0] + M[1][0];
                prev2Sum[1] = M[0][1] + M[1][1];

                // iterate through
                for (x = 1; x < COL - 1; ++x) {
                    prev2Sum[2] = M[0][x + 1] + M[1][x + 1];
                    SM[0][x] = (prev2Sum[0] + prev2Sum[1] + prev2Sum[2]) / nCell;

                    prev2Sum[0] = prev2Sum[1];
                    prev2Sum[1] = prev2Sum[2];
                }
            }
            // last row
            {
                y = ROW - 1;
                // sum of the first 2 columns
                prev2Sum[0] = M[y - 1][0] + M[y][0];
                prev2Sum[1] = M[y - 1][1] + M[y][1];

                // iterate through
                for (x = 1; x < COL - 1; ++x) {
                    prev2Sum[2] = M[y - 1][x + 1] + M[y][x + 1];
                    SM[y][x] = (prev2Sum[0] + prev2Sum[1] + prev2Sum[2]) / nCell;

                    prev2Sum[0] = prev2Sum[1];
                    prev2Sum[1] = prev2Sum[2];
                }
            }

            // 2nd row to last but one row
            nCell = 9;
            {
                for (y = 1; y < ROW - 1; ++y) {
                    // sum of the first 2 columns
                    prev2Sum[0] = M[y - 1][0] + M[y][0] + M[y + 1][0];
                    prev2Sum[1] = M[y - 1][1] + M[y][1] + M[y + 1][1];
                    //cout << "y=1,x=0" << endl;
                    //cout << prev2Sum[0] << "-" << endl;

                    // 1st cell
                    SM[y][0] = (prev2Sum[0] + prev2Sum[1]) / 6;
                    // iterate through cells in the y-th row
                    for (x = 1; x < COL - 1; ++x) {
                        prev2Sum[2] = M[y - 1][x + 1] + M[y][x + 1] + M[y + 1][x + 1];

                        //cout << "y=1,x=" << x << endl;
                        //cout << prev2Sum[0] << "-" << prev2Sum[1] << "-" << prev2Sum[2] << endl;


                        SM[y][x] = (prev2Sum[0] + prev2Sum[1] + prev2Sum[2]) / nCell;

                        prev2Sum[0] = prev2Sum[1];
                        prev2Sum[1] = prev2Sum[2];
                    }
                    // last cell
                    SM[y][x] = (prev2Sum[0] + prev2Sum[1]) / 6;
                }
            }

        }

        return SM;

    }
};

int main() {
    /*
    vector<vector<int> > M =
            {{1, 1, 1},
             {1, 0, 1},
             {1, 1, 1}};
     */
    /*
    vector<vector<int> > M =
            {{1},
             {0},
             {1}};
             */

    vector<vector<int>> M = {{2,  3,  4},
                             {5,  6,  7},
                             {8,  9,  10},
                             {11, 12, 13},
                             {14, 15, 16}};
    /**
     * [[4,4,5],
     *  [5,6,6],
     *  [8,9,9],
     *  [11,12,12],
     *  [13,13,14]]
     */
    /*
    for (const auto &row:M) {
        for (const auto &c:row) {
            cout << c << " ";
        }
        cout << endl;
    }
     */

    auto SM = Solution::imageSmoother(M);
    for (const auto &row:SM) {
        for (const auto &c:row) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}