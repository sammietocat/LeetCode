#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    const int NUM_OFFSET = 8;
    int OFFSET[8][2] = {
            {-2, 1},
            {-1, 2},
            {1,  2},
            {2,  1},
            {2,  -1},
            {1,  -2},
            {-1, -2},
            {-2, -1},
    };

    struct PairHasher {
        std::hash<int> std_hasher;

        size_t operator()(const pair<int, int> &pr) const {
            return std_hasher(pr.first) ^ std_hasher(pr.second);
        }
    };

    double knightProbability(int N, int K, int r, int c) {
        //vector<vector<int>> grids(N, vector<int>(N, 0)), tmp(N, vector<int>(N, 0));
        unordered_map<pair<int, int>, double, PairHasher> grids;
        pair<int, int> pos{r, c};

        grids[pos] = 1;
        while (K--) {
            unordered_map<pair<int, int>, double, PairHasher> tmp;

            for (const auto &grid:grids) {
                for (int i = 0; i < NUM_OFFSET; ++i) {
                    pos.first = grid.first.first + OFFSET[i][0];
                    pos.second = grid.first.second + OFFSET[i][1];

                    if ((pos.first < 0) || (pos.first >= N) ||
                        (pos.second < 0) || (pos.second >= N)) {
                        continue;
                    }

                    tmp[pos] += 0.125 * grid.second;
                }
            }

            grids.swap(tmp);
            /*
            for (const auto &grid : grids) {
                cout << "(" << grid.first.first << ", " << grid.first.second << ", " << grid.second << ")" << endl;
            }
             */
        }

        double pr{};
        for (const auto &grid : grids) {
            pr += grid.second;
        }

        return pr;
    }
};

int main() {
    const int N{3}, K{2}, r{0}, c{0};
    //const int N{3}, K{2}, r{1}, c{1};

    Solution solu;
    cout << solu.knightProbability(N, K, r, c) << endl;

    return 0;
}