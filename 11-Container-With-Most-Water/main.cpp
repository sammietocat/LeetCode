#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int maxArea(vector<int> &height) {
        int areaMax = -1;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int h = std::min(height[i], height[j]);
            areaMax = std::max(areaMax, (j - i) * h);
            while ((i < j) && (height[i] <= h)) { ++i; }
            while ((i < j) && (height[j] <= h)) { --j; }
        }
        return areaMax;
    }
};

int main() {
    vector<int> height{1, 2, 3, 4};

    cout << Solution::maxArea(height) << endl;

    return 0;
}