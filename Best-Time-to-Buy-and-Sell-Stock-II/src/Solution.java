public class Solution {
    public static int maxProfit(int[] prices) {
        if (0 == prices.length) {
            return 0;
        }

        int[] profits = new int[prices.length];
        profits[0] = 0;

        int profitTmp;
        int minIdxUpTillNow = 0;    // index for the minimum element up till now
        for (int i = 1; i < prices.length; ++i) {
            // case: no out today, just copy from last day
            profits[i] = profits[i - 1];
            // case: last in is sold out today, where its input is not earlier than the j-th day (0-based index, j>0)
            int j = (0 == minIdxUpTillNow ? (1 + minIdxUpTillNow) : minIdxUpTillNow);
            while (j < i) {
                profitTmp = profits[j - 1] + (prices[i] - prices[j]);
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

            // don't forget update index for the minimum element up till now
            if (prices[i] <= prices[minIdxUpTillNow]) {
                minIdxUpTillNow = i;
            }
        }

        return profits[profits.length - 1];
    }

    public static void main(String[] args) {
        //int[] prices = new int[]{1, 2};
        //int[] prices = new int[]{1, 2, 4};
        int[] prices = new int[]{2, 1, 2, 1, 0, 1, 2};

        System.out.println(maxProfit(prices));
    }
}
