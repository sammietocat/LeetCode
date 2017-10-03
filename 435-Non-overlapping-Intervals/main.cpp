#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//Definition for an interval.
struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval> &intervals) {
        if (intervals.empty()) { return 0; }

        size_t sz = intervals.size();

        sort(std::begin(intervals), std::end(intervals),
             [](const Interval &i1, const Interval &i2) {
                 if (i1.end == i2.end) { return i1.start < i2.start; }

                 return i1.end < i2.end;
             });

        int prevEnd{intervals[0].end}, nErase{};
        for (int i{1}; i < intervals.size(); ++i) {
            if (intervals[i].start >= prevEnd) {
                prevEnd = intervals[i].end;
            } else { ++nErase; }
        }

        return nErase;
    }
};

int main() {
    /*
    vector<Interval> intervals{
            Interval{1,2},
            Interval{2,3},
            Interval{3,4},
            Interval{1,3},
    };
     */
    /*
    vector<Interval> intervals{
            Interval{1,2},
            Interval{1,2},
            Interval{1,2},
    };
     */
    /*
    vector<Interval> intervals{
            Interval{1, 2},
            Interval{2, 3},
    };
     */
    /*
    vector<Interval> intervals{
            Interval{1, 2},
    };*/
    vector<Interval> intervals{
            {0, 2},
            {1, 3},
            {1, 3},
            {2, 4},
            {3, 5},
            {3, 5},
            {4, 6}
    };


    Solution solu;

    cout << solu.eraseOverlapIntervals(intervals) << endl;

    return 0;
}