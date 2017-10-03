#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
public:
    static int leastIntervalV2(vector<char> &tasks, int n) {
        // priority queue
        // the 1st element is the length of freeze zone of the task
        // the 2nd element is the frequency of the task
        vector<pair<int, int>> pq;
        // frequency counter
        int f[26] = {0};

        // count the frequency for each task
        for (const auto &t:tasks) { ++f[t - 'A']; }
        // make up the underlying vector for pq
        for (int i = 0; i < 26; ++i) {
            if (f[i]) {
                pq.push_back(std::make_pair(-1, f[i]));
                //pq.push_back(std::make_tuple(-1, f[i], (char) ('A' + i)));
            }
        }

        std::make_heap(std::begin(pq), std::end(pq));

        int ticks{};
        while (!pq.empty()) {
            ++ticks;
            for (auto &pr:pq) {
                if (pr.first < 0) {
                    pr.first += 1;
                }
            }

            if (pq[0].first < 0) { continue; }

            std::make_heap(std::begin(pq), std::end(pq));
            std::pop_heap(std::begin(pq), std::end(pq));

            // no more current task
            if (1 == pq.back().second) {
                pq.pop_back();
            } else {
                // decrement the frequency
                pq.back().second -= 1;
                // update the freeze zone
                pq.back().first = -n - 1;
            }
        }

        return ticks;
    }

    static int leastInterval(vector<char> &tasks, int n) {
        // priority queue
        // the 1st element is the length of freeze zone of the task
        // the 2nd element is the frequency of the task
        vector<tuple<int, int>> pq;
        // frequency counter
        int f[26] = {0};

        // count the frequency for each task
        for (const auto &t:tasks) { ++f[t - 'A']; }
        // make up the underlying vector for pq
        for (int i = 0; i < 26; ++i) {
            if (f[i]) {
                pq.push_back(std::make_tuple(-1, f[i]));
                //pq.push_back(std::make_tuple(-1, f[i], (char) ('A' + i)));
            }
        }

        std::make_heap(std::begin(pq), std::end(pq));

        int ticks{};
        while (!pq.empty()) {
            ++ticks;
            for (auto &v:pq) {
                if (std::get<0>(v) < 0) { std::get<0>(v) += 1; }
            }

            if (std::get<0>(pq[0]) < 0) { continue; }

            std::make_heap(std::begin(pq), std::end(pq));
            std::pop_heap(std::begin(pq), std::end(pq));

            // no more current task
            if (1 == std::get<1>(pq.back())) {
                pq.pop_back();
            } else {
                // decrement the frequency
                std::get<1>(pq.back()) -= 1;
                // update the freeze zone
                std::get<0>(pq.back()) = -n - 1;
            }
        }

        return ticks;
    }
};

int main() {
    ///*
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    const int n = 2;
    //*/

    /*
    vector<char> tasks{'A'};
    const int n = 2;
    */

    /*
    vector<char> tasks{'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    const int n = 2;
     */

    cout << Solution::leastIntervalV2(tasks, n) << endl;

    return 0;
}