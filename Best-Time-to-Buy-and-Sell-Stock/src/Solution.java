public class Solution {
    public static int maxProfit(int[] prices) {
        int profit = 0;
        int prevMinIdx = 0;

        int profitTmp;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] < prices[prevMinIdx]) {
                prevMinIdx = i;
                continue;
            }

            profitTmp = prices[i] - prices[prevMinIdx];
            if (profitTmp > profit) {
                profit = profitTmp;
            }
        }

        return profit;
    }

    public static void main(String[] args) {
        //int[] prices = new int[]{7, 1, 5, 3, 6, 4};
        //int[] prices = new int[]{7, 6, 4, 3, 1};
        int[] prices = new int[]{};

        System.out.println(maxProfit(prices));
    }
}
