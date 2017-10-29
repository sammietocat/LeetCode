#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> intersection;
        if (nums1.empty() || nums2.empty()) {
            return intersection;
        }

        if (nums1.size() > nums2.size()) {
            nums1.swap(nums2);
        }

        unordered_map<int, int> recorder;
        for (const auto &n : nums1) {
            ++recorder[n];
        }

        for (const auto &n : nums2) {
            auto itr = recorder.find(n);
            if ((std::end(recorder) != itr) && (itr->second > 0)) {
                intersection.emplace_back(n);
                itr->second -= 1;
            }
        }

        return intersection;
    }
};

int main() {
    vector<int> nums1{1, 2, 2, 1}, nums2{2};

    auto vec = Solution::intersect(nums1, nums2);
    cout << "[";
    for (const auto &n : vec) {
        cout << n << ", ";
    }
    cout << "]" << endl;

    return 0;
}