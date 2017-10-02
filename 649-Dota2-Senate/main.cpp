#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    static string predictPartyVictory(string senate) {
        queue<size_t> radiantIdx, direIdx;
        size_t senateSize = senate.size();

        for (size_t i{}; i < senateSize; ++i) {
            'R' == senate[i] ? radiantIdx.push(i) : direIdx.push(i);
        }

        size_t i, j;
        while (!radiantIdx.empty() && !direIdx.empty()) {
            i = radiantIdx.front();
            j = direIdx.front();

            i < j ? radiantIdx.push(i + senateSize) : direIdx.push(j + senateSize);

            radiantIdx.pop();
            direIdx.pop();
        }

        return radiantIdx.empty() ? "Dire" : "Radiant";
    }
};

int main() {
    string senate[] = {
            "RD", "RDD", "DDRRR"
    };

    for (const auto &s:senate) {
        cout << Solution::predictPartyVictory(s) << endl;
    }

    return 0;
}