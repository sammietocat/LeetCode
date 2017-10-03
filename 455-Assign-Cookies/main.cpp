#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    static int findContentChildren(vector<int> &g, vector<int> &s) {
        priority_queue<int, vector<int>, std::greater<int>> greedPQ{std::begin(g), std::end(g)}, cookiesPQ{
                std::begin(s), std::end(s)};

        int n{};
        while (!greedPQ.empty() && !cookiesPQ.empty()) {
            while (!cookiesPQ.empty() && (cookiesPQ.top() < greedPQ.top())) {
                cookiesPQ.pop();
            }

            if (!cookiesPQ.empty()) {
                cookiesPQ.pop();
                greedPQ.pop();
                ++n;
            }
        }

        return n;
    }
};

int main() {
    //vector<int> g{1, 2}, s{1, 2, 3};
    vector<int> g{1, 2, 3}, s{1, 1};

    cout << Solution::findContentChildren(g, s) << endl;

    return 0;
}