#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    static int minSteps(int n) {
        if (1 == n) { return 0; }

        vector<int> min_ops(n + 1, 10000);
        //vector<vector<int>> buffer_size(n + 1, vector<int>{});
        vector<set<int>> buffer_size(n+1);

        min_ops[1] = 0;
        min_ops[2] = 2;
        buffer_size[1].emplace(0);
        buffer_size[2].emplace(1);

        for (int i = 3; i <= n; ++i) {
            //for (int j = i - 1; j >= 0; --j) {
            for (int j = i / 2; j < i; ++j) {
                //cout << i << " - " << j << endl;

                int tmp_ops;
                // check if one paste is enough
                for (const auto &bf:buffer_size[j]) {
                    if (!bf || (0 != (i - j) % bf)) { continue; }

                    tmp_ops = min_ops[j] + (i - j) / bf;
                    if (min_ops[i] >= tmp_ops) {
                        if (min_ops[i] != tmp_ops) { buffer_size[i].clear(); }

                        //buffer_size[i].push_back(bf);
                        buffer_size[i].emplace(bf);
                        min_ops[i] = tmp_ops;
                    }
                }

                // check if one copy and one paste would be better
                if (j + j == i) {
                    tmp_ops = min_ops[j] + 2;
                    if (min_ops[i] >= tmp_ops) {
                        if (min_ops[i] != tmp_ops) { buffer_size[i].clear(); }

                        //buffer_size[i].push_back(j);
                        buffer_size[i].emplace(j);
                        min_ops[i] = tmp_ops;
                    }
                }
            }
        }

        /*
        for (int i = 1; i <= n; ++i) {
            cout << "(" << i << ", " << min_ops[i] << ", [";
            for (const auto &bf:buffer_size[i]) {
                cout << bf << ", ";
            }
            cout << "])" << endl;
        }
        */

        return min_ops.back();
    }

};

int main() {

    for (int n = 7; n < 8; ++n) {
        cout << Solution::minSteps(n) << endl;
    }

    return 0;
}