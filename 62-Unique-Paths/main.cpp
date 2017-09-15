#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int uniquePaths(int m, int n) {
        vector<vector<int>> mat{m,vector<int>(n,1)};

        for (int i = 1; i < mat.size(); ++i) {
            for (int j = 1; j < mat[i].size(); ++j) {
               mat[i][j] = mat[i-1][j]+mat[i][j-1];
            }
        }

        return mat.back().back();
    }
};

int main() {
    cout << Solution::uniquePaths(2,2) << endl;

    return 0;
}