#include <iostream>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    static string frequencySort(string s) {
        map<char, int> freq;
        for (const char &c:s) {
            ++freq[c];
        }

        //priority_queue<pair<int, char>, vector<pair<int, char>>, std::greater<pair<int, char>>> pq;
        priority_queue<pair<int, char>> pq;
        for (const auto &pr:freq) {
            pq.emplace(pr.second, pr.first);
        }

        string ss;
        while (!pq.empty()) {
            ss.append(string(pq.top().first, pq.top().second));
            pq.pop();
        }

        return ss;
    }
};

int main() {
    string s[] = {"tree", "cccaaa", "Aabb"};

    for (const auto &str:s) {
        cout << Solution::frequencySort(str) << endl;
    }

    return 0;
}