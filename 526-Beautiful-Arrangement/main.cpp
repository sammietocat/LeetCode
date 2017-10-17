#include <iostream>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
public:
    static int countArrangement(int N) {
        int num_perfect{};

        stack<tuple<int, int, int>> num_level_idx;
        for (int i = 1; i <= N; ++i) {
            num_level_idx.emplace(i, 1, i);
        }

        vector<bool> in_use(N + 1, false);
        vector<int> prev(N + 1, 0), prev_idx(N + 1, 0);
        while (!num_level_idx.empty()) {
            auto num = std::get<0>(num_level_idx.top());
            auto level = std::get<1>(num_level_idx.top());
            auto idx = std::get<2>(num_level_idx.top());
            num_level_idx.pop();

            in_use[num] = true;
            if ((0 == num % level) || (0 == level % num)) {
                if (N == level) {
                    ++num_perfect;
                    in_use[num] = false;

                    while (1 == idx) {
                        prev[num] = false;
                        idx = prev_idx[idx];
                    }
                } else {
                    int num_left = 0;
                    for (int i = 1; i <= N; ++i) {
                        if (in_use[i]) { continue; }

                        num_level_idx.emplace(i, level + 1, ++num_left);

                    }
                }
            } else {
                in_use[num] = false;

                while (1 == idx) {
                    prev[num] = false;
                    idx = prev_idx[idx];
                }
            }
        }

        return num_perfect;
    }
};

int main() {
    const int N[]{2};

    for (const auto n : N) {
        cout << n << ": " << Solution::countArrangement(n) << endl;
    }

    return 0;
}