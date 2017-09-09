#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int maxCount(int m, int n, vector<vector<int> > &ops) {
        int x = m, y = n;

        for (int i = 0; i < ops.size(); i++) {
            if (x > ops[i][0]) {
                x = ops[i][0];
            }
            if (y > ops[i][1]) {
                y = ops[i][1];
            }
        }

        return x * y;
    }
};

int main() {
    /*
    const int m = 3, n = 3;
    vector<vector<int>> ops = {
            {2, 2},
            {3, 3},
            {1, 2}
    };
     */
    const int m = 1, n = 2;
    vector<vector<int>> ops = {
            {1, 2},
            {1, 2},
    };


    cout << Solution::maxCount(m, n, ops) << endl;

    return 0;
}