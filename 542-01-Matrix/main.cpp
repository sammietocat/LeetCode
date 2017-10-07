#include <iostream>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    // by dynamic programming
    static vector<vector<int>> updateMatrixV2(vector<vector<int>> &matrix) {
        if (matrix.empty()) { return {}; }

        const int SENTINEL = 10000 + 1;
        int rows = matrix.size(), cols = matrix.back().size();
        vector<vector<int>> distances(rows, vector<int>(cols, SENTINEL));

        // forward search
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (0 == matrix[i][j]) {
                    distances[i][j] = 0;
                    continue;
                }

                if (i && (distances[i][j] > distances[i - 1][j] + 1)) {
                    distances[i][j] = distances[i - 1][j] + 1;
                }
                if (j && (distances[i][j] > distances[i][j - 1] + 1)) {
                    distances[i][j] = distances[i][j - 1] + 1;
                }
            }
        }

        // backward
        for (int i = rows - 1; i >= 0; --i) {
            for (int j = cols - 1; j >= 0; --j) {
                if (0 == matrix[i][j]) { continue; }

                if ((i < rows - 1) && (distances[i][j] > distances[i + 1][j] + 1)) {
                    distances[i][j] = distances[i + 1][j] + 1;
                }
                if ((j < cols - 1) && (distances[i][j] > distances[i][j + 1] + 1)) {
                    distances[i][j] = distances[i][j + 1] + 1;
                }
            }
        }

        return distances;
    }

    using PairType = pair<int, int>;

    static vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty()) { return {}; }

        int rows = matrix.size(), cols = matrix.back().size();
        vector<vector<int>> distances(rows, vector<int>(cols, 10001));

        map<PairType, PairType> vertex_known;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (0 == matrix[i][j]) {
                    distances[i][j] = 0;
                    continue;
                }

                if ((i > 0) && (distances[i][j] > distances[i - 1][j])) {
                    distances[i][j] = distances[i - 1][j] + 1;
                }
                if ((j > 0) && (distances[i][j] > distances[i][j - 1])) {
                    distances[i][j] = distances[i][j - 1] + 1;
                }

                vertex_known.clear();
                queue<tuple<int, int, int>> bfs;

                int y{i}, x{j}, d{1};
                PairType tail{y, x};

                bfs.emplace(y, x, d);
                vertex_known.emplace(tail, tail);

                while (!bfs.empty()) {
                    y = std::get<0>(bfs.front());
                    x = std::get<1>(bfs.front());
                    d = std::get<2>(bfs.front());

                    if (d >= distances[i][j]) { break; }

                    PairType pr{y + 1, x};
                    if ((pr.first < rows) && (std::end(vertex_known) == vertex_known.find(pr))) {
                        vertex_known.emplace(pr, make_pair(y, x));
                        if (0 == matrix[pr.first][pr.second]) {
                            distances[pr.first][pr.second] = 0;

                            tail.first = pr.first;
                            tail.second = pr.second;
                            break;
                        } else if (10001 != distances[pr.first][pr.second]) {
                            if (distances[i][j] > d + distances[pr.first][pr.second]) {
                                distances[i][j] = d + distances[pr.first][pr.second];

                                tail.first = pr.first;
                                tail.second = pr.second;
                            }
                        } else {
                            bfs.emplace(pr.first, pr.second, d + 1);
                        }

                    }

                    pr.first = y;
                    pr.second = x + 1;
                    if ((pr.second < cols) && (std::end(vertex_known) == vertex_known.find(pr))) {
                        vertex_known.emplace(pr, make_pair(y, x));
                        if (0 == matrix[pr.first][pr.second]) {
                            distances[pr.first][pr.second] = 0;

                            tail.first = pr.first;
                            tail.second = pr.second;
                            break;
                        } else if (10001 != distances[pr.first][pr.second]) {
                            if (distances[i][j] > d + distances[pr.first][pr.second]) {
                                distances[i][j] = d + distances[pr.first][pr.second];

                                tail.first = pr.first;
                                tail.second = pr.second;
                            }
                        } else {
                            bfs.emplace(pr.first, pr.second, d + 1);
                        }
                    }

                    bfs.pop();
                }

                if (d < distances[i][j]) {
                    while (vertex_known[tail] != tail) {
                        y = vertex_known[tail].first;
                        x = vertex_known[tail].second;
                        distances[y][x] = distances[tail.first][tail.second] + 1;

                        //cout << tail.first << ", " << tail.second << "->" << y << ", " << x << endl;

                        tail.first = y;
                        tail.second = x;
                    }
                }
            }
        }

        return distances;
    }
};

int main() {
    /*
    vector<vector<int>> matrix{
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };
    */
    /*
    vector<vector<int>> matrix{
            {0, 0, 0},
            {0, 1, 0},
            {1, 1, 1}
    };
     */
    /*
    vector<vector<int>> matrix{
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 0}
    };
     */
    /*
    vector<vector<int>> matrix{
            {0, 1, 1, 0, 0},
            {0, 1, 1, 0, 0},
            {0, 1, 0, 0, 1},
            {1, 1, 1, 1, 0},
            {1, 0, 0, 1, 0},
    };
     */
    /*
    vector<vector<int>> matrix{
            {0, 0, 1, 0, 1, 1, 1, 0, 1, 1},
            {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 0, 0, 0, 1, 1},
            {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
            {0, 0, 1, 1, 1, 0, 1, 1, 1, 1},
            {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
            {0, 1, 0, 0, 0, 1, 0, 0, 1, 1},
            {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
            {1, 0, 1, 1, 1, 0, 1, 1, 1, 0}
    };
     */
    /*
    vector<vector<int>> expected{{0, 0, 1, 0, 1, 2, 1, 0, 1, 2},
                                 {1, 1, 2, 1, 0, 1, 1, 1, 2, 3},
                                 {2, 1, 2, 1, 1, 0, 0, 0, 1, 2},
                                 {1, 0, 1, 0, 1, 1, 1, 0, 1, 2},
                                 {0, 0, 1, 1, 1, 0, 1, 1, 2, 3},
                                 {1, 0, 1, 2, 1, 1, 1, 2, 1, 2},
                                 {1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
                                 {0, 1, 0, 0, 0, 1, 0, 0, 1, 2},
                                 {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
                                 {1, 0, 1, 1, 1, 0, 1, 2, 1, 0}};
                                 */
    vector<vector<int>> matrix{{1, 0, 1, 1, 0, 0, 1, 0, 0, 1},
                               {0, 1, 1, 0, 1, 0, 1, 0, 1, 1},
                               {0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
                               {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
                               {0, 1, 0, 1, 1, 0, 0, 0, 0, 1},
                               {0, 0, 1, 0, 1, 1, 1, 0, 1, 0},
                               {0, 1, 0, 1, 0, 1, 0, 0, 1, 1},
                               {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
                               {1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
                               {1, 1, 1, 1, 0, 1, 0, 0, 1, 1}};

    auto distances = Solution::updateMatrixV2(matrix);

    for (
        const auto &row:
            distances) {
        for (
            const auto &cell:
                row) {
            cout << cell << " ";
        }
        cout <<
             endl;
    }

    return 0;
}