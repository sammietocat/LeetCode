#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) {
            return 0;
        }

        vector<int> profits(prices.size());
        vector<int> lastOutDay(prices.size());
        profits[0] = 0;
        lastOutDay[0] = -1;

        int profitTmp;
        int minIdxUpTillNow = 0;    // index for the minimum element up till now
        for (int i = 1; i < prices.size(); ++i) {
            // case: no out today, just copy from last day
            profits[i] = profits[i - 1];
            lastOutDay[i] = lastOutDay[i - 1];

            // case: last in is sold out today, where its input is not earlier than the j-th day (0-based index, j>0)
            int j = (0 == minIdxUpTillNow ? (1 + minIdxUpTillNow) : minIdxUpTillNow);
            while (j < i) {
                if (lastOutDay[j - 1] < j - 1) {
                    profitTmp = profits[j - 1] + (prices[i] - prices[j]);
                } else {
                    profitTmp = profits[j - 2] + (prices[i] - prices[j]);
                }

                if (profitTmp > profits[i]) {
                    profits[i] = profitTmp;
                }

                ++j;
            }

            // case: out in today, where its input is from the j-th day (0-based index, j=0)
            profitTmp = prices[i] - prices[0];
            if (profitTmp > profits[i]) {
                profits[i] = profitTmp;
            }

            // inequality means some stock is sold in the i-th day
            if (profits[i] > profits[i - 1]) {
                lastOutDay[i] = i;
            }

            // don't forget update index for the minimum element up till now
            if (prices[i] <= prices[minIdxUpTillNow]) {
                minIdxUpTillNow = i;
            }
        }

        for (const auto &i:lastOutDay) {
            cout << i << " ";
        }
        cout << endl;

        return profits.back();
    }
};

int main() {
    //std::cout << "Hello, World!" << std::endl;
    vector<int> prices = {1, 2, 3, 0, 2};

    cout << Solution::maxProfit(prices) << endl;

    return 0;
}