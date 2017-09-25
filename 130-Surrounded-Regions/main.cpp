#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        const int rows = board.size();
        if (0 == rows) { return; }
        const int cols = board.back().size();
        if (0 == cols) { return; }

        sets = vector<int>(rows * cols, -1);

        int offset, x, y;
        for (int row = 0; row < rows; ++row) {
            offset = row * cols;
            for (int col = 0; col < cols; ++col) {
                if ('X' == board[row][col]) { continue; }

                // upper
                y = row - 1;
                x = col;
                if ((y >= 0) && ('O' == board[y][x])) {
                    unionSets(y * cols + x, offset + col);
                }

                // left
                y = row;
                x = col - 1;
                if ((x >= 0) && ('O' == board[y][x])) {
                    unionSets(y * cols + x, offset + col);
                }

                if ((0 == row) || (rows - 1 == row) || (0 == col) || (cols - 1 == col)) {
                    uncapturedO.emplace(find(offset + col));
                }
            }
        }

        // bottom-up, right-left
        for (int row = 0; row < rows; ++row) {
            offset = row * cols;
            for (int col = 0; col < cols; ++col) {
                if (('X' == board[row][col])
                    || uncapturedO.count(find(offset + col))) {
                    continue;
                }
                board[row][col] = 'X';
            }
        }
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

        if (root1 == root2) {
            return false;
        }

        if (sets[root1] < sets[root2]) {  // root2 is deeper
            sets[root1] = root2;   // make root2 the new root

            if (uncapturedO.count(root1)) { uncapturedO.emplace(root2); }
        } else {
            if (sets[root1] == sets[root2]) {
                --sets[root1]; // increment the height for set root1
            }

            sets[root2] = root1;   // make root1 the new root
            if (uncapturedO.count(root2)) { uncapturedO.emplace(root1); }
        }

        return true;
    }

private:
    vector<int> sets;
    unordered_set<int> uncapturedO;
};

int main() {
    /*
    vector<vector<char>> board = {
            {'X', 'X', 'X', 'X'},
            {'X', 'O', 'O', 'X'},
            {'X', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'X'},
    };*/
    vector<vector<char>> board = {
            {'O', 'O'},
            {'O', 'O'},
    };

    Solution solu;

    solu.solve(board);

    for (const auto &row:board) {
        for (const auto &cell:row) {
            cout << cell;
        }
        cout << endl;
    }

    return 0;
}
