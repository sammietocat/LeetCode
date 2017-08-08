/**
 * Created by loccs on 7/17/17.
 */
public class Solution {
    public static double findMaxAverage(int[] nums, int k) {
       double maxSubSum = 0;
       for(int i=0;i<k;i++) {
          maxSubSum+=nums[i];
       }

       double subSum;
        for (int i = k; i < nums.length; i++) {
            if (nums[i]>nums[i-k]) {
                subSum = 0;
                for (int j = i-k+1; j <= i; j++) {
                   subSum += nums[j];
                }
                if (subSum>maxSubSum) {
                    maxSubSum = subSum;
                }
            }
        }

        return maxSubSum/k;
    }
    public static void main(String[] args) {
        int[] nums = {1,12,-5,-6,50,3};
        final int K = 4;

        System.out.println(findMaxAverage(nums, K));
    }
}
