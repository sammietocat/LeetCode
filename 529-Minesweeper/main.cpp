#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    static vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {
        int rows = board.size(), cols = board.back().size();
        vector<vector<char>> board_new{std::begin(board), std::end(board)};

        queue<pair<int, int>> bfs;
        vector<vector<bool>> is_visited(rows, vector<bool>(cols, false));
        vector<pair<int, int>> adjacent_cells;
        adjacent_cells.reserve(8);

        bfs.emplace(click[0], click[1]);
        while (!bfs.empty()) {
            auto &pr = bfs.front();
            bfs.pop();
            //is_visited[pr.first][pr.second] = true;

            if ('M' == board_new[pr.first][pr.second]) {
                board_new[pr.first][pr.second] = 'X';
                break;
            }

            int num_mine{0};
            int y, x;

            //cout << pr.first << ", " << pr.second << endl;
            // try to unreveal surroundings
            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    if ((0 == dx) && (0 == dy)) { continue; }

                    y = pr.first + dy;
                    x = pr.second + dx;
                    if ((y < 0) || (y >= rows) || (x < 0) || (x >= cols)) { continue; }

                    if ('M' == board_new[y][x]) {
                        ++num_mine;
                    } else if (('E' == board_new[y][x]) && !is_visited[y][x]) {
                        adjacent_cells.emplace_back(y, x);
                    }
                }
            }

            //cout << "\tnum_mine=" << num_mine << endl;
            if (0 == num_mine) {
                board_new[pr.first][pr.second] = 'B';

                for (const auto &cell:adjacent_cells) {
                    //cout << "\t" << cell.first << ", " << cell.second << endl;
                    is_visited[cell.first][cell.second] = true;
                    bfs.emplace(cell.first, cell.second);
                }
            } else {
                board_new[pr.first][pr.second] = (char) ('0' + num_mine);
                //break;
            }
            adjacent_cells.clear();
        }

        return board_new;
    }
};

int main() {
    /*
    vector<vector<char>> board{{'E', 'E', 'E', 'E', 'E'},
                               {'E', 'E', 'M', 'E', 'E'},
                               {'E', 'E', 'E', 'E', 'E'},
                               {'E', 'E', 'E', 'E', 'E'}
    };
    vector<int> click{3, 0};
    */
    ///*
    vector<vector<char>> board{{'B', '1', 'E', '1', 'B'},
                               {'B', '1', 'M', '1', 'B'},
                               {'B', '1', '1', '1', 'B'},
                               {'B', 'B', 'B', 'B', 'B'}};
    vector<int> click{1, 2};
     //*/
    /*
    vector<vector<char>> board{{'E'},};
    vector<int> click{0, 0};
     */

    auto board_new = Solution::updateBoard(board, click);
    for (const auto &row : board_new) {
        for (const auto &cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }


    return 0;
}