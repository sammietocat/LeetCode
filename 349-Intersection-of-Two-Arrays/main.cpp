#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        vector<int> intersec;
        if (nums1.empty() || nums2.empty()) {
            return intersec;
        }

        if (nums1.size() > nums2.size()) {
            nums1.swap(nums2);
        }

        set<int> seen{std::begin(nums1), std::end(nums1)};
        for (const auto &n : nums2) {
            if (std::end(seen) != seen.find(n)) {
                intersec.emplace_back(n);
                seen.erase(n);
            }
        }

        return intersec;
    }
};

int main() {
    vector<int> nums1{1, 2, 2, 1}, nums2{2, 2};

    auto vec = Solution::intersection(nums1, nums2);
    for (const auto &n : vec) {
        cout << n << endl;
    }

    return 0;
}