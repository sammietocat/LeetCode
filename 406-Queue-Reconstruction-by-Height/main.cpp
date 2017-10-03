#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using PairType = pair<int, int>;

    static vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people) {
        sort(std::begin(people), std::end(people),
             [](const PairType &pr1, const PairType &pr2) {
                 if (pr1.first == pr2.first) {
                     return pr1.second <= pr2.second;
                 }

                 return pr1.first > pr2.first;
             });

        for (size_t i{1}; i < people.size(); ++i) {
            size_t j = i;
            while ((j > 0) && (j != people[j].second)) {
                std::swap(people[j], people[j - 1]);
                --j;
            }
        }

        return vector<PairType>{std::begin(people), std::end(people)};
    }
};

int main() {
    vector<pair<int, int>> people{{7, 0},
                                  {4, 4},
                                  {7, 1},
                                  {5, 0},
                                  {6, 1},
                                  {5, 2}};

    auto peopleQueue = Solution::reconstructQueue(people);
    for (const auto &p:peopleQueue) {
        cout << p.first << ", " << p.second << endl;
    }


    return 0;
}