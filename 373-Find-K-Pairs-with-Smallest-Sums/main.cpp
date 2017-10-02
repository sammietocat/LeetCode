#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using Pair = pair<int, int>;

struct PairCmp {
    bool operator()(const Pair &pr1, const Pair &pr2) {
        return (pr1.first + pr1.second < pr2.first + pr2.second);
    }
};

class Solution {
public:
    static vector<pair<int, int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        if (!nums1.size() || !nums2.size()) {
            return vector<Pair>{};
        }

        priority_queue<Pair, vector<Pair>, PairCmp> pq;

        size_t i{0}, j;
        while (i < nums1.size()) {
            j = 0;
            while (j < nums2.size()) {
                pq.emplace(nums1[i], nums2[j]);

                if (pq.size() >= k) { break; }
                ++j;
            }

            if (pq.size() >= k) { break; }
            ++i;
        }

        if (i < nums1.size()) {
            while ((++j < nums2.size()) && (j < k)) {
                if (nums1[i] + nums2[j] < pq.top().first + pq.top().second) {
                    pq.pop();
                    pq.emplace(nums1[i], nums2[j]);
                }
            }
        }


        int topSum;
        bool changed;
        while (++i < nums1.size()) {
            topSum = pq.top().first + pq.top().second;
            j = 0;
            changed = false;
            while ((j < nums2.size()) && (j < k)) {
                if (nums1[i] + nums2[j] < topSum) {
                    pq.pop();
                    pq.emplace(nums1[i], nums2[j]);
                    topSum = pq.top().first + pq.top().second;
                    changed = true;
                }

                if (!changed) { break; }
                ++j;
            }

            if (!changed) { break; }
        }

        vector<Pair> pairs;
        pairs.reserve(pq.size());
        while (!pq.empty()) {
            pairs.emplace_back(pq.top().first, pq.top().second);
            pq.pop();
        }

        std::reverse(std::begin(pairs), std::end(pairs));

        return pairs;
    }
};

int main() {
    /*
    vector<int> nums1{1, 7, 11}, nums2{2, 4, 6};
    const int k = 3;
     */

    /*
    vector<int> nums1{1, 1, 2}, nums2{1, 2, 3};
    const int k = 2;
    */

    /*
    vector<int> nums1{1, 2}, nums2{3};
    const int k = 3;
     */

    /*
    vector<int> nums1{1, 2, 4, 5, 6}, nums2{3, 5, 7, 9};
    const int k = 3;
     */

    /*
    vector<int> nums1{1, 1, 2}, nums2{1, 2, 3};
    const int k = 10;
     */

    /*
    vector<int> nums1{1}, nums2{3, 5, 6, 7, 8, 100};
    const int k = 4;
     */

    /*
    vector<int> nums1{0, 0, 0, 0, 0}, nums2{-3, 22, 35, 56, 76};
    const int k = 22;
    */

    vector<int> nums1{0, 0, 0, 0, 0, 2, 2, 2, 2}, nums2{-3, 22, 35, 56, 76};
    const int k = 22;


    auto pvec = Solution::kSmallestPairs(nums1, nums2, k);
    for (const auto &pr:pvec) {
        cout << pr.first << ", " << pr.second << endl;
    }

    return 0;
}