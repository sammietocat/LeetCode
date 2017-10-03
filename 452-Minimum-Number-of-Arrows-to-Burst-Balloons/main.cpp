#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using PairType = pair<int, int>;

    static int findMinArrowShots(vector<pair<int, int>> &points) {
        if (points.empty()) { return 0; }

        sort(std::begin(points), std::end(points), [](const PairType &pr1, const PairType &pr2) {
            return pr1.second <= pr2.second;
        });

        int nShot{1}, xMax{points[0].second};
        for (const auto &pr:points) {
            if (pr.first > xMax) {
                ++nShot;
                xMax = pr.second;
            }

        }

        return nShot;
    }
};

int main() {
    vector<pair<int, int>> points{
            make_pair(10, 16),
            make_pair(2, 8),
            make_pair(1, 6),
            make_pair(7, 12),
    };

    cout << Solution::findMinArrowShots(points) << endl;

    return 0;
}