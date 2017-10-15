#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges) {
        if (1 == n) {
            return {0};
        } else if (2 == n) {
            return {0, 1};
        }

        // graph
        vector<unordered_set<int>> G(n);

        // build the graph
        for (const auto &e : edges) {
            G[e.first].insert(e.second);
            G[e.second].insert(e.first);
        }

        vector<bool> is_leaf(n);
        int num_nodes = 3;
        vector<int> roots{-1, -1};
        while (num_nodes > 2) {
            for (int i = 0; i < G.size(); ++i) {
                is_leaf[i] = (1 == G[i].size());
                //cout << G.size() << endl;
            }

            num_nodes = 0;
            for (int i = 0; i < G.size(); ++i) {
                if (is_leaf[i]) {
                    auto itr = std::begin(G[i]);
                    G[*itr].erase(i);
                    G[i].clear();
                }

                if (!G[i].empty()) {
                    if (num_nodes < 2) { roots[num_nodes] = i; }
                    ++num_nodes;
                }
            }
        }

        if (1 == num_nodes) { roots.pop_back(); }

        return roots;
    }

};

int main() {
    const int NUM_CASES = 6;
    const int n[]{6, 4, 3, 2, 5, 6};
    vector<vector<pair<int, int>>> edges{
            {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}},
            {{1, 0}, {1, 2}, {1, 3}},
            {{0, 1}, {0, 2}},
            {{0, 1}},
            {{0, 1}, {0, 2}, {0, 3}, {3, 4}},
            {{0, 1}, {0, 2}, {0, 3}, {3, 4}, {4, 5}}
    };
    const vector<vector<int>> expected{
            {3, 4},
            {1},
            {0},
            {0, 1},
            {0, 3},
            {3},
    };

    for (int i = 0; i < NUM_CASES; ++i) {
        cout << "case " << i << ": " << endl;

        cout << "\t output: ";
        auto root_labels = Solution::findMinHeightTrees(n[i], edges[i]);
        for (const auto &l : root_labels) {
            cout << l << " ";
        }
        cout << endl;
        cout << "\t expected: ";
        for (const auto &x : expected[i]) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}