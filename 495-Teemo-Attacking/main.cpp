#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int findPoisonedDuration(vector<int> &timeSeries, int duration) {
        if(timeSeries.empty()) { return 0; }

        int total = 0;
        int start{timeSeries[0]}, end{start + duration};
        for (int i = 1; i < timeSeries.size(); ++i) {
            if (end < timeSeries[i]) {
                total += end - start;

                start = timeSeries[i];
                end = start + duration;
            } else {
                end = timeSeries[i] + duration;
            }
        }

        total += end - start;
        return total;
    }
};

int main() {
    /*
    vector<int> timeSeries{1, 4};
    const int duration = 2;
     */
    vector<int> timeSeries{1, 2};
    const int duration = 2;

    cout << Solution::findPoisonedDuration(timeSeries, duration) << endl;
    return 0;
}