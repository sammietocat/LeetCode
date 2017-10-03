#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        bool isOk = false;
        size_t i{};
        while (i < gas.size()) {
            isOk = true;
            int gasLeft = gas[i];

            size_t j = i, k;
            do {
                k = j;
                j = (gas.size() == j + 1 ? 0 : (j + 1));

                if (gasLeft < cost[k]) {
                    isOk = false;
                    break;
                }
                gasLeft += gas[j] - cost[k];
            } while (j != i);

            if (isOk) { break; }
            ++i;
        }

        return isOk ? i : -1;
    }
};

int main() {
    //vector<int> gas{4}, cost{5};
    vector<int> gas{2, 4}, cost{3, 4};

    cout << Solution::canCompleteCircuit(gas, cost) << endl;

    return 0;
}