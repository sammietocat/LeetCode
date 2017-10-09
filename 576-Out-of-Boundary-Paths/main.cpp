#include <iostream>

using namespace std;

class Solution {
public:
    static int findPaths(int m, int n, int N, int i, int j) {
        int num_paths[2][50][50]{};

        int curr{1}, prev{0};
        while (N--) {
            curr = 1 - curr;
            prev = 1 - prev;

            for (int row = 0; row < m; ++row) {
                for (int col = 0; col < n; ++col) {
                    num_paths[curr][row][col] = (0 == row ? 1 : num_paths[prev][row - 1][col]) % 1000000007;
                    num_paths[curr][row][col] = (num_paths[curr][row][col] +
                                                 (m - 1 == row ? 1 : num_paths[prev][row + 1][col])) % 1000000007;

                    num_paths[curr][row][col] = (num_paths[curr][row][col] +
                                                 (0 == col ? 1 : num_paths[prev][row][col - 1])) % 1000000007;
                    num_paths[curr][row][col] = (num_paths[curr][row][col] +
                                                 (n - 1 == col ? 1 : num_paths[prev][row][col + 1])) % 1000000007;

                    /*
                    num_paths[curr][row][col] = ((0 == row ? 1 : num_paths[prev][row - 1][col]) +
                                                 (m - 1 == row ? 1 : num_paths[prev][row + 1][col]) +
                                                 (0 == col ? 1 : num_paths[prev][row][col - 1]) +
                                                 (n - 1 == col ? 1 : num_paths[prev][row][col + 1])) % 1000000007;
                                                 */
                }
            }
        }

        return num_paths[curr][i][j];
    }

    static int findPathsV2(int m, int n, int N, int i, int j) {
        unsigned int g[2][50][50] = {};
        while (N-- > 0)
            for (auto k = 0; k < m; ++k)
                for (auto l = 0, nc = (N + 1) % 2, np = N % 2; l < n; ++l)
                    g[nc][k][l] = ((k == 0 ? 1 : g[np][k - 1][l]) +
                                   (k == m - 1 ? 1 : g[np][k + 1][l])
                                   + (l == 0 ? 1 : g[np][k][l - 1]) +
                                   (l == n - 1 ? 1 : g[np][k][l + 1])) % 1000000007;
        return g[1][i][j];
    }
};

int main() {
    //const int m = 1, n = 3, N = 3, i = 0, j = 1;
    //const int m = 2, n = 2, N = 2, i = 0, j = 0;
    //const int m = 2, n = 2, N = 2, i = 0, j = 0;
    //const int m = 8, n = 50, N = 23, i = 5, j = 26;
    const int m = 36, n = 5, N = 50, i = 15, j = 3;

    cout << Solution::findPaths(m, n, N, i, j) << endl;
    cout << Solution::findPathsV2(m, n, N, i, j) << endl;

    return 0;
}