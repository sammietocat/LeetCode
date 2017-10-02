#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    using triple = tuple<int, int, int>;

    static int kthSmallest(vector<vector<int>> &matrix, int k) {
        size_t n = matrix.size();

        priority_queue<triple, vector<triple>, std::greater<triple>> pq;

        for (int i = 0; i < n; ++i) {
            pq.push(make_tuple(matrix[i][0], i, 0));
        }

        int wanted;
        while (k--) {
            wanted = std::get<0>(pq.top());
            int y = std::get<1>(pq.top());
            int x = std::get<2>(pq.top());

            pq.pop();
            if (n - 1 == x) { continue; }

            pq.push(make_tuple(matrix[y][x + 1], y, x+1));
        }

        return wanted;
    }
};

int main() {
    using M = vector<vector<int>>;
    /*
    vector<vector<int>> matrix = {
            {1,  5,  9},
            {10, 11, 13},
            {12, 13, 15},
    };
    const int k = 8;
     */

    /*
    M matrix = {
            {-5},
    };
    const int k = 1;
     */

    /*
    M matrix = {
            {1,  3,  5,  7,  9},
            {2,  4,  6,  8,  10},
            {11, 13, 15, 17, 19},
            {12, 14, 16, 18, 20},
            {21, 22, 23, 24, 25},
    };
    const int k = 8;
     */

    M matrix = {{1,  6,  10, 13, 14, 16, 21},
                {3,  10, 12, 18, 22, 27, 29},
                {3,  15, 19, 20, 23, 29, 34},
                {8,  15, 19, 25, 27, 29, 39},
                {12, 17, 24, 25, 28, 29, 41},
                {16, 22, 27, 31, 31, 33, 44},
                {20, 26, 28, 35, 39, 41, 45}};
    const int k = 38;

    cout << Solution::kthSmallest(matrix, k) << endl;

    return 0;
}