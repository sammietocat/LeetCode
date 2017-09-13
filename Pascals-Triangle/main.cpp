#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rows;
        if (numRows >= 1) {
            rows.push_back({1});
        }
        if (numRows >= 2) {
            rows.push_back({1, 1});
        }
        if (numRows >= 3) {
            for (int i = 2; i < numRows; ++i) {
                vector<int> row(i+1,1);

                const auto &prev = rows[i - 1];
                for (int j = 1; j < i; ++j) {
                    row[j] = prev[j] + prev[j - 1];
                }

                rows.push_back(row);
            }
        }

        return rows;
    }
};

int main() {
    for (int i = 1; i < 6; ++i) {
        cout << "***" << endl;

        for (const auto &row:Solution::generate(i)) {
            cout << "[";
            for (const auto &cell:row) {
                cout << cell << ",";
            }
            cout << "]" << endl;
        }
    }
    return 0;
}