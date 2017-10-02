#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct PairCmp {
    bool operator()(const pair<int, int> &pr1, const pair<int, int> &pr2) {
        return pr1.second > pr2.second;
    }
};

class Solution {
public:
    static vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> freq;

        // count the frequence
        for (const auto &n:nums) {
            ++freq[n];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, PairCmp> pq;
        for (const auto &pr:freq) {
            if (pq.size() < k) {
                pq.push(make_pair(pr.first, pr.second));
            } else {
                if (pr.second > pq.top().second) {
                    pq.pop();
                    //pq.push(pr);
                    pq.push(make_pair(pr.first, pr.second));
                }
            }
        }

        vector<int> topK(k,0);

        int i = k;
        while (!pq.empty()) {
            topK[--k] = pq.top().first;
            pq.pop();
        }

        return topK;
    }
};

int main() {
    const int k = 2;
    vector<int> nums = {1, 1, 1, 2, 2, 3};

    auto topK = Solution::topKFrequent(nums, k);
    for (const auto &v:topK) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}