#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    using PairType = pair<char, int>;

    struct PairTypeCmp {
        bool operator()(const PairType &pr1, const PairType &pr2) {
            if (pr1.first == pr2.first) {
                return pr1.second > pr2.second;
            }

            return pr1.first > pr2.first;
        }
    };

    static string removeKdigits(string num, int k) {
        priority_queue<PairType, vector<PairType>, PairTypeCmp> pq;

        string smallest(num.size() - k, '0');

        for (int i{}; i < k; ++i) {
            pq.push(make_pair(num[i], i));
        }

        /*
        while (!pq.empty()) {
            cout << pq.top().first<<" at "<<pq.top().second<< endl;
            pq.pop();
        }
        */
        int prevEndIdx{-1};
        for (int i{k}, j{}; i < num.size(); ++i, ++j) {
            pq.push(make_pair(num[i], i));
            //showQ(pq);
            while (pq.top().second <= prevEndIdx) { pq.pop(); }

            smallest[j] = num[pq.top().second];
            prevEndIdx = pq.top().second;
            pq.pop();
        }

        // erase the leading 0
        int i{-1};
        while ('0' == smallest[++i]);

        return (smallest.size()==i ? "0": smallest.substr(i));
    }

    static void showQ(priority_queue<PairType, vector<PairType>, PairTypeCmp>  Q) {
        cout << "***"<<endl;
        while (!Q.empty()) {
            cout << Q.top().first<<" at "<<Q.top().second<< endl;
            Q.pop();
        }
    }
};

int main() {
    string num[] = {"10200", "1432219", "10"};
    const int k[] = {1, 3, 2};

    for (int i = 0; i < 3; ++i) {
        cout << Solution::removeKdigits(num[i], k[i]) << endl;
    }

    return 0;
}