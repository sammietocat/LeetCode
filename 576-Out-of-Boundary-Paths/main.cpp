#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int findPaths(int m, int n, int N, int i, int j) {
        const int ROUND = (int)(1e9)+7;

        vector<int> nOut(N + 1);
        vector<vector<int>> I(N + 1), J(N + 1);

        nOut[0] = 0;
        I[0].push_back(i);
        J[0].push_back(j);

        int prev;
        for (int k = 1; k <= N; ++k) {
            nOut[k] = nOut[k-1];

            prev = k - 1;
            for (int l = 0; l < I[prev].size(); ++l) {
                // up
                if (I[prev][l] - 1 < 0) {
                    ++nOut[k];
                } else {
                    I[k].push_back(I[prev][l] - 1);
                    J[k].push_back(J[prev][l]);
                }
                // right
                if (J[prev][l] + 1 >= n) {
                    ++nOut[k];
                } else {
                    I[k].push_back(I[prev][l]);
                    J[k].push_back(J[prev][l] + 1);
                }
                // bottom
                if (I[prev][l] + 1 >= m) {
                    ++nOut[k];
                } else {
                    I[k].push_back(I[prev][l] + 1);
                    J[k].push_back(J[prev][l]);
                }
                // left
                if (J[prev][l] - 1 < 0) {
                    ++nOut[k];
                } else {
                    I[k].push_back(I[prev][l]);
                    J[k].push_back(J[prev][l] - 1);
                }
            }
        }

        return nOut.back()%ROUND;
    }
};

int main() {
    //const int m = 1, n = 3, N = 3, i = 0, j = 1;
    //const int m = 2, n = 2, N = 2, i = 0, j = 0;
    const int m = 2, n = 2, N = 2, i = 0, j = 0;

    cout << Solution::findPaths(m, n, N, i, j) << endl;

    return 0;
}