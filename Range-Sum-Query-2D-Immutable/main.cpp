#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        cache.resize(matrix.size());
        for (int i = 0; i < matrix.size(); ++i) {

            cache[i].resize(matrix[i].size());
            cache[i][0] = matrix[i][0];
            //cout << cache[i][0]<<" ";
            for (int j = 1; j < matrix[i].size(); ++j) {
                cache[i][j] = cache[i][j - 1] + matrix[i][j];
                //cout << cache[i][j]<<" ";
            }
            //cout <<endl;
        }
        //cout << endl;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        if (col1 > 0) {
            for (int i = row1; i <= row2; ++i) {
                sum += cache[i][col2] - cache[i][col1 - 1];
            }
        } else {
            for (int i = row1; i <= row2; ++i) {
                sum += cache[i][col2];
            }
        }

        return sum;
    }

private:
    vector<vector<int>> cache;
};

int main() {
    /*
    vector<vector<int>> matrix = {
            {3, 0, 1, 4, 2},
            {5, 6, 3, 2, 1},
            {1, 2, 0, 1, 5},
            {4, 1, 0, 1, 7},
            {1, 0, 3, 0, 5}
    };
     */

    vector<vector<int>> matrix = {
            {1},
            {-7}
    };

    /*
    for (const auto &row:matrix) {
        for (const auto &col:row) {
            cout << col << " ";
        }
        cout << endl;
    }
     */

    NumMatrix nm(matrix);
    const int nCases = 3;
    const int rowVec[nCases][2] = {
            {0, 0},
            {1, 1},
            {0, 1}
    };
    const int colVec[nCases][2] = {
            {0, 0},
            {0, 0},
            {0, 0}
    };

    for (int i = 0; i < nCases; ++i) {
        cout << nm.sumRegion(rowVec[i][0], colVec[i][0], rowVec[i][1], colVec[i][1]) << endl;
    }

    return 0;
}