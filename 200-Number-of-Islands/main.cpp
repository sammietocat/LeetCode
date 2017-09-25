#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        // invoke empty() will be slower
        /*
         * if(grid.empty() || grid[0].empty()) {return 0;}
         */
        const int rows = grid.size();
        if (0 == rows) { return 0; }
        const int cols = grid.back().size();
        if (0 == cols) { return 0; }

        sets = vector<int>(rows * cols, -1);
        nLand = 0;

        int offset, x, y;
        bool isolated;
        for (int row = 0; row < rows; ++row) {
            offset = row * cols;
            for (int col = 0; col < cols; ++col) {
                if ('0' == grid[row][col]) { continue; }

                isolated = true;
                // upper
                y = row - 1;
                x = col;
                if ((y >= 0) && ('1' == grid[y][x])) {
                    unionSets(y * cols + x, offset + col);
                    isolated = false;
                }

                // left
                y = row;
                x = col - 1;
                if ((x >= 0) && ('1' == grid[y][x])) {
                    if (unionSets(y * cols + x, offset + col)) {
                        if (!isolated) { --nLand; }
                    }

                    isolated = false;
                }

                if (isolated) {
                    ++nLand;
                }
            }
        }

        return nLand;
    }

    /**
     * @brief Perform a find with path compression.
     * @return the set containing x
     * */
    size_t find(size_t x) {
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
     * @return true means union is done, and false means no union needed
     * */
    bool unionSets(const size_t x, const size_t y) {
        // find set for x
        size_t root1 = find(x);
        // find set for y
        size_t root2 = find(y);

        //cout << "root1 = " << root1 << ", root2 = " << root2 << endl;
        if (root1 == root2) {
            return false;
        }

        if (sets[root1] < sets[root2]) {  // root2 is deeper
            sets[root1] = root2;   // make root2 the new root
        } else {
            if (sets[root1] == sets[root2]) {
                --sets[root1]; // increment the height for set root1
            }

            sets[root2] = root1;   // make root1 the new root
        }

        return true;
    }

private:
    vector<int> sets;
    int nLand;
};

int main() {
    /*
    vector<vector<char>> grid = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'},
    };
     */
    vector<vector<char>> grid = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'},
    };

    Solution solu;

    cout << solu.numIslands(grid) << endl;

    return 0;
}