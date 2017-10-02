#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int> &nums) {
        if (nums.size() < 3) { return false; }

        // check for continuity
        size_t lo = 0;
        for (size_t i{1}; i < nums.size(); ++i) {
            if (nums[i] - nums[i - 1] > 1) {
                if (!checkSubVecV2(nums, lo, i)) { return false; }

                lo = i;
            }
        }

        //return checkSubVec(nums, lo, nums.size());
        return checkSubVecV2(nums, lo, nums.size());
    }

private:
    bool checkSubVecV2(const vector<int> &vec, const size_t lo, const size_t hi) {
        if (hi - lo < 3) { return false; }

        // fPrev: frequency of previous number
        // fCurr: frequency of current number
        int fPrev = 0, fCurr = 1;
        // nS1: # of subsequence of length 1
        // nS2: # of subsequence of length 2
        int nS1Prev{0}, nS2Prev{0};
        for (size_t i{lo + 1}; i < hi; ++i) {
            if (vec[i] == vec[i - 1]) {
                ++fCurr;
            } else {
                if (fCurr < nS1Prev + nS2Prev) { return false; }

                nS2Prev = nS1Prev;
                nS1Prev = std::max(0, fCurr - fPrev);
                fPrev = fCurr;
                fCurr = 1;
            }
        }

        for (size_t i{lo + 1}; i < hi; ++i) {
            if ((i + 1 == hi) || (vec[i] != vec[i + 1])) {
                if (fCurr < nS1Prev + nS2Prev) { return false; }

                nS2Prev = nS1Prev;
                nS1Prev = std::max(0, fCurr - fPrev);
                fPrev = fCurr;
                fCurr = 1;
            } else { ++fCurr; }
        }

        return (0 == nS1Prev) && (0 == nS2Prev);
    }

    bool checkSubVec(const vector<int> &vec, const size_t lo, const size_t hi) {
        int L = vec[hi - 1] - vec[lo] + 2;

        // frequency counter
        vector<int> frequency(L, 0);

        for (size_t i{lo}; i < hi; ++i) {
            ++frequency[vec[i] - vec[lo] + 1];
        }

        // subsequence of length 1, 2
        vector<int> seq1(L, 0), seq2(L, 0);
        for (size_t i{1}; i < L; ++i) {
            // not enough numbers for use
            if (frequency[i] < seq1[i - 1] + seq2[i - 1]) { return false; }

            seq2[i] = seq1[i - 1];
            seq1[i] = std::max(0, frequency[i] - frequency[i - 1]);
        }

        return (0 == seq1[L - 1]) && (0 == seq2[L - 1]);
    }
};

int main() {
    //vector<int> nums{1, 2, 3, 3, 4, 5};
    //vector<int> nums{1, 2, 3, 3, 4, 4, 5, 5};
    vector<int> nums{1, 2, 3, 4, 4, 5};

    Solution solu;

    cout << std::boolalpha << solu.isPossible(nums) << endl;

    return 0;
}