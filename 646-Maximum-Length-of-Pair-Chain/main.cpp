#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int findLongestChain(vector<vector<int>> &pairs) {
        if (pairs.empty()) { return 0; }

        std::sort(std::begin(pairs), std::end(pairs),
                  [](const vector<int> &pr1, const vector<int> &pr2) {
                      if (pr1[1] == pr2[1]) { return pr1[0] <= pr2[0]; }

                      return pr1[1] <= pr2[1];
                  });

        int len{1}, tail_prev{pairs[0][1]};
        for (const auto &pr : pairs) {
            if (pr[0] <= tail_prev) { continue; }

            ++len;
            tail_prev = pr[1];
        }

        return len;
    }
};

int main() {
    vector<vector<int>> pairs{
            {1, 2},
            {2, 3},
            {3, 4},
    };

    cout << Solution::findLongestChain(pairs) << endl;

    return 0;
}