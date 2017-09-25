#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>> &M) {
        sets = vector<int>(M.size(), -1);

        for (int i = 0; i < M.size(); ++i) {
            for (int j = 0; j < M[i].size(); ++j) {
                if((j!=i) && M[i][j]) {
                    unionSets(i, j);
                }
            }
        }

        int n = 0;
        for (const auto &s:sets) {
            if (s < 0) {
                ++n;
            }
        }

        return n;
    }

    /**
     * @brief Perform a find with path compression.
     * @return the set containing x
     * */
    int find(int x) {
        if (x >= sets.size()) {
            return -1;
        }

        if (sets[x] < 0) {
            return x;
        } else {
            return sets[x] = find(sets[x]);
        }
    }

    /**
     * @brief   union the containing sets of 2 elements
     * @param i index of an element
     * @param j index of another element
     * */
    void unionSets(const int x, const int y) {
        // find set for x
        int root1 = find(x);
        // find set for y
        int root2 = find(y);

        // check if they are already in the same set
        if (root1 == root2) {
            return;
        }

        if (sets[root1] < sets[root2]) {  // root2 is deeper
            sets[root1] = root2;   // make root2 the new root
        } else {
            if (sets[root1] == sets[root2]) {
                --sets[root1]; // increment the height for set root1
            }

            sets[root2] = root1;   // make root1 the new root
        }
    }

private:
    vector<int> sets;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}