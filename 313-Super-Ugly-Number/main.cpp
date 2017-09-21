#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int nthSuperUglyNumber(int n, vector<int> &primes) {
        vector<int> vec(n);
        vec[0] = 1;

        vector<int> x{std::begin(primes), std::end(primes)};
        vector<int> idx(primes.size(), 0);
        int minX, minXIdx;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < primes.size(); ++j) {
                while (x[j] <= vec[i - 1]) {
                    x[j] = vec[++idx[j]] * primes[j];
                }
            }

            minX = x[0];
            minXIdx = 0;
            for (int k = 1; k < primes.size(); ++k) {
                if (minX > x[k]) {
                    minX = x[k];
                    minXIdx = k;
                }
            }

            vec[i] = minX;
            x[minXIdx] = vec[++idx[minXIdx]] * primes[minXIdx];
        }


        return vec.back();
    }
};

int main() {
    vector<int> primes{2, 7, 13, 19};
    for (int n = 1; n < 20; ++n) {
        cout << Solution::nthSuperUglyNumber(n, primes) << endl;
    }

    return 0;
}